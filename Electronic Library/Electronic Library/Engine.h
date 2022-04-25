#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "Library.h"

class Engine {
public:
	void run();

private:
	Library m_library;

	void printOperations();

	void sortBook();
	void addBook();
};

bool cmpTitle(const Book&, const Book&);
bool cmpAuthor(const Book&, const Book&);
bool cmpISBN(const Book&, const Book&);

#endif // !ENGINE_H
