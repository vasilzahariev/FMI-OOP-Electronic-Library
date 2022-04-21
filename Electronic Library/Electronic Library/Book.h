#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>

const size_t ISBN_SIZE = 13;
const size_t LINE_SEPARATOR_SIZE = 55;
const char LINE_SEPARATOR[LINE_SEPARATOR_SIZE] = "------------------------------------------------------";

class Book {
public:
	Book();
	Book(const char* author, const char* title, const char* fileName, const char* description, const double rating, const int ISBN[ISBN_SIZE]);
	Book(const Book& book);
	~Book();

	char* getAuthor() const;

	char* getTitle() const;

	char* getDescription() const;

	double getRating() const;

	Book& operator=(const Book& other);

	friend std::istream& operator>>(std::istream& in, Book& book);
	friend std::ostream& operator<<(std::ostream& out, const Book& book);

private:
	char* m_author;
	char* m_title;
	char* m_fileName;
	char* m_description;
	double m_rating;
	int m_ISBN[13];

	void copy(const Book& other);
	void setString(char*& str, const char* newStr);
};

#endif // !BOOK_H
