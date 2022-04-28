#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "ISBN.h"
#include "Helper.h"

const size_t ISBN_SIZE = 13;
const size_t LINE_SEPARATOR_SIZE = 55;
const char LINE_SEPARATOR[LINE_SEPARATOR_SIZE] = "------------------------------------------------------";

class Book {
public:
	Book();
	Book(const char* author, const char* title, const char* fileName, const char* description, const double rating, const ISBN& isbn);
	Book(const Book& book);
	~Book();

	char* getAuthor() const;

	char* getTitle() const;

	char* getDescription() const;

	char* getFileName() const;

	double getRating() const;

	ISBN getISBN() const;

	Book& operator=(const Book& other);

	bool operator==(const Book& other) const;

	friend std::ifstream& operator>>(std::ifstream& in, Book& book);
	friend std::istream& operator>>(std::istream& in, Book& book);
	friend std::ostream& operator<<(std::ostream& out, const Book& book);

private:
	char* m_author;
	char* m_title;
	char* m_fileName;
	char* m_description;
	double m_rating;
	ISBN m_ISBN;

	void copy(const Book& other);
};

#endif // !BOOK_H
