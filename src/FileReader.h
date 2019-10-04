//
// Created by Nihileon on 2019/10/2.
//

#ifndef MY_PROJ_FILEREADER_H
#define MY_PROJ_FILEREADER_H

#include <fstream>
#include <iostream>

#include <string>
#include <fstream>
#include <sstream>

class FileReader {
private:
    FileReader() {
    }

public:
    static void testReadFile();

    static std::string readWholeFile(std::string filePath);


};


#endif //MY_PROJ_FILEREADER_H
