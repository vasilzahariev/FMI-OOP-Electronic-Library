#include "Engine.h"

void Engine::run() {
	int operation;
	
	do {
		printOperations();
		
		std::cout << "Enter: ";

		std::cin >> operation;
		
		if (operation == 1)
			sortBook();
		else if (operation == 2)
			findBook();
		else if (operation == 3)
			addBook();
		else if (operation == 4)
			removeBook();
		else if (operation == 5)
			readBook();
		else if (operation == 6)
			std::cout << "Bye!" << std::endl;
		else
			std::cout << "Invalid operation" << std::endl;

	} while (operation != 6);
}

void Engine::printOperations() {
	std::cout << "-----------------------" << std::endl;
	std::cout << "Select an operation:" << std::endl;
	std::cout << "1) Sort the library" << std::endl;
	std::cout << "2) Search for a book" << std::endl;
	std::cout << "3) Add a book" << std::endl;
	std::cout << "4) Remove a book" << std::endl;
	std::cout << "5) Read a book" << std::endl;
	std::cout << "6) Exit" << std::endl;
	std::cout << "-----------------------" << std::endl;
}

bool Engine::checkForAuthentication() {
	const size_t PASSWORD_SIZE = 50;
	char password[PASSWORD_SIZE];

	std::cout << "This action requires authentication" << std::endl;
	std::cout << "Please enter the password: " << std::endl;

	std::cin.getline(password, PASSWORD_SIZE);

	return strcmp(password, PASSWORD.c_str());
}

void Engine::sortBook() {
	const size_t SORTING_TYPE_SIZE = 50;
	char sortingType[SORTING_TYPE_SIZE];
	
	std::cout << "Enter a sorting type (title, author, ISBN): " << std::endl;
	std::cin.get(sortingType, SORTING_TYPE_SIZE);

	if (strcmp(Helper::toLowerStr(sortingType), "title") == 0)
		m_library.sortByAndPrint(&cmpTitle);
	else if (strcmp(Helper::toLowerStr(sortingType), "author") == 0)
		m_library.sortByAndPrint(&cmpAuthor);
	else if (strcmp(Helper::toLowerStr(sortingType), "isbn") == 0)
		m_library.sortByAndPrint(&cmpISBN);
	else
		std::cout << "Invalid sorting type!" << std::endl;
}

void Engine::findBook() {
	const size_t CRITERIA_SIZE = 50;
	const size_t SEARCH_SIZE = 100;

	char criteria[CRITERIA_SIZE];

	std::cout << "Enter a search criteria(title | author | ISBN | description): ";
	std::cin.get(criteria, CRITERIA_SIZE);

	char search[SEARCH_SIZE];

	if (strcmp(Helper::toLowerStr(criteria), "title"))
		searchInput("Enter the title: ", search, SEARCH_SIZE, &checkerTitle);
	else if (strcmp(Helper::toLowerStr(criteria), "author"))
		searchInput("Enter the author: ", search, SEARCH_SIZE, &checkerAuthor);
	else if (strcmp(Helper::toLowerStr(criteria), "ISBN"))
		searchInput("Enter the ISBN(don't separate the numbers with spaces): ", search, SEARCH_SIZE, &checkerISBN);
	else if (strcmp(Helper::toLowerStr(criteria), "description"))
		searchInput("Enter the description: ", search, SEARCH_SIZE, &checkerDescription);
}

void Engine::addBook() {
	if (!checkForAuthentication()) {
		std::cout << "Invalid Authentication!" << std::endl;

		return;
	}

	Book book;

	std::cin >> book;

	try {
		m_library += book;
	}
	catch (int err) {
		std::cout << "Book already in the library!" << std::endl;
	}
}

void Engine::removeBook() {
	if (!checkForAuthentication()) {
		std::cout << "Invalid Authentication!" << std::endl;

		return;
	}

	const size_t TITLE_SIZE = 100;
	char title[TITLE_SIZE];

	std::cout << "Enter book title:" << std::endl;

	std::cin.getline(title, TITLE_SIZE);

	try {
		m_library -= m_library[title];
	}
	catch (int err) {
		std::cout << "Book does not exist!" << std::endl;
	}
}

void Engine::readBook() {
	const size_t TITLE_SIZE = 100;
	char title[TITLE_SIZE];

	std::cout << "Enter book titile:" << std::endl;
	std::cin.getline(title, TITLE_SIZE);

	try {
		std::ifstream file(m_library[title].getFileName());

		bookReader(file);

		file.close();
	}
	catch (int err) {
		std::cout << "Book does not exist!" << std::endl;
	}
}

void Engine::bookReader(std::ifstream& file) {
	const size_t READING_TYPE_SIZE = 50;
	char readingType[READING_TYPE_SIZE];

	std::cout << "Choose your reading type (rows | punctuation mark):" << std::endl;
	std::cin.getline(readingType, READING_TYPE_SIZE);

	if (strcmp(Helper::toLowerStr(readingType), "rows") == 0)
		bookReaderRows(file);
	else if (strcmp(Helper::toLowerStr(readingType), "punctuation mark") == 0)
		bookReaderPunctuationMark(file);
	else
		std::cout << "Invalid reading type!" << std::endl;
}

void Engine::bookReaderRows(std::ifstream& file) {
	int rowsToRead;

	std::cout << "Enter the amount of rows you would like to read: ";
	std::cin >> rowsToRead;

	readBookRows(file, rowsToRead);
}

void Engine::readBookRows(std::ifstream& file, const int rowsToRead) {
	while (!file.eof()) {
		for (unsigned i = 0; i < rowsToRead; ++i) {
			if (file.eof()) break;

			readBookLine(file);
		}

		system("pause");
	}
}

void Engine::readBookLine(std::ifstream& file) {
	const size_t LINE_SIZE = 1025;
	char line[LINE_SIZE];

	file.getline(line, LINE_SIZE);

	std::cout << line;
}

void Engine::bookReaderPunctuationMark(std::ifstream& file) {
	char punctMark;

	std::cout << "Enter the punctuation mark you would like to stop reading at: ";
	std::cin >> punctMark;

	readBookUntilPunctMark(file, punctMark);
}

void Engine::readBookUntilPunctMark(std::ifstream& file, const char punctMark) {
	while (!file.eof()) {
		readBookText(file, punctMark);

		system("pause");
	}
}

void Engine::readBookText(std::ifstream& file, const char punctMark) {
	const size_t TEXT_SIZE = 1025;
	char text[TEXT_SIZE];

	file.getline(text, TEXT_SIZE, punctMark);

	std::cout << text;
}

void Engine::searchInput(const char* inputText, char search[], const size_t SEARCH_SIZE, bool(*checker)(const Book&, const char*)) {
	std::cout << inputText;
	std::cin.get(search, SEARCH_SIZE);

	std::cout << *m_library.findABook(checker, search);
}

bool cmpTitle(const Book& b1, const Book& b2) {
	return strcmp(b1.getTitle(), b2.getTitle()) < 0;
}

bool cmpAuthor(const Book& b1, const Book& b2) {
	return strcmp(b1.getAuthor(), b2.getAuthor()) < 0;
}

bool cmpISBN(const Book& b1, const Book& b2) {
	return b1.getISBN() < b2.getISBN();
}

bool checkerTitle(const Book& book, const char* title) {
	return strcmp(Helper::toLowerStr(book.getTitle()), Helper::toLowerStr((char*) title));
}

bool checkerAuthor(const Book& book, const char* author) {
	return strcmp(Helper::toLowerStr(book.getAuthor()), Helper::toLowerStr((char*)author));
}

bool checkerISBN(const Book& book, const char* ISBNStr) {
	return book.getISBN() == ISBN(ISBNStr);
}

bool checkerDescription(const Book& book, const char* description) {
	const size_t BOOK_DESCRIPTION_SIZE = strlen(book.getDescription());
	const size_t DESCRIPTION_SIZE = strlen(description);
	size_t descriptionIndex = 0;

	for (size_t i = 0; i < BOOK_DESCRIPTION_SIZE; ++i) {
		if (descriptionIndex == DESCRIPTION_SIZE) return true;

		if (book.getDescription()[i] == description[descriptionIndex]) ++descriptionIndex;
		else descriptionIndex = 0;
	}

	if (descriptionIndex == DESCRIPTION_SIZE) return true;

	return false;
}
