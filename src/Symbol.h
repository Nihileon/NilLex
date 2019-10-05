#pragma once

#include "gtest/gtest.h"
#include <map>
#include <string>

class Symbol {
private:
    static std::map<std::string, int> m;
    static std::map<int, int> symbolCntMap;
    const std::string DIGIT = "digit";
    const std::string PARAMETER = "parameter";

public:
    // -1 表示没有此符号
    static int getSymbolId(std::string s) {
        if (Symbol::m.count(s) > 0) {
            return Symbol::m[s];
        }
        return -1;
    }

    static bool incSymbolCntMap(std::string s) {
        int symbolId = Symbol::getSymbolId(s);
        if (symbolId == -1) {
            return false;
        }
        const int a = 1;
        Symbol::symbolCntMap.count(a);
        if (Symbol::symbolCntMap.count(symbolId) == 0) {
            Symbol::symbolCntMap.insert(std::make_pair(symbolId, 1));
        } else {
            Symbol::symbolCntMap[symbolId]++;
        }
        return true;
    }

    static int getSymbolCnt(std::string s) {
        int symbolId = getSymbolId(s);
        if (symbolId == -1) {
            return 0;
        }
        return symbolCntMap[symbolId];
    }

};