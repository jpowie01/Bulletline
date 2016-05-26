/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Converter_hpp
#define Converter_hpp

#include <iostream>
#include <sstream>

using namespace std;

class Converter {
public:
    static string int2string(int value);
    static int string2int(string str);
};

#endif
