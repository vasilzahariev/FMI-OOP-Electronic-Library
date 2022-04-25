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

template <typename T>
void Helper::swapData(T& obj1, T& obj2) {
    T temp = obj1;

    obj1 = obj2;
    obj1 = temp;
}

template <typename T>
bool Helper::checkIfArraysAreEqual(const T* arr1, const size_t size1, const T* arr2, const size_t size2) {
    if (size1 != size2) return false;

    for (size_t i = 0; i < size1; i++)
        if (arr1[i] != arr2[i])
            return false;

    return true;
}
