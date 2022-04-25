#pragma warning(disable: 4996)

#include "Book.h"

Book::Book() : m_author(nullptr), m_title(nullptr), m_description(nullptr), m_fileName(nullptr),
			   m_rating(0) {
}

Book::Book(const char* author, const char* title, const char* fileName, const char* description, const double rating, const int ISBN[ISBN_SIZE])
		: m_author(nullptr), m_title(nullptr), m_description(nullptr), m_fileName(nullptr),
		  m_rating(rating) {
	Helper::setString(m_author, author);
	Helper::setString(m_title, title);
	Helper::setString(m_description, description);
	Helper::setString(m_fileName, fileName);
	
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

bool Book::operator==(const Book& other) const {
	return (strcmp(m_author, other.m_author) == 0 &&
			strcmp(m_title, other.m_title) == 0 &&
			strcmp(m_description, other.m_description) == 0 &&
			strcmp(m_fileName, other.m_fileName) == 0 &&
			Helper::compareDoubles(m_rating, other.m_rating) == 0 &&
			Helper::checkIfArraysAreEqual(m_ISBN, ISBN_SIZE, other.m_ISBN, ISBN_SIZE));
}

void Book::copy(const Book& other) {
	Helper::setString(m_author, other.m_author);
	Helper::setString(m_title, other.m_title);
	Helper::setString(m_description, other.m_description);
	Helper::setString(m_fileName, other.m_fileName);

	m_rating = other.m_rating;

	for (size_t i = 0; i < ISBN_SIZE; i++)
		m_ISBN[i] = other.m_ISBN[i];
}

std::ifstream& operator>>(std::ifstream& in, Book& book) {
	char buffer[1025];

	in.ignore(LINE_SEPARATOR_SIZE);

	in.getline(buffer, 1025);
	Helper::setString(book.m_author, buffer);

	in.getline(buffer, 1025);
	Helper::setString(book.m_title, buffer);

	in.getline(buffer, 1025);
	Helper::setString(book.m_description, buffer);

	in.getline(buffer, 1025);
	Helper::setString(book.m_fileName, buffer);

	in >> book.m_rating;

	for (size_t i = 0; i < ISBN_SIZE; i++)
		in >> book.m_ISBN[i];

	in.ignore(LINE_SEPARATOR_SIZE);

	return in;
}

std::istream& operator>>(std::istream& in, Book& book) {
	char buffer[1025];

	std::cout << "Enter author's name: ";
	in.getline(buffer, 1025);
	Helper::setString(book.m_author, buffer);

	std::cout << "Enter book's title: ";
	in.getline(buffer, 1025);
	Helper::setString(book.m_title, buffer);

	std::cout << "Enter small description:" << std::endl;
	in.getline(buffer, 1025);
	Helper::setString(book.m_description, buffer);

	std::cout << "Enter the name of the file which contains the book: ";
	in.getline(buffer, 1025);
	Helper::setString(book.m_fileName, buffer);

	std::cout << "Enter book rating: ";
	in >> book.m_rating;

	std::cout << "Enter ISBN: ";
	for (size_t i = 0; i < ISBN_SIZE; i++)
		in >> book.m_ISBN[i];

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
