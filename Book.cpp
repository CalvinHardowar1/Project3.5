#include <iostream>
#include "Book.hpp"
//default constructor, booleans set at false
Book::Book()
    : title(""), author(""), pagenumber(0), digital(false) {}
//paramaterized constructor with strings and constants to initiate functions
Book::Book(std::string const title, std::string const author, const int pagenumber, bool digital)
    : title(title), author(author), pagenumber(pagenumber), digital(digital) {}
// setters and getters used here for core functions such as title, author and page count
void Book::setTitle (const std::string& title) 
{ this->title = title; }
std::string Book::getTitle() const
{ return title; }
void Book::setAuthor(const std::string& author) 
{ this->author = author; }
std::string Book::getAuthor() const 
{ return author; }
//if statement used here to determine correct page number in case it is defaulted as a negative value or below 0, you can't have 0 pages in a book.
void Book::setPageCount(const int& pagenumber)  
{ 
  if  (pagenumber > 0) {
     this->pagenumber = pagenumber;
    
  }
   }
//accessor functions
int Book::getPageCount() const
{ return pagenumber; }
void Book::setDigital() 
{ this->digital = true; } 
  bool Book::isDigital() const 
{ return digital; }


bool Book::operator==(const Book& rhs)const {
    return (title == rhs.title)&&
    (author == rhs.author)&&
    (pagenumber == rhs.pagenumber)&&
     (digital == rhs.digital);
}

bool Book::operator!=(const Book& rhs) const {
    if (title != rhs.title){
        return true;
    }
    if (author != rhs.author){
        return true;
    }
    if (pagenumber != rhs.pagenumber){
        return true;
    }
    if (digital != rhs.digital){
        return true;
    }
    return false;
}

void Book::display() const {
    if (digital) {
        std::string digital_str = "available digitally";
        std::cout << title << " is written by " << author << ". Page Count: " << pagenumber << ". It is " << digital_str << "\n";
    } else {
        std::string digital_str = "not available digitally";
        std::cout << title << " is written by " << author << ". Page Count: " << pagenumber << ". It is " << digital_str << "\n";
    }
}