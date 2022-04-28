#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <fstream>

#include "Library.h"

class Engine {
public:
	void run();

private:
	Library m_library;

	void printOperations();

	void sortBook();
	void addBook(); // TODO: Add security
	void removeBook(); // TODO: Add security
	void readBook();

	void bookReader(std::ifstream& file);

	void bookReaderRows(std::ifstream& file);
	void readBookRows(std::ifstream& file, const int rowsToRead);
	void readBookLine(std::ifstream& file);

	void bookReaderPunctuationMark(std::ifstream& file);
};

bool cmpTitle(const Book&, const Book&);
bool cmpAuthor(const Book&, const Book&);
bool cmpISBN(const Book&, const Book&);

#endif // !ENGINE_H
