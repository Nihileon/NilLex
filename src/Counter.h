//
// Created by Nihileon on 2019/10/2.
//

#ifndef MY_PROJ_COUNTER_H
#define MY_PROJ_COUNTER_H

#include <map>
#include "Symbol.h"

class Counter {

private:
    static int lineCnt;
    static int wordCnt;
    static int punctuationCnt;
    static int lineBeginCharCnt;
    static std::map<int, int> symbolCntMap;
public:
    static int getLineCnt();

    static int getWordCnt();

    static int getPunctuationCnt();



    static void updateLineBeginCharCnt(int at) {
        lineBeginCharCnt = at;
    }
    // at 指向下一位
    static int getColumnCntAtCurrentLine(int at) {
        return at -1- lineBeginCharCnt;
    }

    static void incLineCntUpdateCharCnt(int at) {
        incLineCnt();
        updateLineBeginCharCnt(at);
    }

    static void incLineCnt() {
        lineCnt++;
    }

    static void incWordCnt() {
        wordCnt++;
    }

    static void incPunctuationCnt() {
        punctuationCnt++;
    }

    static void addLineCnt(int rowNum) {
        lineCnt += rowNum;
    }

    static bool addSymbolCntMap(std::string s, int num) {
        int symbolId = Symbol::getSymbolId(s);
        if (symbolId == -1) {
            return false;
        }
        const int a = 1;
        Counter::symbolCntMap.count(a);
        if (Counter::symbolCntMap.count(symbolId) == 0) {
            Counter::symbolCntMap.insert(std::make_pair(symbolId, num));
        } else {
            Counter::symbolCntMap[symbolId] += num;
        }
        return true;
    }

    static bool incSymbolCntMap(std::string s) {
        addSymbolCntMap(s, 1);
    }


    static int getSymbolCnt(std::string s) {
        int symbolId = Symbol::getSymbolId(s);
        if (symbolId == -1) {
            return 0;
        }
        return symbolCntMap[symbolId];
    }

    static void print() {
        std::cout << "there are " << lineCnt << " lines in the source code" << std::endl;
        for (auto iter = symbolCntMap.begin(); iter != symbolCntMap.end(); iter++) {
            std::cout << iter->first << " : " << iter->second << std::endl;
        }

    }

};

#endif //MY_PROJ_COUNTER_H
