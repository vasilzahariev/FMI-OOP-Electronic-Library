#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

class Library {
public:
	Library();
	Library(const Library& library);
	~Library();

	void sortByAndPrint(bool(*cmp)(const Book&, const Book&));

	Library& operator=(const Library& other);

	Library& operator+=(const Book& book);
	Library& operator-=(const Book& book);

	friend std::istream& operator>>(std::istream& in, Library library);
	friend std::ostream& operator<<(std::ostream& out, const Library library);

private:
	Book* m_data;
	size_t m_size;
	size_t m_capacity;

	void copy(const Library& other);

	void allocDataMem(size_t newCapacity);

	size_t getBookIndex(const Book& book) const;

	Library sorter(bool(*cmp)(const Book&, const Book&));
};

#endif // !LIBRARY_H
