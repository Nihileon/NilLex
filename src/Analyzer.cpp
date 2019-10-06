//
// Created by Nihileon on 2019/10/2.
//

#include "Analyzer.h"
#include "gtest/gtest.h"

TEST(a, b) {
    Analyzer a("./data-generator/test.txt");
//    a.printFile();
    a.start();
    Counter::print();
}

void Analyzer::start() {
    int i = 0;
    for (; i < file.size();) {
        char c = file.at(i);
        if (Utils::isSeparator(c)) {
            if (c == '\n') {
                Counter::incLineCnt();
            }
            i++;
            continue;
        }
        if (Utils::isValidWordBegin(c)) { // 单词
            bool isWord = false;
            std::string symbolName = Utils::matchWord(file, isWord, i);
            if (!isWord) {
                Utils::getValidWordToSeparator(file, i);
                std::cout << "it's not a word: line " << Counter::getLineCnt() << std::endl;
            }
            std::cout << "get a word : '" << symbolName << "' at line:" << Counter::getLineCnt() << std::endl;
            int symbol = Symbol::getSymbolId(symbolName);
            if (symbol == -1) {
                //todo deal with error
            } else {
                symbolCntMap[symbol]++;
            }
            continue;
        }
        if (Utils::isValidDigitBegin(file, i)) { // 数字
            // todo 对负数进行处理
            bool isInteger = false;
            int resultInt = Utils::SToI(file, isInteger, i);
            if (isInteger) { // 整数
                Counter::incSymbolCntMap(Symbol::INTEGER);
                std::cout << "get a inte : '" << resultInt << "' at line:" << Counter::getLineCnt() << std::endl;
            } else { // 浮点
                bool isDouble = false;
                double resultDouble = Utils::SToD(file, isDouble, i);
                if (isDouble) {
                    Counter::incSymbolCntMap(Symbol::DOUBLE);
                    std::cout << "get a doub : '" << resultDouble << "' at line:" << Counter::getLineCnt() << std::endl;
                } else {
                    // todo：两种数字都不是则说明炸了
                    std::cout << "'" << Utils::getValidWordToSeparator(file, i) << "'" << std::endl;
                    std::cout << "it is not a digit: line " << Counter::getLineCnt() << std::endl;
                }
            }
            continue;
        }
        if (Utils::isPunctuation(Utils::CToS(c))) { // 符号
            std::string punctuation = Utils::matchPunctuation(file, i);
            std::cout << "get a punc : '" << punctuation << "' at line:" << Counter::getLineCnt() << std::endl;
            if (c == '/') {
                Utils::stripComment(file, i);
            }
            Counter::incSymbolCntMap(punctuation);
            continue;
            //未知字符
        }
        std::cout << "unknown char: '" << c << "' ,line " << Counter::getLineCnt() << std::endl;
        i++;
    }
}
