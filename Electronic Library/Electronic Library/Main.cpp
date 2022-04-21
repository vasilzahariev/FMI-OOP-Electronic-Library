#pragma warning(disable: 4996)

#include <fstream>

#include "Book.h"

int main() {
	int ISBN[13]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	Book book("Author", "Title", "title.txt", "Description", 5, ISBN);

	std::ofstream file("book.txt");

	file << book;

	file.close();

	std::ifstream fileReader("book.txt");

	fileReader >> book;

	fileReader.close();

	std::cout << book;

	return 0;
}
