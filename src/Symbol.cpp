#include "Symbol.h"
#include "Counter.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

// normal parameter 的值是0
std::map<std::string, int> Symbol::m = {
        {"parameter",1},
        {"integer",2},
        {"double",3},
        {"auto",4},
        {"break",5},
        {"case",6},
        {"char",7},
        {"const",8},
        {"continue",9},
        {"default",10},
        {"do",11},
        {"double",12},
        {"else",13},
        {"enum",14},
        {"extern",15},
        {"float",16},
        {"for",17},
        {"goto",18},
        {"if",19},
        {"int",20},
        {"long",21},
        {"register",22},
        {"return",23},
        {"short",24},
        {"signed",25},
        {"sizeof",26},
        {"static",27},
        {"struct",28},
        {"switch",29},
        {"typedef",30},
        {"union",31},
        {"unsigned",32},
        {"void",33},
        {"volatile",34},
        {"while",35},
        {"main",36},
        {"[",37},
        {"]",38},
        {"{",39},
        {"}",40},
        {"(",41},
        {")",42},
        {";",43},
        {"!",44},
        {"%",45},
        {"^",46},
        {"&",47},
        {"|",48},
        {"~",49},
        {"*",50},
        {"?",51},
        {",",52},
        {"-",53},
        {"+",54},
        {"=",55},
        {"==",56},
        {"+=",57},
        {"-=",58},
        {"++",59},
        {"--",60},
        {".",61},
        {"/",62},
        {">",63},
        {"<",64},
        {"<=",65},
        {">=",66},
        {"&&",67},
        {"||",68},
        {"#",69},
        {"\"",70},
        {"'",71},
        {"\\",72},
};
std::string Symbol::INTEGER = "integer";
std::string Symbol::DOUBLE = "double";
std::string Symbol::PARAMETER = "parameter";

TEST(lex, getSymbolName) {
    std::cout << std::endl;

    std::cout << Symbol::getSymbolId("|") << std::endl;

    Counter::incLineCnt();
    std::cout << Counter::getLineCnt();

}

