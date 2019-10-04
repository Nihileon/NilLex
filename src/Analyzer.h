//
// Created by Nihileon on 2019/10/2.
//

#ifndef MY_PROJ_ANALYZER_H
#define MY_PROJ_ANALYZER_H

#include <utility>

#include "Counter.h"
#include "FileReader.h"
#include "Symbol.h"
#include "Utils.h"

class Analyzer {
    std::map<std::string, int> symbolMap;
    std::string file;
    std::map<int, int> symbolCntMap;

public:
    Analyzer(std::string filePath) {
        file = FileReader::readWholeFile(std::move(filePath));
    }

    void printFile() {
        std::cout << file;
    }

    // 输入一个词的时候，是否需要一个回调函数来告诉调用函数offset所处位置
    // matchWord matchPunctuation mathInteger 失败之后还得返回matchDouble

    void start() {
        int i = 0;
        for (; i < file.size(); i++) {
            char c = file.at(i);
            if (Utils::isSeparator(c)) {
                continue;
            }
            if (Utils::isValidWordBegin(c)) {
                Utils::matchWord(file, i);

            } else if (Utils::isDigit(c)) {
            } else if (Utils::isPunctuation(Utils::CToS(c))) {
            }
        }
    }
};

#endif //MY_PROJ_ANALYZER_H