//
// Created by Nihileon on 2019/10/2.
//

#ifndef MY_PROJ_UTILS_H
#define MY_PROJ_UTILS_H

#include "gtest/gtest.h"
#include <cmath>

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
               s == "." || s == "/" || s == ">" || s == "<" || s == "<=" || s == ">=" || s == "&&" || s == "||";
    }

    static int SToI(std::string s, bool &isInteger, int &at) {
        if (s.size() == 0) {
            isInteger = false;
            return 0;
        }
        int result = 0;
        int negativeSymbol = 1;
        int prefixZeroCnt = 0;
        if (s.at(0) == '-') {
            negativeSymbol = -1;
        } else if (isDigit(s.at(0))) {
            result = s.at(0) - '0';
            if (result == 0) {
                prefixZeroCnt++;
            }
        } else {
            isInteger = false;
            return 0;
        }
        int i = 1;
        for (; i < s.size() && s.at(i) - '0' == 0; i++) {
            if (prefixZeroCnt == 0) {
                prefixZeroCnt++;
            } else {
                isInteger = false;
                return 0;
            }
        }

        for (; i < s.size(); i++) {
            if (!isdigit(s.at(i)) || prefixZeroCnt > 0) {
                isInteger = false;
                return 0;
            }
            int c = s.at(i) - '0';
            result = result * 10 + (s.at(i) - '0');
        }
        isInteger = true;
        return negativeSymbol * result;
    }

    static int SToI(std::string s, bool &isInteger) {
        int i = 0;
        SToI(s, isInteger, i);
    }

    static double SToD(std::string s, bool &isDouble, int &at) {
        if (s.size() == 0) {
            isDouble = false;
            return 0;
        }
        double negativeSymbol = 1.0;
        double prefix = 0;
        if (s[at] == '-') {
            negativeSymbol = -1.0;
        } else {
            prefix = s[at] - '0';
        }
        int dotCnt = 0;
        int suffixCnt = 0;
        double suffix = 0.0;
        for (int i = 1; i < s.size(); i++) {
            char c = s.at(i);
            if (!isDigit(c) && !isDot(c)) {
                isDouble = false;
                return 0.0;
            }
            if (isDigit(c) && dotCnt == 0) {
                prefix = prefix * 10 + (c - '0');
            } else if (isDigit(c) && dotCnt == 1) {
                suffixCnt++;
                suffix += static_cast<double>(c - '0') / pow(10.0, suffixCnt);
            } else if (isDot(c) && 0 == dotCnt) {
                dotCnt++;
            } else {
                isDouble = false;
                return 0;
            }
        }
        isDouble = true;
        return (prefix + suffix) * negativeSymbol;
    }

    static double SToD(std::string s, bool &isDouble) {
        int i = 0;
        SToD(s, isDouble, i);
    }

    static auto CToS(char c) {
        return std::string(1, c);
    }

    static std::string matchWord(std::string s, int &at) {
        std::string result;
        for (; at < s.length(); at++) {
            if (!isValidWordCharacter(s.at(at))) {
                break;
            }
            result.append(CToS(s.at(at)));
        }
        return result;
    }

    static std::string matchWord(std::string s) {
        int i = 0;
        matchWord(s, i);
    }

    //at 最终指向一个未被检测的字符
    static bool stripComment(std::string s, int &at) {
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
                    at = curAt + 1;
                    return true;
                }
                //todo deal with case: //之后用反斜杠阻隔换行符号，此时行数需要加一
            } else if (curAt < s.size() && s[curAt] == '*') {
                curAt++;
                while (curAt < s.size() && s[curAt] != '*' && curAt + 1 < s.size() && s[curAt] != '/') {
                    curAt++;
                }
                if (curAt < s.size() && s[curAt] == '*' && curAt + 1 < s.size() && s[curAt] == '/') {
                    at = curAt + 2;
                    return true;
                }
            }
        }
        return false;
    }

};

#endif //MY_PROJ_UTILS_H
