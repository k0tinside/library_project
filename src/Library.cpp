#include <iostream>
#include "Library.h"

Library::Library(const std::string& dataFile)
    : books(),
      users(),
      dataFile(dataFile) {}

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::addUser(const User& user) {
    users.push_back(user);
}

void Library::borrowBook(const std::string& userName, const std::string& isbn) {
    Book* book = findBookByISBN(isbn);
    User* user = findUserByName(userName);

    if (book == nullptr || user == nullptr) {
        std::cout << "User or book not found\n";
        return;
    }

    if (user->canBorrowMore() && book->getIsAvailable()) {
        user->addBook(isbn);
        book->borrowBook(userName);
    } else {
        std::cout << "error";
    }
}

void Library::returnBook(const std::string& isbn) {
    Book* book = findBookByISBN(isbn);
    
    if (book == nullptr) {
        std::cout << "Book not found\n";
        return;
    }

    std::string borrower = book->getBorrowedBy();
    if (borrower.empty()) {
        std::cout << "Book is not borrowed\n";
        return;
    }

    User* user = findUserByName(borrower);
    if (user == nullptr) {
        std::cout << "User not found\n";
        return;
    }

    user->removeBook(isbn);
    book->returnBook();
}

Book* Library::findBookByISBN(const std::string& isbn) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getIsbn() == isbn) {
            return &(*it);
        }
    }
    return nullptr;
}

User* Library::findUserByName(const std::string& name) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getName() == name) {
            return &(*it);
        }
    }
    return nullptr;
}

void Library::displayAllBooks() {
    for (auto it = books.begin(); it != books.end(); ++it) {
        it->displayInfo();
        std::cout << "-----------------\n";
    }
}

void Library::displayAllUsers() {
    for (auto it = users.begin(); it != users.end(); ++it) {
        it->displayProfile();
        std::cout << "-----------------\n";
    }
}

void Library::saveToFile() {
    std::cout << "saveToFile() not implemented yet\n";
}

void Library::loadFromFile() {
    std::cout << "loadFromFile() not implemented yet\n";
}