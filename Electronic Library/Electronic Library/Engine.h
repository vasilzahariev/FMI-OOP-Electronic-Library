#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <fstream>
#include <string>

#include "Library.h"

class Engine {
public:
	static Engine& getInstance();

	void run();

private:
	Engine();
	Engine(const Engine& engine) = delete;

	Engine& operator=(const Engine& other) = delete;

private:
	Library m_library;
	const std::string FILE_NAME = "library.txt";
	const std::string PASSWORD = "vErYsEcUrEpAsS";

	void saveChanges();

	void printOperations();

	bool checkForAuthentication();

	void sortBook();
	void findBook();
	void addBook();
	void removeBook();
	void readBook();

	void bookReader(std::ifstream& file);

	void bookReaderRows(std::ifstream& file);
	void readBookRows(std::ifstream& file, const int rowsToRead);
	void readBookLine(std::ifstream& file);

	void bookReaderPunctuationMark(std::ifstream& file);
	void readBookUntilPunctMark(std::ifstream& file, const char punctMark);
	void readBookText(std::ifstream& file, const char punctMark);

	void searchInput(const char* inputText, char search[], const size_t SEARCH_SIZE, bool (*checker)(const Book&, const char*));
};

bool cmpTitle(const Book&, const Book&);
bool cmpAuthor(const Book&, const Book&);
bool cmpISBN(const Book&, const Book&);

bool checkerTitle(const Book&, const char*);
bool checkerAuthor(const Book&, const char*);
bool checkerISBN(const Book&, const char*);
bool checkerDescription(const Book&, const char*);

#endif // !ENGINE_H
