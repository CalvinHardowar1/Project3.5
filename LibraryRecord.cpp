#include "LibraryRecord.hpp"

bool LibraryRecord::checkIn(const Book& book){

    bool result = add(book);
    return result;


}
bool LibraryRecord::checkOut(const Book& book){
    bool result = remove(book);

    if (result){
        
        checkedOutBooks.add(book);
    }
    return result;    
}

int LibraryRecord::getCheckOutHistory(const Book& book){
    
    int result = checkedOutBooks.getFrequencyOf(book);
    return result;
} 

void LibraryRecord::display(){

     for (int i = 0; i < getCurrentSize();i++) {
    Book& currentBook = items_[i]; 
    std::cout << currentBook.getTitle() <<" is written by " << currentBook.getAuthor();
    std::cout << ". Page Count: " << currentBook.getPageCount();
    std::cout << (currentBook.isDigital() ? "It is " :  "It is not " )<< "available digitally.\n";
    std::cout <<"It has been checked out " << checkedOutBooks.getFrequencyOf(currentBook) << " times.\n";
         
    
        
         
     }     

}
 void LibraryRecord::displayTitles(){
    std:: cout << getCurrentSize()<< " .\n";
     
    for (int i = 0; i < getCurrentSize(); i++) {
        Book& currentBook = items_[i];
        std::cout << currentBook.getTitle(); 
        if (i + 1 < getCurrentSize()){
            std::cout<< ", ";        
         }
            
    }
     
     std::cout <<"!\n";
 }    


bool LibraryRecord::duplicateStock(){

    bool result = true;
    int count = getCurrentSize();
    for (int i = 0;i<count;i++){
        result = add(items_[i]);
        if (result == false){

            return false;
            
        }
        
    }
    
    return true;
}

bool LibraryRecord::removeStock(const Book& book){
    bool result = remove(book);
    return result;
    
}

bool LibraryRecord::equivalentRecords(const LibraryRecord& rightParam){
    for (int i = 0; i < getCurrentSize() ; i++){
        const Book& currentBook = items_[i];  
        int occurrance_in_this = getFrequencyOf(currentBook);
        int occurrance_in_rightParam =rightParam.getFrequencyOf(currentBook);
        //std::cout << occurrance_in_this << "\n";
        //std::cout << occurrance_in_rightParam<< "\n"; 
        //std::cout<< "\n";
        if (occurrance_in_this != occurrance_in_rightParam) {
            return false;
           
        }
       
    }

    for (int i = 0; i < rightParam.getCurrentSize() ; i++){
        const Book& currentBook = rightParam.items_[i];  
        int occurrance_in_this = getFrequencyOf(currentBook);
        int occurrance_in_rightParam =rightParam.getFrequencyOf(currentBook);
        //std::cout << occurrance_in_this << "\n";
        //std::cout << occurrance_in_rightParam<< "\n";  
        // std::cout<< "\n";
        if (occurrance_in_this != occurrance_in_rightParam) {
            return false;
        }   
        
    }
    return true;
}

LibraryRecord & LibraryRecord::operator+=(const LibraryRecord& rightParam){

    ((ArrayBag<Book>&)(*this)) += ((const ArrayBag<Book>&)(rightParam));
    checkedOutBooks+=rightParam.checkedOutBooks;
    return *this;
    
}

LibraryRecord & LibraryRecord::operator/=(const LibraryRecord& rightParam){
    ((ArrayBag<Book>&)(*this)) /= ((const ArrayBag<Book>&)(rightParam));
    checkedOutBooks/=rightParam.checkedOutBooks;
    return *this;
}
