#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Sign {
public:
    map<string, int> m = {
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
    int rowCnt = 0;
    int wordCnt = 0;
    int punctuationCnt = 0;

    Sign() {
    }

    void init() {
    }
};

//词法分析：关键字拼写错误，
int main() {

    ifstream file;
    file.open("./test.txt", ios::in);
    if (!file) {
        return -1;
    }
    //将文件指针移动到文件开头
    file.clear(std::ios::goodbit);
    file.seekg(std::ios::beg);
    int lineNum = 1;
    while (file.good() && !file.eof()) {
        string temp_line;
        std::getline(file, temp_line);
        lineNum++;
        std::cout << temp_line << std::endl;
        std::cout << lineNum;

    }

    file.close();
    Sign sign;
    cout << sign.m["while"];
    cout << -00000009.010000 ;
    return 0;
}