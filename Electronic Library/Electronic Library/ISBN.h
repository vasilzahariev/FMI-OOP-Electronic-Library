#ifndef ISBN_H
#define ISBN_H

#include <iostream>

class ISBN {
public:
	ISBN();
	ISBN(const ISBN& other);

	ISBN& operator=(const ISBN& other);

	bool operator==(const ISBN& other) const;
	bool operator<(const ISBN& other) const;

	unsigned int& operator[](const int index);
	const unsigned int& operator[](const int index) const;

	friend std::istream& operator>>(std::istream& in, ISBN& isbn);
	friend std::ostream& operator<<(std::ostream& out, const ISBN& isbn);

private:
	static const size_t SIZE = 13;
	unsigned int m_data[SIZE] = { 0, };

	void copy(const ISBN& other);
};

#endif // !ISBN_H
