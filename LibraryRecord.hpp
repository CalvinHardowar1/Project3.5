#ifndef LIBRARY_RECORD_HPP
#define LIBRARY_RECORD_HPP


#include "Book.hpp"
#include "ArrayBag.hpp"

class LibraryRecord : public ArrayBag<Book>{
ArrayBag<Book>checkedOutBooks;

public:
bool checkIn(const Book& book);
bool checkOut(const Book& book);
int getCheckOutHistory(const Book& book);

void display();
void displayTitles();
bool duplicateStock();
bool removeStock(const Book& book);
bool equivalentRecords(const LibraryRecord& Library);

LibraryRecord & operator+=(const LibraryRecord& rightParam);
LibraryRecord & operator/=(const LibraryRecord& rightParam);



};
#endif