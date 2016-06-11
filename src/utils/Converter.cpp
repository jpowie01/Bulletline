/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Converter.hpp"

string Converter::int2string(int value) {
    string out;
    stringstream ss;
    ss << value;
    ss >> out;
    return out;
}

int Converter::string2int(string str) {
    int out;
    stringstream ss;
    ss << str;
    ss >> out;
    return out;
}
