#include "FileReader.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>

using namespace std;

TEST(SuiteNam3, TestName3) {
    std::cout << FileReader::readWholeFile("./data-generator/test.c");
}

void FileReader::testReadFile() {
    std::ifstream file;
    file.open("./data-generator/test.c", std::ios::in);
    if (!file) {
        throw "not a file";
    }

    while (file.good() && !file.eof()) {
        std::string temp_line;
        std::getline(file, temp_line);
        std::cout << temp_line << std::endl;
    }

    //将文件指针移动到文件开头
    file.clear(std::ios::goodbit);
    file.seekg(std::ios::beg);

    int lineNum = 0;
    while (file.good() && !file.eof()) {
        std::string temp_line;
        std::getline(file, temp_line);
        lineNum++;
        std::cout << temp_line << std::endl;
        std::cout << lineNum;
    }
    file.close();
}

std::string FileReader::readWholeFile(std::string filePath) {

    std::ifstream t(filePath);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string contents(buffer.str());
    return contents;
}
