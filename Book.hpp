#ifndef BOOK_HPP
#define BOOK_HPP



#include <string>
//book class to suit the necessary functions such as title author page number and if its digital or not
class Book {
  private:
    std::string title;
    std::string author;
    int pagenumber;
    bool digital;
// adding functions and paramters using setters and getters for user proceses of the functions
  public:
    Book();
    Book(std::string title, std::string author, int pagenumber, bool digital = false);
    void setTitle(const std::string& title);
    std::string getTitle() const;
    void setAuthor(const std::string& author);
    std::string getAuthor() const;
    void setPageCount(const int& pagenumber);
    int getPageCount() const;
    void setDigital();
    bool isDigital() const;

bool operator==(const Book& rhs) const;
bool operator!=(const Book& rhs) const;

void display() const;
};
#endif// used to reference cpp files

#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}