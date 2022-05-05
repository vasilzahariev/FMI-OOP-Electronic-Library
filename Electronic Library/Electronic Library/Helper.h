#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cstring>
#include <cmath>
#include <ctype.h>

/**
* Implements a Helper class with useful functions that can be used by different classes
*/
class Helper {
public:
	/*
	* Compares two doubles using an epsilon
	* @return -1 if num1 is greater, 0 if they are equal, 1 if num2 is greater
	*/
	static int compareDoubles(const double num1, const double num2);

	/*
	* Sets a new value for a string
	*/
	static void setString(char*& str, const char* newStr);

	/*
	* Reads a string from the given stream and then sets it as a value for str
	*/
	static void readStrLineFromStream(std::istream& in, char*& str, char buffer[1025]);

	/*
	* Takes a string and replaces all the characters with their lower versions
	* @return The lowered version of the string
	*/
	static char* toLowerStr(char* str);

	/*
	* Takes a char and turns it into an integer
	*/
	static char charToInt(const char c);

	/*
	* Swaps the data between two objects
	*/
	template <typename T>
	static void swapData(T& obj1, T& obj2);
};

#endif // !HELPER_H

template<typename T>
inline void Helper::swapData(T& obj1, T& obj2) {
    const T temp = obj1;

    obj1 = obj2;
    obj1 = temp;
}
