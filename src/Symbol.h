#pragma once

#include "gtest/gtest.h"
#include <map>
#include <string>

class Symbol {
private:
    static std::map<std::string, int> m;

public:
    static std::string INTEGER;
    static std::string DOUBLE;
    static std::string PARAMETER;

    // -1 表示没有此符号
    static int getSymbolId(std::string s) {
        if (Symbol::m.count(s) > 0) {
            return Symbol::m[s];
        }
        return Symbol::getSymbolId(PARAMETER);
    }

};