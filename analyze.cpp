#include <iostream>
#include "gtest/gtest.h"

using namespace std;

TEST(SuiteName, TestName) {
    cout << "this test" << endl;

    static_assert(1, "2");
}

class Analyzer {
public:
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    int SToI(string s, bool &isInteger) {
        if (s.size() == 0) {
            isInteger = false;
            return 0;
        }
        int result = 0;
        int negativeSymbol = 1;
        int zeroCnt = 0;
        if (s.at(0) == '-') {
            negativeSymbol = -1;
        } else {
            result = s.at(0) - '0';
            if (result == 0) {
                zeroCnt++;
            }
        }
        for (int i = 1; i < s.size(); i++) {
            int tempBit = s.at(i) - '0';
            //超过一个0就非十进制数
            zeroCnt = 0 == tempBit ? zeroCnt + 1 : zeroCnt;
            if (zeroCnt > 0) {
                isInteger = false;
                return 0;
            }
            result = result * 10 + (s.at(i) - '0');
        }
        isInteger = true;
        return negativeSymbol * result;
    }
};