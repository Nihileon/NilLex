//
// Created by Nihileon on 2019/10/2.
//

#include "Counter.h"

int Counter::rowCnt = 0;
int Counter::wordCnt = 0;
int Counter::punctuationCnt = 0;

int Counter::getRowCnt() {
    return rowCnt;
}

int Counter::getWordCnt() {
    return wordCnt;
}

int Counter::getPunctuationCnt() {
    return punctuationCnt;
}
