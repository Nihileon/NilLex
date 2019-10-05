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
            if (!isdigit(s[curAt]) || prefixZeroCnt > 0) {
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
        int curAt = at;
        if (s.size() == 0) {
            isDouble = false;
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
        return SToD(s, isDouble, i);
    }

    static auto CToS(char c) {
        return std::string(1, c);
    }

    static std::string matchPunctuation(std::string s, int &at) {
        std::string result;
        int curAt = at;
        if (isPunctuation(CToS(s[curAt]))) {
            result.append(CToS(s[curAt]));
        }
        if (curAt + 1 < s.length() && isPunctuation(CToS(s[curAt + 1]))) {
            result.append(CToS(s[curAt + 1]));
            at = curAt + 2;
        } else {
            at = curAt + 1;
        }
        return result;

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
            } else if (curAt < s.size() && s[curAt] == '*') {
                //todo deal with case: //之后用反斜杠阻隔换行符号，此时行数需要加一
                curAt++;
                while ((curAt < s.size() && s[curAt] != '*') || (curAt + 1 < s.size() && s[curAt + 1] != '/')) {
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
};

#endif //MY_PROJ_UTILS_H