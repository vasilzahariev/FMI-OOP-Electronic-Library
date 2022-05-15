#include "ISBN.h"

ISBN::ISBN() {
}

ISBN::ISBN(const char* ISBNstr) {
    for (size_t i = 0; i < SIZE; ++i)
        m_data[i] = Helper::charToInt(ISBNstr[i]);
}

ISBN::ISBN(const ISBN& other) {
    copy(other);
}

ISBN& ISBN::operator=(const ISBN& other) {
    if (this != &other) copy(other);

    return *this;
}

bool ISBN::operator==(const ISBN& other) const {
    for (size_t i = 0; i < ISBN::SIZE; ++i)
        if ((*this)[i] != other[i])
            return false;

    return true;
}

bool ISBN::operator<(const ISBN& other) const {
    for (size_t i = 0; i < SIZE; ++i)
        if ((*this)[i] < other[i])
            return true;

    return false;
}

bool ISBN::operator>(const ISBN& other) const {
    for (size_t i = 0; i < SIZE; ++i)
        if ((*this)[i] > other[i])
            return true;

    return false;
}

unsigned int& ISBN::operator[](const int index) {
    if (index < 0 || index >= 13)
        throw "Index out of bounds";

    return m_data[index];
}

const unsigned int& ISBN::operator[](const int index) const {
    if (index < 0 || index >= 13)
        throw "Index out of bounds";

    return m_data[index];
}

void ISBN::copy(const ISBN& other) {
    for (size_t i = 0; i < SIZE; ++i)
        (*this)[i] = other[i];
}

std::istream& operator>>(std::istream& in, ISBN& isbn) {
    for (size_t i = 0; i < ISBN::SIZE; ++i)
        in >> isbn[i];

    return in;
}

std::ostream& operator<<(std::ostream& out, const ISBN& isbn) {
    for (size_t i = 0; i < ISBN::SIZE; ++i)
        out << isbn[i] << ' ';

    return out;
}
