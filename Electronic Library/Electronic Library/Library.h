#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

class Library {
public:
	Library();
	Library(const Library& library);
	~Library();

	Library& operator=(const Library& other);

	friend std::istream& operator>>(std::istream& in, Library library);
	friend std::ostream& operator<<(std::ostream& out, const Library library);

private:
	Book* m_data;
	size_t m_size;
	size_t m_capacity;

	void copy(const Library& other);

	void allocDataMem(size_t newCapacity);
};

#endif // !LIBRARY_H
