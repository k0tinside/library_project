#include <iostream>
#include "Library.h"

Library::Library(const std::string& dataFile)
    : books(),
      users(),
      dataFile(dataFile) {}

void Library::addBook(const Book& book) {
    std::string isbn = book.getIsbn();
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it).getIsbn() == isbn) {
            throw std::invalid_argument("ISBN должен быть уникальным");
        }
    }
    books.push_back(book);
}

void Library::addUser(const User& user) {
    std::string idUser = user.getUserId();
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it).getUserId() == idUser) {
            throw std::invalid_argument("ID пользователя должен быть уникальным");
        }
    }
    users.push_back(user);
}

void Library::borrowBook(const std::string& userId, const std::string& isbn) {
    if (isbn == "") { 
        throw std::invalid_argument("ISBN должен быть не пустым");
    }
    if (userId == "") {
        throw std::invalid_argument("ID пользователя не может быть пустым");
    }

    Book* book = findBookByISBN(isbn);
    User* user = findUserByUserId(userId);

    if (book == nullptr) {
        throw std::runtime_error("Книга не найдена");
    }
    if (user == nullptr) {
        throw std::runtime_error("Пользователь не найден");
    }

    if (user->canBorrowMore() && book->getIsAvailable()) {
        user->addBook(isbn);
        book->borrowBook(userId); // !
    } else if (!user->canBorrowMore()) {
        throw std::runtime_error("У пользователя максимальное количество книг");
    } else {
        throw std::runtime_error("Книга уже взята");
    }
}

void Library::returnBook(const std::string& isbn) {
    if (isbn == "") { 
        throw std::invalid_argument("ISBN должен быть не пустым");
    }
    
    Book* book = findBookByISBN(isbn);
    
    if (book == nullptr) {
        throw std::runtime_error("Книга не найдена");
    }

    std::string borrower = book->getBorrowedBy();
    if (borrower.empty()) {
        throw std::runtime_error("Книга не была взята");
    }

    User* user = findUserByUserId(borrower);
    if (user == nullptr) {
        throw std::runtime_error("Пользователь не найден");
    }

    user->removeBook(isbn);
    book->returnBook();
}

Book* Library::findBookByISBN(const std::string& isbn) {
    if (isbn == "") { 
        throw std::invalid_argument("ISBN должен быть не пустым");
    }
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getIsbn() == isbn) {
            return &(*it);
        }
    }
    return nullptr;
}
// считаю, что лучше реализовать метод по поиску айди - имена могут повторяться
User* Library::findUserByName(const std::string& name) {
    if (name == "") {
        throw std::invalid_argument("Имя пользователя не может быть пустым");
    }
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getName() == name) {
            return &(*it);
        }
    }
    return nullptr;
}

User* Library::findUserByUserId(const std::string& userId) {
    if (userId == "") {
        throw std::invalid_argument("ID пользователя не может быть пустым");
    }
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->getUserId() == userId) {
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