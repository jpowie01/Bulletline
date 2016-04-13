/*
 * Counter Strike 2D
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
