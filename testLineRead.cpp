#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file;
    file.open("./test.txt", ios::in);
    if (!file) {
        return -1;
    }

    while (file.good() && !file.eof()) {
        string temp_line;
        std::getline(file, temp_line);
        std::cout << temp_line << std::endl;
    }

    //将文件指针移动到文件开头
    file.clear(std::ios::goodbit);
    file.seekg(std::ios::beg);

    int lineNum = 0;
    while (file.good() && !file.eof()) {
        string temp_line;
        std::getline(file, temp_line);
        lineNum++;
        std::cout << temp_line << std::endl;
        std::cout << lineNum;
    }

    file.close();

    return 0;
}