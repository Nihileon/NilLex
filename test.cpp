#include <iostream>
#include <string>
#include "gtest/gtest.h"

using namespace std;
int main() {
    std::string s = "-124";
    int result = 0;
    int negativeSymbol = 1;
    if (s.at(0) == '-') {
        negativeSymbol = -1;
    } else {
        result = s.at(0) - '0';
    }
    for (int i = 1; i < s.size(); i++) {
        result = result * 10 + (s.at(i) - '0');
    }
    cout << negativeSymbol * result;
}