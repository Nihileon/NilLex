#include <iostream>
#include <cmath>
#include <map>
//#include "gtest/gtest.h"
#include "Utils.h"

TEST(SuiteName, TestName) {
    std::cout << std::endl;

    Utils a;
    bool isDouble = false;
    std::cout << a.SToD("-1231.133333", isDouble) << std::endl;
    std::cout << isDouble;

    bool isInteger = false;
    a.SToI("-0000.0000", isInteger);
    assert(!isInteger);

    a.SToI("-&^*^", isInteger);
    assert(!isInteger);

    a.SToI("*&(", isInteger);
    assert(!isInteger);

    std::cout << a.SToI("-123000", isInteger) << std::endl;
    assert(isInteger);

    a.SToI("-0123000", isInteger);
    assert(!isInteger);

    a.SToI("-00123000", isInteger);
    assert(!isInteger);

    int at = 0;
    std::string s = "//123456789\n1234567890";
    a.stripComment(s, at);

    std::cout << at << std::endl;
    std::cout << s[at];
}

