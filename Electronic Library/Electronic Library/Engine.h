#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "Library.h"

/*!
* Имплементира основната функционалност на един Engine
* Имплементацията е осъществена чрез Singleton Design Pattern-а, защото не искаме да може да се използва на повече от едно място и да има други негови инстанции
*/
class Engine {
public:
	/*!
	* Взима единствената инстанция на Engine
	* @return Референция към единствената инстанция на Engine
	*/
	static Engine& getInstance();

	/*!
	* Пуска основната функционалност на програмата
	*/
	void run();

private:
	/*!
	* Конструктор по подозиране на Engine
	*/
	Engine();
	/*!
	* Изтриване на конструктора за копиране, защото не искаме да може да се появява друга инстанция на Engine
	*/
	Engine(const Engine& engine) = delete;

	/*!
	* Изтриване на оператор "=", защото не искаме да може да се появява друга инстанция на Engine
	*/
	Engine& operator=(const Engine& other) = delete;

private:
	/*!
	* Главната библиотека (Library)
	*/
	Library m_library;
	/*!
	* Името на файла, съдържащ библиотеката (Library)
	* Използвам std::string, защото ме мързи
	*/
	const std::string FILE_NAME = "library.txt";
	/*!
	* Паролата нужна за аутентикация на административните операции
	*/
	const std::string PASSWORD = "vErYsEcUrEpAsS";

	/*!
	* Запазва главната библиотека (Library)
	*/
	void saveChanges();

	/*!
	* Принтира всички операции на конзолата
	*/
	void printOperations();

	/*!
	* Проверка дали потребителят знае админската парола
	*/
	bool checkForAuthentication();

	/*!
	* Изпълнява операцията за сортиране
	*/
	void sortBook();
	/*!
	* Изпълнява операцията за намиране на книга по определен критерий
	*/
	void findBook();
	/*!
	* Изпълнява операцията за добавяне на книга
	*/
	void addBook();
	/*!
	* Изпълнява операцията за премахване на книга
	*/
	void removeBook();
	/*!
	* Изпълнява операцията за извеждане на книгата
	*/
	void readBook();
	
	/*!
	* Приема по какъв начин ще бъде четена книгата
	* @param file - Файлов поток, от който ще се чете книгата
	*/
	void bookReader(std::ifstream& file);

	/*!
	* Приема по колко реда на веджън ще бъдат прочетени
	* @param file - Файлов поток, от който ще се чете книгата
	*/
	void bookReaderRows(std::ifstream& file);
	/*!
	* Чете по определен брой редове докато не стигне краят на книгата
	* @param file - Файлов поток, от който ще се чете книгата
	* @param rowsToRead - Брой на редовете, които ще бъдат прочетени
	*/
	void readBookRows(std::ifstream& file, const int rowsToRead);
	/*!
	* Прочитане на ред от файла
	* @param file - Файлов поток, от който ще се чете книгата
	*/
	void readBookLine(std::ifstream& file);

	/*!
	* Приема до какъв знак ще бъде четенето
	* @param file - Файлов поток, от който ще се чете книгата
	*/
	void bookReaderPunctuationMark(std::ifstream& file);
	/*!
	* Чете до определен знак докато не стигне краят на книгата
	* @param file - Файлов поток, от който ще се чете книгата
	* @param punctMark - Знакът до който ще се чете
	*/
	void readBookUntilPunctMark(std::ifstream& file, const char punctMark);
	/*!
	* Прочитане до определен пунктуационен знак
	*/
	void readBookText(std::ifstream& file, const char punctMark);

	void searchInput(const char* inputText, char search[], const size_t SEARCH_SIZE, bool (*checker)(const Book&, const char*));
};

/*!
* Сравнява и намира коя книга е по-малка по азбучен ред
*/
bool cmpTitle(const Book&, const Book&, const bool);
/*!
* Сравнява и намира коя книга е по-малка по азбучен ред
*/
bool cmpAuthor(const Book&, const Book&, const bool);
/*!
* Сравнява и намира коя книга е по-малка по ISBN
*/
bool cmpISBN(const Book&, const Book&, const bool);

/*!
* Проверява дали заглавието на книгата е същото като подаденото
*/
bool checkerTitle(const Book&, const char*);
/*!
* Проверява дали името на автора на книгата е същото като подаденото
*/
bool checkerAuthor(const Book&, const char*);
/*!
* Проверява дали ISBN на книгата е същият като на подаденият
*/
bool checkerISBN(const Book&, const char*);
/*!
* Проверява дали подаденият текс се съдържа в описанието на книгата
*/
bool checkerDescription(const Book&, const char*);

#endif // !ENGINE_H
