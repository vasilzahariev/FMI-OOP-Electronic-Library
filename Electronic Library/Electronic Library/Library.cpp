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

Library& Library::operator=(const Library& other) {
	if (this != &other) copy(other);

	return *this;
}

void Library::copy(const Library& other) {
	delete[] m_data;

	m_data = new Book[other.m_capacity];

	for (size_t i = 0; i < other.m_size; i++)
		m_data[i] = other.m_data[i];

	m_size = other.m_size;
	m_capacity = other.m_capacity;
}

void Library::allocDataMem(size_t newCapacity) {
	if (newCapacity <= m_size) newCapacity = m_size + 1;

	Book* newBlock = new Book[newCapacity];

	for (size_t i = 0; i < m_size; i++)
		newBlock[i] = m_data[i];

	delete[] m_data;
	m_data = newBlock;
	m_capacity = newCapacity;
}

std::istream& operator>>(std::istream& in, Library library) {
	size_t newCapacity;
	
	in >> library.m_size >> newCapacity;

	library.allocDataMem(newCapacity);

	for (size_t i = 0; i < library.m_size; i++)
		in >> library.m_data[0];

	return in;
}

std::ostream& operator<<(std::ostream& out, const Library library) {
	out << library.m_size << ' ' << library.m_capacity << '\n';

	for (size_t i = 0; i < library.m_size; i++)
		out << library.m_data[i];

	return out;
}
