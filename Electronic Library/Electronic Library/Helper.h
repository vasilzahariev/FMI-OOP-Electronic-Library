#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cstring>
#include <cmath>
#include <ctype.h>

/*!
* Имплементация на Helper клас с полезни фукнции, които могат да бъдат използвани на повече от едно място
*/
class Helper {
public:
	/*!
	* Сравнява дали две числа от тип double са еднакви използвайки епсилон
	* @return Булеан, репрезентиращ дали са равни или не
	*/
	static bool compareDoubles(const double num1, const double num2);

	/*!
	* Задава стойността на newStr на str
	*/
	static void setString(char*& str, const char* newStr);

	/*!
	* Чете низ от даден поток и задава този низ като стойност за str
	*/
	static void readStrLineFromStream(std::istream& in, char*& str, char buffer[1025]);

	/*!
	* Приема низ и заменя всеки символ с неговата по-малка версия
	* @return По-малката версия на str
	*/
	static char* toLowerStr(const char* str);

	/*!
	* Превръща символ към integer
	*/
	static char charToInt(const char c);

	/*!
	* Сменя стойностите / данните на два обекта
	*/
	template <typename T>
	static void swapData(T& obj1, T& obj2);
};

template<typename T>
inline void Helper::swapData(T& obj1, T& obj2) {
	const T temp = obj1;

	obj1 = obj2;
	obj2 = temp;
}

#endif // !HELPER_H
