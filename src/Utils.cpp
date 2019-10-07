#include <iostream>
#include <cmath>
#include <map>
//#include "gtest/gtest.h"
#include "Utils.h"
#include "Counter.h"

TEST(lex, AnyToDigit) {
    std::cout << std::endl;

    Utils a;
    bool isDouble = false;
    std::cout << a.SToD("-1231.133333", isDouble) << std::endl;
    assert(isDouble);

    isDouble = false;
    std::cout << a.SToD("-0000.0000", isDouble);
    assert(isDouble);

    bool isInteger = false;
    a.SToI("-0000.0000", isInteger);
    assert(!isInteger);

    a.SToI("-&^*^", isInteger);
    assert(!isInteger);

    a.SToI("*&(", isInteger);
    assert(!isInteger);

    assert(a.SToI("-123000", isInteger) == -123000);
    assert(isInteger);

    a.SToI("-0123000", isInteger);
    assert(!isInteger);

    a.SToI("-00123000", isInteger);
    assert(!isInteger);

}

TEST(lex, matchWordWithAt) {
    Utils u;
    bool isInteger = false;
    int i = 1;
    u.SToI(" -0000.0000 ", isInteger, i);
    assert(!isInteger);
    assert(i == 1);

    i = 3;
    isInteger = false;
    int result = u.SToI("   0; ", isInteger, i);
    assert(isInteger);
    std::cout << result << std::endl;
    assert(result == 0);

    i = 3;
    isInteger = false;
    result = u.SToI("   255; ", isInteger, i);
    assert(isInteger);
    std::cout << result << std::endl;
    assert(result == 255);

    i = 3;
    isInteger = false;
    result = u.SToI("   1; ", isInteger, i);
    assert(isInteger);
    std::cout << result << std::endl;
    assert(result == 1);

    i = 3;
    isInteger = false;
    result = u.SToI("   -0; ", isInteger, i);
    assert(isInteger);
    std::cout << result << std::endl;
    assert(result == 0);

    i = 1;
    u.SToI("-01000", isInteger, i);
    assert(!isInteger);
    assert(i == 1);

    i = 2;
    result = u.SToI("-01000", isInteger, i);
    assert(result = 1000);
    assert(isInteger);
    assert(i == 6);

    i = 0;
    bool isDouble = false;
    double d = u.SToD("-0000.0000 ", isDouble, i);
    assert(d < 0.00000001 && d > -0.0000001);
    assert(isDouble);

    i = 0;
    isDouble = false;
    d = u.SToD("-1000.0000 ", isDouble, i);
    assert(d < -999.99999 && d > -1000.0000001);
    assert(isDouble);

    i = 2;
    isDouble = false;
    d = u.SToD("-1000.0001 ", isDouble, i);
    assert(d < 0.001 && d > 0);
    assert(isDouble);


}

TEST(lex, comment) {

    Utils a;
    int at = 0;
    std::string s = "//123456789\n1234567890";
    assert(a.stripComment(s, at));
    assert(at == 12);

    s = "/*23456789\n123456789/******/89";
    at = 0;

    assert(a.stripComment(s, at));
    std::cout << std::endl << at;
}


TEST(lex, matchWord) {
    Utils a;
    int at = 0;
    std::string s = "dhfkalsdk12837y_dashfk9";
    bool isWord = false;
    a.matchWord(s, isWord, at);
    assert(isWord);

    at = 0;
    s = "_1231230191";
    isWord = false;
    a.matchWord(s, isWord, at);
    assert(isWord);

    at = 0;
    s = "1231230191";
    isWord = false;
    a.matchWord(s, isWord, at);
    assert(!isWord);
    assert(at == 0);

    at = 0;
    s = "abc45678_ 123";
    isWord = false;
    a.matchWord(s, isWord, at);
    assert(isWord);
    assert(at == 9);
}

TEST(lex, punctuation) {
    int i = 0;
    Utils::matchPunctuation("(;", i);

}

bool Utils::stripComment(std::string s, int &at) {
    int curAt = at;
    if (curAt > s.size()) {
        return false;
    }
    if (s[curAt] == '/') {
        curAt++;
        if (curAt < s.size() && s[curAt] == '/') {
            curAt++;
            while (curAt < s.size() && s[curAt] != '\n') {
                curAt++;
            }
            if (curAt < s.size() && s[curAt] == '\n') {
                Counter::incLineCntUpdateCharCnt(curAt);
                at = curAt + 1;
                return true;
            }
        } else if (curAt < s.size() && s[curAt] == '*') {
            //todo deal with case: //之后用反斜杠阻隔换行符号，此时行数需要加一
            curAt++;
            while ((curAt < s.size() && s[curAt] != '*') || (curAt + 1 < s.size() && s[curAt + 1] != '/')) {
                if (s[curAt] == '\n') {
                    Counter::incLineCntUpdateCharCnt(curAt);
                }
                curAt++;
            }
            if (curAt < s.size() && s[curAt] == '*' && curAt + 1 < s.size() && s[curAt + 1] == '/') {
                at = curAt + 2;
                return true;
            }
        }
    }
    return false;
}

std::string Utils::getPositionStr(int at) {
    std::ostringstream s;
    s << ", at line: " << Counter::getLineCnt() << " , at col: " << Counter::getColumnCntAtCurrentLine(at);
    return s.str();
}


