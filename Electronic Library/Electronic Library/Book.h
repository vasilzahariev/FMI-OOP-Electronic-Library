#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "ISBN.h"
#include "Helper.h"

/*!
* Имплементация на основните функционалности на Book
*/
class Book {
public:
	/*!
	* Конструтора по подозиране на Book
	*/
	Book();
	/*!
	* Конструктор с параметри на Book
	*/
	Book(const char* author, const char* title, const char* fileName, const char* description, const double rating, const ISBN& isbn);
	/*!
	* Конструктор за копиране на Book
	*/
	Book(const Book& book);
	/*!
	* Деструктор на Book
	*/
	~Book();

	/*!
	* Селектор за m_author
	*/
	char* getAuthor() const;

	/*!
	* Селектор за m_title
	*/
	char* getTitle() const;

	/*!
	* Селектор за m_description
	*/
	char* getDescription() const;

	/*!
	* Селектор за m_fileName
	*/
	char* getFileName() const;

	/*!
	* Селектор за m_rating
	*/
	double getRating() const;

	/*!
	* Селектор за m_ISBN
	*/
	ISBN getISBN() const;

	/*!
	* Чете книга (Book) от подаден файлов поток
	*/
	void readFromFile(std::istream& file);

	/*!
	* Предефиниране на оператор "=". Копира данните от подаденият обект към този
	* @return Референция към трансформираният обект
	*/
	Book& operator=(const Book& other);

	/*!
	* Предефниране на оператор "==". Проверява дали тази книга е еднаква с подадената
	*/
	bool operator==(const Book& other) const;

	/*!
	* Предефиниране на оператор ">>". Използва се за четене на книга (Book) от конзолата
	*/
	friend std::istream& operator>>(std::istream& in, Book& book);
	/*!
	* Предефиниране на оператор "<<". Използва се за отпочатване на книга (Book) в конзола или файл
	*/
	friend std::ostream& operator<<(std::ostream& out, const Book& book);

private:
	/*!
	* Големината на разделител на линии
	*/
	static const size_t LINE_SEPARATOR_SIZE = 56;
	/*!
	* Разделител на линии
	*/
	const char LINE_SEPARATOR[Book::LINE_SEPARATOR_SIZE] = "------------------------------------------------------";

	/*!
	* Име на автора на книгата
	*/
	char* m_author;
	/*!
	* Заглавието на книгата
	*/
	char* m_title;
	/*!
	* Име на текстов файл, където е записан текста на книгите
	*/
	char* m_fileName;
	/*!
	* Кратко описание на книгата
	*/
	char* m_description;
	/*!
	* Рейтинг на книгата
	*/
	double m_rating;
	/*!
	* Международен стандартен номер на книгата
	*/
	ISBN m_ISBN;

	/*!
	* Копира данните от подадената книга (Book) в тази
	*/
	void copy(const Book& other);

	/*!
	* Задава подадените стойностти на всички низове в класа (m_author, m_title, m_fileName, m_description)
	*/
	void setBookStrs(const char* author, const char* title, const char* fileName, const char* description);
};

#endif // !BOOK_H
