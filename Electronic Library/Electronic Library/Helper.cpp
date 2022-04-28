#pragma warning(disable: 4996)

#include "Helper.h"

int Helper::compareDoubles(const double num1, const double num2) {
    const double EPS = 1.0 / (1 << 30);
    const double RES = std::abs(num1 - num2);
    
    return (RES == EPS ? 0 : (RES < EPS ? -1 : 1));
}

void Helper::setString(char*& str, const char* newStr) {
    delete[] str;

    str = new char[strlen(newStr) + 1];
    strcpy(str, newStr);
}

char* Helper::toLowerStr(char* str) {
    for (size_t i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);

    return str;
}
