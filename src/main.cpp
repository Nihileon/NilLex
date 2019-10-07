//
// Created by Nihileon on 2019/10/2.
//
#include <iostream>
#include "Analyzer.h"

int main() {
    Analyzer a("./data-generator/test.c");
    a.start();
    Counter::print();

}
