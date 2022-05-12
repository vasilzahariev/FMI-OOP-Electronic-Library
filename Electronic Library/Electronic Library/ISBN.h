#ifndef ISBN_H
#define ISBN_H

#include <iostream>

#include "Helper.h"

/*!
* Имплементация на основните функционалности на международен стандартен номер на книга
*/
class ISBN {
public:
	/*!
	* Конструктор по подразбиране на ISBN
	*/
	ISBN();
	/*!
	* Конструктор с параметри на ISBN
	* @param ISBNstr - Низ съдържащ ISBN-а
	*/
	ISBN(const char* ISBNstr);
	/*!
	* Конструктор за копиране на ISBN
	*/
	ISBN(const ISBN& other);

	/*!
	* Предефиниране на оператор "=". Копира данните от подаденият обект към сегащният
	* @return Референция към трансформираният обект
	*/
	ISBN& operator=(const ISBN& other);

	/*!
	* Предефиниране на оператор "==". Проверява дали този ISBN е същият като подаденият
	* @return Булева, показваща дали са еднакви
	*/
	bool operator==(const ISBN& other) const;
	/*!
	* Предефиниране на оператор "<". Проверява дали този ISBN е по-малък от подаденият като сравнява всяка от техните цифри
	* @return Булева, показваща дали този е по-малък
	*/
	bool operator<(const ISBN& other) const;

	/*!
	* Предефиниране на оператор "[]"
	* @throws "Index out of bounds" - Когато индкесът е под 0 или над максималния брой
	* @return Референция към числото намиращо се на подаденият индекс
	*/
	unsigned int& operator[](const int index);
	/*!
	* Предефиниране на оператор "[]"
	* @throws "Index out of bounds" - Когато индкесът е под 0 или над максималния брой
	* @return Референция към константна версия на числото намиращо се на подаденият индекс
	*/
	const unsigned int& operator[](const int index) const;

	/*!
	* Предефиниране на оператор ">>". Служи за четене от конзолата и файлове
	*/
	friend std::istream& operator>>(std::istream& in, ISBN& isbn);
	/*!
	* Предефиниране на оператор "<<". Служи за печатане на конзолата и файлове
	*/
	friend std::ostream& operator<<(std::ostream& out, const ISBN& isbn);

private:
	/*!
	* Броят числа в един ISBN
	*/
	static const size_t SIZE = 13;
	/*!
	* Числата в ISBN
	*/
	unsigned int m_data[SIZE] = { 0, };

	/*!
	* Копира данните от един ISBN към този
	*/
	void copy(const ISBN& other);
};

#endif // !ISBN_H
