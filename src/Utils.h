//
// Created by Nihileon on 2019/10/2.
//

#ifndef MY_PROJ_UTILS_H
#define MY_PROJ_UTILS_H

#include "gtest/gtest.h"
#include "Symbol.h"
#include <cmath>
#include <sstream>

//using namespace std;

class Utils {
public:
    static bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    static bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    static bool isValidWordBegin(char c) {
        return isLetter(c) || c == '_';
    }

    static bool isValidWordCharacter(char c) {
        return isValidWordBegin(c) || isDigit(c);
    }

    static bool isDot(char c) {
        return c == '.';
    }

    static bool isSeparator(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    }

    static bool isPunctuation(std::string s) {
        return s == "[" || s == "]" || s == "{" || s == "}" || s == "(" || s == ")" || s == ";" || s == "!" ||
               s == "%" || s == "^" || s == "&" || s == "|" || s == "~" || s == "*" || s == "?" || s == "," ||
               s == "-" || s == "+" || s == "=" || s == "==" || s == "+=" || s == "-=" || s == "++" || s == "--" ||
               s == "." || s == "/" || s == ">" || s == "<" || s == "<=" || s == ">=" || s == "&&" || s == "||" ||
               s == "#" || s == "\"" || s == "'" || s == "\\";
    }

    static bool isValidDigitBegin(std::string s, int at) {
        if (at > s.length()) {
            return false;
        }
        if (isdigit(s[at])) {
            return true;
        }
        if (at + 1 < s.length()) {
            if (s[at] == '-' && isDigit(s[at + 1])) {
                return true;
            }
        }
        return false;
    }

    static int SToI(std::string s, bool &isInteger, int &at) {
        int curAt = at;
        if (s.size() == 0) {
            isInteger = false;
            return 0;
        }
        int result = 0;
        int negativeSymbol = 1;
        int prefixZeroCnt = 0;
        int c = s[curAt];
        if (c == '-') {
            negativeSymbol = -1;
        } else if (isDigit(c)) {
            result = c - '0';
            if (result == 0) {
                prefixZeroCnt++;
            }
        } else {
            isInteger = false;
            return 0;
        }
        curAt++;
        //去0处理：如果开头是-1则需要检测其后是否有两个0，如果是1-9则可以跳过，如果是0开头则需要检测其后是否有两个0；
        if (negativeSymbol == -1 || prefixZeroCnt > 0) {
            for (; curAt < s.size() && s[curAt] - '0' == 0; curAt++) {
                if (prefixZeroCnt == 0) {
                    prefixZeroCnt++;
                } else {
                    isInteger = false;
                    return 0;
                }
            }
        }

        for (; curAt < s.size(); curAt++) {
            if (!isdigit(s[curAt])) {
                break;
            }
            if (prefixZeroCnt > 0) {
                isInteger = false;
                return 0;
            }
            result = result * 10 + (s[curAt] - '0');
        }
        isInteger = true;
        at = curAt;
        return negativeSymbol * result;
    }

    static int SToI(std::string s, bool &isInteger) {
        int i = 0;
        return SToI(s, isInteger, i);
    }

    static double SToD(std::string s, bool &isDouble, int &at) {
        isDouble = false;
        int curAt = at;
        if (s.size() == 0) {
            return 0;
        }
        double negativeSymbol = 1.0;
        double prefix = 0;
        if (s[curAt] == '-') {
            negativeSymbol = -1.0;
        } else {
            prefix = s[curAt] - '0';
        }
        curAt++;
        int dotCnt = 0;
        int suffixCnt = 0;
        double suffix = 0.0;
        for (; curAt < s.size(); curAt++) {
            char c = s[curAt];
            if (isDigit(c) && dotCnt == 0) {
                prefix = prefix * 10 + (c - '0');
            } else if (isDigit(c) && dotCnt == 1) {
                suffixCnt++;
                suffix += static_cast<double>(c - '0') / pow(10.0, suffixCnt);
            } else if (isDot(c) && 0 == dotCnt) {
                dotCnt++;
            } else {
                break;
            }
        }
        if (dotCnt == 1 && suffixCnt > 0) {
            at = curAt;
            isDouble = true;
        }
        return (prefix + suffix) * negativeSymbol;
    }

    static double SToD(std::string s, bool &isDouble) {
        int i = 0;
        return SToD(s, isDouble, i);
    }

    static auto CToS(char c) {
        return std::string(1, c);
    }


    static std::string getValidWordToSeparator(std::string s, int at) {
        std::string result;
        while (!isSeparator(s[at])) {
            result.append(CToS(s[at]));
            at++;
        }
        return result;
    }

    static std::string matchPunctuation(std::string s, int &at) {
        std::string monoPunc;
        int curAt = at;
        if (isPunctuation(CToS(s[curAt]))) {
            monoPunc.append(CToS(s[curAt]));
        }
        if (curAt + 1 < s.length() && isPunctuation(CToS(s[curAt + 1]))) {
            std::string diPunc = monoPunc;
            diPunc.append(CToS(s[curAt + 1]));
            if (Symbol::getSymbolId(diPunc) != Symbol::getSymbolId(Symbol::PARAMETER) &&
                Symbol::getSymbolId(diPunc) > 0) {
                at = curAt + 2;
                return diPunc;
            }
        }
        at = curAt + 1;
        return monoPunc;

    }


    static std::string matchWord(std::string s, bool &isWord, int &at) {
        int curAt = at;
        std::string result;
        if (!isValidWordBegin(s[curAt])) {
            isWord = false;
            return result;
        }
        for (; curAt < s.length(); curAt++) {
            if (!isValidWordCharacter(s[curAt])) {
                break;
            }
            result.append(CToS(s[curAt]));
        }

        isWord = true;
        at = curAt;
        return result;
    }

    static std::string matchWord(std::string s, int &i) {
        bool isWord = false;
        return matchWord(s, isWord, i);
    }

    //at 最终指向一个未被检测的字符
    static bool stripComment(std::string s, int &at);

    static bool stripString(std::string s, int &at) {
        int curAt = at;
        if (s[curAt] == '"') {
            curAt++;
            for (; curAt < s.length() && s[curAt] != '"'; curAt++);
        }
        if (curAt < s.length()) {
            at = curAt;
            return true;
        }
        return false;
    }

    static std::string getPositionStr(int at);
};

#endif //MY_PROJ_UTILS_H