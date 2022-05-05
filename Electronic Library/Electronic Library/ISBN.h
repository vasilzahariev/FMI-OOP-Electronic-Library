#ifndef ISBN_H
#define ISBN_H

#include <iostream>

#include "Helper.h"

/*
* Implements the basic functionalities of an ISBN (International Standard Book Number)
*/
class ISBN {
public:
	/*
	* The ISBN default constructor
	*/
	ISBN();
	/*
	* The Book parameterized constructor
	* @param ISBNstr - A string version of the ISBN
	*/
	ISBN(const char* ISBNstr);
	/*
	* The ISBN copy constructor.
	*/
	ISBN(const ISBN& other);

	/*
	* The '=' operator overloader. It copies the data from another object to this one
	* @return A reference to the transformed this object
	*/
	ISBN& operator=(const ISBN& other);

	/*
	* Checks if this ISBN is equal to another ISBN
	*/
	bool operator==(const ISBN& other) const;
	/*
	* Checks if this ISBN is smaller than another ISBN
	*/
	bool operator<(const ISBN& other) const;

	/*
	* Overloader for the '[]' operator.
	* @return A reference to the number corresponding to a certain index
	*/
	unsigned int& operator[](const int index);
	/*
	* Overloader for the '[]' operator
	* @return A reference to the constant number corresponding to a certain index
	*/
	const unsigned int& operator[](const int index) const;

	/*
	* Overloader for the operator '>>'. Reads input from the console and files
	*/
	friend std::istream& operator>>(std::istream& in, ISBN& isbn);
	/*
	* Overloader for the operator '<<'. Outputs ISBN's information to the console or a file
	*/
	friend std::ostream& operator<<(std::ostream& out, const ISBN& isbn);

private:
	/*
	* The amount of digits in the ISBN
	*/
	static const size_t SIZE = 13;
	/*
	* The numbers of the ISBN
	*/
	unsigned int m_data[SIZE] = { 0, };

	/*
	* Copies the data from information from another ISBN to this one
	*/
	void copy(const ISBN& other);
};

#endif // !ISBN_H
