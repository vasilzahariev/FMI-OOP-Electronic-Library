#pragma warning(disable: 4996)

#include "Book.h"

Book::Book() : m_author(nullptr), m_title(nullptr), m_description(nullptr), m_fileName(nullptr),
			   m_rating(0) {
}

Book::Book(const char* author, const char* title, const char* fileName, const char* description, const double rating, const int ISBN[ISBN_SIZE])
		: m_author(nullptr), m_title(nullptr), m_description(nullptr), m_fileName(nullptr),
		  m_rating(rating) {
	setString(m_author, author);
	setString(m_title, title);
	setString(m_description, description);
	setString(m_fileName, fileName);
	
	for (size_t i = 0; i < ISBN_SIZE; i++)
		m_ISBN[i] = ISBN[i];
}

Book::Book(const Book& book) : m_author(nullptr), m_title(nullptr), m_description(nullptr), m_fileName(nullptr) {
	copy(book);
}

Book::~Book() {
	delete[] m_author;
	delete[] m_title;
	delete[] m_fileName;
	delete[] m_description;
}

char* Book::getAuthor() const {
	return m_author;
}

char* Book::getTitle() const {
	return m_title;
}

char* Book::getDescription() const {
	return m_description;
}

double Book::getRating() const {
	return m_rating;
}

Book& Book::operator=(const Book& other) {
	if (this != &other) copy(other);

	return *this;
}

void Book::copy(const Book& other) {
	setString(m_author, other.m_author);
	setString(m_title, other.m_title);
	setString(m_description, other.m_description);
	setString(m_fileName, other.m_fileName);

	m_rating = other.m_rating;

	for (size_t i = 0; i < ISBN_SIZE; i++)
		m_ISBN[i] = other.m_ISBN[i];
}

void Book::setString(char*& str, const char* newStr) {
	delete[] str;

	str = new char[strlen(newStr) + 1];
	strcpy(str, newStr);
}

std::istream& operator>>(std::istream& in, Book& book) {
	char buffer[1025];

	in.ignore(LINE_SEPARATOR_SIZE);

	in.getline(buffer, 1025);
	book.setString(book.m_author, buffer);

	in.getline(buffer, 1025);
	book.setString(book.m_title, buffer);

	in.getline(buffer, 1025);
	book.setString(book.m_description, buffer);

	in.getline(buffer, 1025);
	book.setString(book.m_fileName, buffer);

	in >> book.m_rating;

	for (size_t i = 0; i < ISBN_SIZE; i++)
		in >> book.m_ISBN[i];

	in.ignore(LINE_SEPARATOR_SIZE);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
	out << LINE_SEPARATOR << std::endl;
	out << book.m_author << '\n' << book.m_title << '\n' << book.m_description << '\n' << book.m_fileName << '\n' << book.m_rating << '\n';
	
	for (size_t i = 0; i < ISBN_SIZE; i++)
		out << book.m_ISBN[i] << ' ';

	out << '\n' << LINE_SEPARATOR << std::endl;

	return out;
}
