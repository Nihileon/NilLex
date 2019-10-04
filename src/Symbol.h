#pragma once

#include <map>
#include <string>
#include "gtest/gtest.h"

class Symbol {
public:
    static std::map<std::string, int> m;

    // -1 表示没有此符号
    static int get(std::string s) {
        if (Symbol::m.count(s) > 0) {
            return Symbol::m[s];
        }
        return -1;
    }
};