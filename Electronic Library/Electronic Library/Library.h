#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

/*
* Implements the basic functionalities of a Library
*/
class Library {
public:
	/*
	* The Library default constructor
	*/
	Library();
	/*
	* The Library copy constructor
	*/
	Library(const Library& library);
	/*
	* The Library destructor
	*/
	~Library();

	/*
	* Sorts a copy of the library and prints it
	* @param cmp - A pointer function that compares two Books in a specific way
	*/
	void sortByAndPrint(bool(*cmp)(const Book&, const Book&));

	/*
	* The '=' operator overloader. It copies the data from another object to this one
	* @return A reference to the transformed this object
	*/
	Library& operator=(const Library& other);

	/*
	* Overloader for the '[]' operator.
	* @throw an exception if there is no book in the library with the given title
	* @return A reference to the Book corresponding to a specific title
	*/
	Book& operator[](const char* title);
	/*
	* Overloader for the '[]' operator
	* @throw an exception if there is no book in the library with the given title
	* @return A reference to the constant Book corresponding to a specific title
	*/
	const Book& operator[](const char* title) const;

	/*
	* Overloader for the '+=' operator. It adds a Book to the Library
	* @throw an exception if the book already exists
	* @return A reference to the transformed this object
	*/
	Library& operator+=(const Book& book);
	/*
	* Overloader for the '-=' operator. It removes a Book from the Library
	* @return A reference to the transformed this object
	*/
	Library& operator-=(const Book& book);

	/*
	* Overloader for the operator '>>'. Reads input from the console and files
	*/
	friend std::istream& operator>>(std::istream& in, Library library);
	/*
	* Overloader for the operator '<<'. Outputs Library's information to the console or a file
	*/
	friend std::ostream& operator<<(std::ostream& out, const Library library);

private:
	/*
	* A dynamicly allocated array with the Books in the library
	*/
	Book* m_data;
	/*
	* The amount of Books in m_data
	*/
	size_t m_size;
	/*
	* The maximum amount of Books m_data can contain
	*/
	size_t m_capacity;

	/*
	* Copies the data from information from another Library to this one
	*/
	void copy(const Library& other);

	/*
	* Allocates a additional memory for m_data
	* @param newCapacity - the new capacity that will be set for m_data. If newCapacity is less than m_size, then it's set to m_size + 1
	*/
	void allocDataMem(size_t newCapacity);

	/*
	* Finds the index of a specific book
	* @return the index of the book and -1 if that book isn't in the Library
	*/
	size_t getBookIndex(const Book& book) const;

	/*
	* Sorts a copy of the Library
	* @param cmp - A pointer function that compares two Books in a specific way (used for the sorting)
	* @return the sorted copy of Library
	*/
	Library sorter(bool(*cmp)(const Book&, const Book&));
};

#endif // !LIBRARY_H
