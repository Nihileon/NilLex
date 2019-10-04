//
// Created by Nihileon on 2019/10/2.
//

#include "Counter.h"

auto Counter::rowCnt = 0;
auto Counter::wordCnt = 0;
auto Counter::punctuationCnt = 0;

int Counter::getRowCnt() {
    return rowCnt;
}

int Counter::getWordCnt() {
    return wordCnt;
}

int Counter::getPunctuationCnt() {
    return punctuationCnt;
}
