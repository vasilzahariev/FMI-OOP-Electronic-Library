#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

/*!
* 
* Имплементация на основните функционалности на библиотеката (Library)
*/
class Library {
public:
	/*!
	* Конструтора по подозиране на Library
	*/
	Library();
	/*!
	* Конструктор за копиране на Library
	*/
	Library(const Library& library);
	/*!
	* Деструктор на Library
	*/
	~Library();

	/*!
	* Сортира копие на сегашната библиотека и го принтира на конзолата
	* @param cmp - Пойнтър функция, която сравнява 2 книги по специфичен начин
	*/
	void sortByAndPrint(bool(*cmp)(const Book&, const Book&, const bool), const bool isAscending);

	/*!
	* Намира книга като проверява дали изпълнява дадено условие
	* @param checker - Пойнтър функция, която проверява дали дадената книга е търсената
	*/
	Book* findABook(bool (*checker)(const Book&, const char*), const char* search);

	/*!
	* Предефиниране на оператор "=". Копира данните от подаденият обект към този
	* @return Референция към трансформираният обект
	*/
	Library& operator=(const Library& other);

	/*!
	* Предефиниране на оператор "[]"
	* @param title - Заглавие на търсената книга
	* @throw 1 - Когато не съществува книга с такова заглавие
	* @return Референция към книгата с подаденото заглавие
	*/
	Book& operator[](const char* title);
	/*!
	* Предефиниране на оператор "[]"
	* @param title - Заглавие на търсената книга
	* @throw 1 - Когато не съществува книга с такова заглавие
	* @return Референция към константна версия на книгата с подаденото заглавие
	*/
	const Book& operator[](const char* title) const;

	/*!
	* Предефиниране на оператор "+=". Добавя книга (Book) в тази библиотека (Library)
	* @throw 1 - Когато книгата вече същестува
	* @return Референция към трансформираният обект
	*/
	Library& operator+=(const Book& book);
	/*!
	* Предефиниране на оператор "-=". Премахва книга (Book) в тази библиотека (Library)
	* @return Референция към трансформираният обект
	*/
	Library& operator-=(const Book& book);

	/*!
	* Предефиниране на оператор ">>". Служи за четене от конзолата или файл
	*/
	friend std::istream& operator>>(std::istream& in, Library& library);
	/*!
	* Предефиниране на оператор "<<". Служи за печатане на конзолата и файлове
	*/
	friend std::ostream& operator<<(std::ostream& out, const Library& library);

private:
	/*!
	* Динамино заделен масив с книги (Book) в библиотеката (Library)
	*/
	Book* m_data;
	/*!
	* Броят на книгите (Book) в m_data
	*/
	size_t m_size;
	/*!
	* Максималният брой книги (Book), които може да бъдат записани в m_data
	*/
	size_t m_capacity;

	/*!
	* Копира данните от подадената библиотека (Library) в тази
	*/
	void copy(const Library& other);

	/*!
	* Заделя допълнително памен за m_data
	* @param newCapacity - новата максимален брой книги (Book) за m_data. Ако newCapacity е по-малко или равно на m_size, то става равно на m_size + 1
	*/
	void allocDataMem(size_t newCapacity);

	/*!
	* Намира индекса на определена книга в m_data
	* @return Индекстът на книгата, ако книгата я няма в библиотеката (Library) връща -1
	*/
	size_t getBookIndex(const Book& book) const;

	/*!
	* Сортира копие на библиотеката (Library) по определени критерии
	* @param cmp - Пойнтър функция, която сравнява 2 книги (Book) по специфичен начин
	* @return Сортирано копие на тази библиотека (Library)
	*/
	Library sorter(bool(*cmp)(const Book&, const Book&, const bool), const bool isAscending);
};

#endif // !LIBRARY_H
