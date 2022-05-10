#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "ISBN.h"
#include "Helper.h"

/*
* The size of the line separator
*/
const size_t LINE_SEPARATOR_SIZE = 56;
/*
* Sepator for the begining and end of the output
*/
const char LINE_SEPARATOR[LINE_SEPARATOR_SIZE] = "------------------------------------------------------";

/*
* Implements the basic functionalities of a Book
*/
class Book {
public:
	/*
	* The Book default constructor
	*/
	Book();
	/*
	* The Book parameterized constructor
	*/
	Book(const char* author, const char* title, const char* fileName, const char* description, const double rating, const ISBN& isbn);
	/*
	* The Book copy constructor
	*/
	Book(const Book& book);
	/*
	* The Book destructor
	*/
	~Book();

	/*
	* A getter for m_author
	*/
	char* getAuthor() const;

	/*
	* A getter for m_title
	*/
	char* getTitle() const;

	/*
	* A getter for m_description
	*/
	char* getDescription() const;

	/*
	* A getter for m_fileName
	*/
	char* getFileName() const;

	/*
	* A getter for m_rating
	*/
	double getRating() const;

	/*
	* A getter for m_ISBN
	*/
	ISBN getISBN() const;

	/*
	* Overloader for the operator '>>'. Reads input from files
	*/
	void readFromFile(std::istream& file);

	/*
	* The '=' operator overloader. It copies the data from another object to this one
	* @return A reference to the transformed this object
	*/
	Book& operator=(const Book& other);

	/*
	* Checks if this Book is equal to another Book
	*/
	bool operator==(const Book& other) const;

	/*
	* Overloader for the operator '>>'. Reads input from the console
	*/
	friend std::istream& operator>>(std::istream& in, Book& book);
	/*
	* Overloader for the operator '<<'. Outputs Book's information to the console or a file
	*/
	friend std::ostream& operator<<(std::ostream& out, const Book& book);

private:
	/*
	* The name of the Book's author
	*/
	char* m_author;
	/*
	* The Book's title (name)
	*/
	char* m_title;
	/*
	* The name of the file which contains the Book's contents
	*/
	char* m_fileName;
	/*
	* A small description of the Book
	*/
	char* m_description;
	/*
	* The Book's rating
	*/
	double m_rating;
	/*
	* The ISBN of the Book
	*/
	ISBN m_ISBN;

	/*
	* Copies the data from information from another Book to this one
	*/
	void copy(const Book& other);

	/*
	* Sets the values of the strings in the class (m_author, m_title, m_fileName, m_description)
	*/
	void setBookStrs(const char* author, const char* title, const char* fileName, const char* description);
};

#endif // !BOOK_H
