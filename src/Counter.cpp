//
// Created by Nihileon on 2019/10/2.
//

#include "Counter.h"

int Counter::lineCnt = 1;
int Counter::wordCnt = 0;
int Counter::punctuationCnt = 0;
std::map<int, int> Counter::symbolCntMap = {};


int Counter::getLineCnt() {
    return lineCnt;
}

int Counter::getWordCnt() {
    return wordCnt;
}

int Counter::getPunctuationCnt() {
    return punctuationCnt;
}

TEST(lex, incSymbol) {
    Counter::incSymbolCntMap("|");
    Counter::incSymbolCntMap("|");
    Counter::incSymbolCntMap("|");
    Counter::incSymbolCntMap("|");
    std::cout << std::endl << Counter::getSymbolCnt("|");
}
