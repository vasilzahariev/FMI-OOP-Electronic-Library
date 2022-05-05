#include "Library.h"

Library::Library() : m_data(nullptr), m_size(0), m_capacity(0) {
	allocDataMem(2);
}

Library::Library(const Library& library) : m_data(nullptr) {
	copy(library);
}

Library::~Library() {
	delete[] m_data;
}

void Library::sortByAndPrint(bool(*cmp)(const Book&, const Book&)) {
	std::cout << sorter(cmp);
}

Book* Library::findABook(bool(*checker)(const Book&, const char*), const char* search) {
	for (size_t i = 0; i < m_size; ++i) {
		if (checker(m_data[i], search)) {
			return &m_data[i];
		}
	}

	std::cout << "No book matched the search criteria!" << std::endl;

	return nullptr;
}

Library& Library::operator=(const Library& other) {
	if (this != &other) copy(other);

	return *this;
}

Book& Library::operator[](const char* title) {
	for (size_t i = 0; i < m_size; ++i)
		if (strcmp(m_data[i].getTitle(), title) == 0)
			return m_data[i];

	throw 1;
}

const Book& Library::operator[](const char* title) const {
	for (size_t i = 0; i < m_size; ++i)
		if (strcmp(m_data[i].getTitle(), title) == 0)
			return m_data[i];

	throw 1;
}

Library& Library::operator+=(const Book& book) {
	if (getBookIndex(book) != -1) throw 1;

	if (m_size == m_capacity) allocDataMem(m_capacity * 2);

	m_data[m_size++] = book;
	
	return *this;
}

Library& Library::operator-=(const Book& book) {
	size_t index = getBookIndex(book);

	if (index == -1) {
		std::cout << "Book isn't in the library!" << std::endl;

		return *this;
	}

	std::swap(m_data[index], m_data[--m_size]);

	return *this;
}

void Library::copy(const Library& other) {
	delete[] m_data;

	m_data = new Book[other.m_capacity];

	for (size_t i = 0; i < other.m_size; ++i)
		m_data[i] = other.m_data[i];

	m_size = other.m_size;
	m_capacity = other.m_capacity;
}

void Library::allocDataMem(size_t newCapacity) {
	if (newCapacity <= m_size) newCapacity = m_size + 1;

	Book* newBlock = new Book[newCapacity];

	for (size_t i = 0; i < m_size; ++i)
		newBlock[i] = m_data[i];

	delete[] m_data;
	m_data = newBlock;
	m_capacity = newCapacity;
}

size_t Library::getBookIndex(const Book& book) const {
	for (size_t i = 0; i < m_size; ++i)
		if (m_data[i] == book)
			return i;

	return -1;
}

Library Library::sorter(bool(*cmp)(const Book&, const Book&)) {
	Library lib = *this;

	for (size_t i = 0; i < lib.m_size; ++i)
		for (size_t j = i + 1; j < lib.m_size - i; ++j)
			if (cmp(lib.m_data[j], lib.m_data[j - 1]))
				Helper::swapData(lib.m_data[j], lib.m_data[j - 1]);

	return *this;
}

std::istream& operator>>(std::istream& in, Library library) {
	size_t newCapacity;
	
	in >> library.m_size >> newCapacity;

	library.allocDataMem(newCapacity);

	for (size_t i = 0; i < library.m_size; ++i)
		in >> library.m_data[0];

	return in;
}

std::ostream& operator<<(std::ostream& out, const Library library) {
	out << library.m_size << ' ' << library.m_capacity << '\n';

	for (size_t i = 0; i < library.m_size; ++i)
		out << library.m_data[i];

	return out;
}
