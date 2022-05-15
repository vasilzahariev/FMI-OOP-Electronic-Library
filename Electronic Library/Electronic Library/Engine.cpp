#include "Engine.h"

Engine::Engine() {
	std::ifstream file(FILE_NAME);

	if (!file.is_open())
		throw "File did not open correctly!";

	file >> m_library;
}

Engine& Engine::getInstance() {
	static Engine engine;

	return engine;
}

void Engine::run() {
	char operation;
	
	do {
		printOperations();
		
		std::cout << "Enter: ";

		std::cin >> operation;
		
		if (operation == '1')
			sortBook();
		else if (operation == '2')
			findBook();
		else if (operation == '3')
			addBook();
		else if (operation == '4')
			removeBook();
		else if (operation == '5')
			readBook();
		else if (operation == '6')
			std::cout << "Bye!" << std::endl;
		else
			std::cout << "Invalid operation" << std::endl;

		if (operation != '6') {
			system("pause");
			system("cls");
		}

	} while (operation != '6');
}

void Engine::saveChanges() {
	std::ofstream file(FILE_NAME);

	if (!file.is_open())
		throw "File did not open correctly!";

	file << m_library;

	file.close();
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
	char password[PASSWORD_SIZE]{ '\0', };

	std::cout << "This action requires authentication" << std::endl;
	std::cout << "Please enter the password: " << std::endl;

	std::cin.ignore();
	std::cin.getline(password, PASSWORD_SIZE);


	return strcmp(password, PASSWORD.c_str()) == 0;
}

void Engine::sortBook() {
	const size_t SORTING_TYPE_SIZE = 50;
	const size_t PRINTING_TYPE_SIZE = 50;
	char sortingType[SORTING_TYPE_SIZE];
	char printingType[PRINTING_TYPE_SIZE];
	
	do {
		std::cout << "Enter a sorting type (title | author | ISBN): " << std::endl;
		std::cin.ignore().get(sortingType, SORTING_TYPE_SIZE);
	} while (strcmp(Helper::toLowerStr(sortingType), "title") != 0 &&
			 strcmp(Helper::toLowerStr(sortingType), "author") != 0 &&
			 strcmp(Helper::toLowerStr(sortingType), "isbn") != 0);

	do {
		std::cout << "Enter a printing type (ascending | descending): " << std::endl;
		std::cin.ignore().get(printingType, PRINTING_TYPE_SIZE);
	} while (strcmp(Helper::toLowerStr(printingType), "ascending") != 0 &&
			 strcmp(Helper::toLowerStr(printingType), "descending") != 0);

	bool isAscending = strcmp(Helper::toLowerStr(printingType), "ascending") == 0;

	if (strcmp(Helper::toLowerStr(sortingType), "title") == 0)
		m_library.sortByAndPrint(&cmpTitle, isAscending);
	else if (strcmp(Helper::toLowerStr(sortingType), "author") == 0)
		m_library.sortByAndPrint(&cmpAuthor, isAscending);
	else if (strcmp(Helper::toLowerStr(sortingType), "isbn") == 0)
		m_library.sortByAndPrint(&cmpISBN, isAscending);
	else
		std::cout << "Invalid sorting type!" << std::endl;
}

void Engine::findBook() {
	const size_t CRITERIA_SIZE = 50;
	const size_t SEARCH_SIZE = 100;

	char criteria[CRITERIA_SIZE];

	std::cout << "Enter a search criteria(title | author | ISBN | description): ";
	std::cin.ignore().get(criteria, CRITERIA_SIZE);

	char search[SEARCH_SIZE];

	if (strcmp(Helper::toLowerStr(criteria), "title") == 0)
		searchInput("Enter the title: ", search, SEARCH_SIZE, &checkerTitle);
	else if (strcmp(Helper::toLowerStr(criteria), "author") == 0)
		searchInput("Enter the author: ", search, SEARCH_SIZE, &checkerAuthor);
	else if (strcmp(Helper::toLowerStr(criteria), "isbn") == 0)
		searchInput("Enter the ISBN(don't separate the numbers with spaces): ", search, SEARCH_SIZE, &checkerISBN);
	else if (strcmp(Helper::toLowerStr(criteria), "description") == 0)
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

	saveChanges();
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
		const char* fileName = m_library[title].getFileName();

		char SHOULD_DELETE[5];
		
		do {
			std::cout << "Do you want to delete the file containg the book? (yes | no)" << std::endl;
			std::cin.get(SHOULD_DELETE, 5);
		} while (strcmp(SHOULD_DELETE, "yes") != 0 && strcmp(SHOULD_DELETE, "no") != 0);

		if (strcmp(SHOULD_DELETE, "yes") == 0) {
			remove(fileName);
		}

		m_library -= m_library[title];
	}
	catch (int err) {
		std::cout << "Book does not exist!" << std::endl;
	}

	saveChanges();
}

void Engine::readBook() {
	const size_t TITLE_SIZE = 100;
	char title[TITLE_SIZE];

	std::cout << "Enter book titile:" << std::endl;

	std::cin.ignore();
	std::cin.getline(title, TITLE_SIZE);

	try {
		std::ifstream file(m_library[title].getFileName());

		if (!file.is_open()) {
			std::cout << "There was a problem while trying to open the file!" << std::endl;

			return;
		}

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

		if (!file.eof()) system("pause");
		else std::cout << std::endl << "You've read the whole book!" << std::endl;
	}
}

void Engine::readBookLine(std::ifstream& file) {
	const size_t LINE_SIZE = 1025;
	char line[LINE_SIZE];

	file.getline(line, LINE_SIZE);

	std::cout << line << std::endl;
}

void Engine::bookReaderPunctuationMark(std::ifstream& file) {
	char punctMark;

	do {
		std::cout << "Enter the punctuation mark you would like to stop reading at: ";
		std::cin >> punctMark;
	} while (std::ispunct(punctMark) == false);

	readBookUntilPunctMark(file, punctMark);
}

void Engine::readBookUntilPunctMark(std::ifstream& file, const char punctMark) {
	while (!file.eof()) {
		readBookText(file, punctMark);

		if (!file.eof()) system("pause");
		else std::cout << std::endl << "You've read the whole book!" << std::endl;
	}
}

void Engine::readBookText(std::ifstream& file, const char punctMark) {
	const size_t TEXT_SIZE = 1025;
	char text[TEXT_SIZE];

	file.getline(text, TEXT_SIZE, punctMark);

	std::cout << text << std::endl;
}

void Engine::searchInput(const char* inputText, char search[], const size_t SEARCH_SIZE, bool(*checker)(const Book&, const char*)) {
	std::cout << inputText;
	std::cin.ignore().get(search, SEARCH_SIZE);

	Book* book = m_library.findABook(checker, search);

	if (book != nullptr) std::cout << *book << std::endl;
}

bool cmpTitle(const Book& b1, const Book& b2, const bool isAscending) {
	std::cout << std::boolalpha << isAscending << std::endl;

	return (isAscending ? strcmp(b1.getTitle(), b2.getTitle()) < 0 : strcmp(b1.getTitle(), b2.getTitle()) > 0);
}

bool cmpAuthor(const Book& b1, const Book& b2, const bool isAscending) {
	return (isAscending ? strcmp(b1.getAuthor(), b2.getAuthor()) < 0 : strcmp(b1.getAuthor(), b2.getAuthor()) > 0);
}

bool cmpISBN(const Book& b1, const Book& b2, const bool isAscending) {
	return (isAscending ? b1.getISBN() < b2.getISBN() : b1.getISBN() > b2.getISBN());
}

bool checkerTitle(const Book& book, const char* title) {
	return strcmp(Helper::toLowerStr(book.getTitle()), Helper::toLowerStr((char*) title)) == 0;
}

bool checkerAuthor(const Book& book, const char* author) {
	return strcmp(Helper::toLowerStr(book.getAuthor()), Helper::toLowerStr((char*)author)) == 0;
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
