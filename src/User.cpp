#include <iostream>
#include "User.h"
 
User::User(std::string name,
           std::string userId,
           int maxBooksAllowed)
    : name(name),
    userId(userId),
    borrowedBooks(),
    maxBooksAllowed(maxBooksAllowed) {}

std::string User::getName() const {
    return name;
}

std::string User::getUserId() const {
    return userId;
}

std::vector<std::string> User::getBorrowedBooks() const {
    return borrowedBooks;
}
int User::getMaxBooksAllowed() const {
    return maxBooksAllowed;
}


bool User::canBorrowMore() const {
    return borrowedBooks.size() < maxBooksAllowed;
}

void User::addBook(const std::string& isbn) {
    borrowedBooks.push_back(isbn);
}

void User::removeBook(const std::string& isbn) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (*it == isbn) {
            borrowedBooks.erase(it);
            break;
        }
    }
}

void User::displayProfile() const {
    std::cout << "Name: " << name << "\n";
}