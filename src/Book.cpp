#include "Book.h"
#include <iostream>

Book::Book(const std::string title, 
        const std::string author,
        int year,
        const std::string isbn) 
    : title(title),
    author(author),
    year(year),
    isbn(isbn),
    isAvailable(true),
    borrowedBy("") {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

std::string Book::getIsbn() const {
    return isbn;
}

bool Book::getIsAvaible() const {
    return isAvailable;
}

std::string Book::getBorrowedBy() const {
    return borrowedBy;
}

void Book::borrowBook(std::string userName) {
    isAvailable = false;
    borrowedBy = userName;
}

void Book::returnBook() {
    isAvailable = true;
    borrowedBy.clear();
}

void Book::displayInfo() const {
    std::cout << "Title: " << title << "\n";
}