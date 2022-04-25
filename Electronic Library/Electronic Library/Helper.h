#ifndef HELPER_H
#define HELPER_H

#include <cstring>
#include <cmath>
#include <ctype.h>

class Helper {
public:
	/*
	A method that compares two doubles and returns an int representing which one is bigger.
	-1 - num1
	0 - equal
	1 - num2
	*/
	static int compareDoubles(const double num1, const double num2);

	static void setString(char*& str, const char* newStr);

	static char* toLowerStr(char* str);

	template <typename T>
	static void swapData(T& obj1, T& obj2);

	template <typename T>
	static bool checkIfArraysAreEqual(const T* arr1, const size_t size1, const T* arr2, const size_t size2);
};

#endif // !HELPER_H
