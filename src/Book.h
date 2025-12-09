#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;
    std::string isbn;
    bool isAvailable;
    std::string borrowedBy;

public:
    Book(std::string title, 
        std::string author, 
        int year, 
        std::string isbn);

    //Getter-методы для всех полей
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getIsbn() const;
    bool getIsAvaible() const;
    std::string getBorrowedBy() const;

    void borrowBook(std::string userName);
    void returnBook();
    void displayInfo() const;
};

#endif