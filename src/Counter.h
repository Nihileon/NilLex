//
// Created by Nihileon on 2019/10/2.
//

#ifndef MY_PROJ_COUNTER_H
#define MY_PROJ_COUNTER_H


class Counter {


public:
    static int rowCnt;
    static int wordCnt;
    static int punctuationCnt;

    static int getRowCnt();

    static int getWordCnt();

    static int getPunctuationCnt();

    static void init(){

   }

    static void IncRowCnt() {
        rowCnt++;
    }

    static void IncWordCnt() {
        wordCnt++;
    }

    static void IncPunctuationCnt() {
        punctuationCnt++;
    }

    static void addRowCnt(int rowNum) {
        rowCnt += rowNum;
    }

};
#endif //MY_PROJ_COUNTER_H
