#include "Symbol.h"
#include "Counter.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

// normal parameter 的值是0
std::map<std::string, int> Symbol::m = {
    {"auto", 1},
    {"break", 2},
    {"case", 3},
    {"char", 4},
    {"const", 5},
    {"continue", 6},
    {"default", 7},
    {"do", 8},
    {"double", 9},
    {"else", 10},
    {"enum", 11},
    {"extern", 12},
    {"float", 13},
    {"for", 14},
    {"goto", 15},
    {"if", 16},
    {"int", 17},
    {"long", 18},
    {"register", 19},
    {"return", 20},
    {"short", 21},
    {"signed", 22},
    {"sizeof", 23},
    {"static", 24},
    {"struct", 25},
    {"switch", 26},
    {"typedef", 27},
    {"union", 28},
    {"unsigned", 29},
    {"void", 30},
    {"volatile", 31},
    {"while", 32},
    {"main", 33},
    {"[", 34},
    {"]", 35},
    {"{", 36},
    {"}", 37},
    {"(", 38},
    {")", 39},
    {";", 40},
    {"!", 41},
    {"%", 42},
    {"^", 43},
    {"&", 44},
    {"|", 45},
    {"~", 46},
    {"<<", 47},
    {">>", 48},
    {"*", 49},
    {"?", 50},
    {",", 51},
    {"-", 52},
    {"+", 53},
    {"=", 54},
    {"==", 55},
    {"+=", 56},
    {"-=", 57},
    {"++", 58},
    {"--", 59},
    {".", 60},
    {"/", 61},
    {">", 62},
    {"<", 63},
    {"<=", 64},
    {">=", 65},
    {"&&", 66},
    {"||", 67}};

TEST(SuiteName2, TestName2) {
    std::cout << std::endl;

    auto s = Utils::CToS('|');
    if (Symbol::m.count(s) > 0) {
        std::cout << Symbol::m[s] << std::endl;
    }

    Counter::IncRowCnt();
    std::cout << Counter::getRowCnt();
}
