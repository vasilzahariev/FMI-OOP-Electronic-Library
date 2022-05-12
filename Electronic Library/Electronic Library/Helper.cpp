#pragma warning(disable: 4996)

#include "Helper.h"

bool Helper::compareDoubles(const double num1, const double num2) {
    const double EPS = 1.0 / (1 << 30);
    const double RES = std::abs(num1 - num2);
    
    return RES < EPS;
}

void Helper::setString(char*& str, const char* newStr) {
    delete[] str;
    
    if (newStr == nullptr) {
        str = nullptr;

        return;
    }
    else {
        str = new char[strlen(newStr) + 1];
        strcpy(str, newStr);
    }
}

void Helper::readStrLineFromStream(std::istream& in, char*& str, char buffer[1025]) {
    in.getline(buffer, 1025);
    Helper::setString(str, buffer);
}

char* Helper::toLowerStr(const char* str) {
    char* result = new char[strlen(str) + 1]{ '\0', };

    for (size_t i = 0; i < strlen(str); ++i)
        result[i] = tolower(str[i]);

    return result;
}

char Helper::charToInt(const char c) {
	return (int) c - 48;
}
