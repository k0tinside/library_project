#include <iostream>
#include <windows.h>
#include "Book.h"
#include "User.h"
#include "Library.h"

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    try {
        // Тест Book
        Book b1("Война и мир", "Лев Толстой", 1869, "5671");
        std::cout << "Книга создана успешно" << std::endl;
        b1.displayInfo();
        std::cout << std::endl;

        // Плохой год
        try {
            Book b_bad("Плохая книга", "Автор", 1000, "123");
        } catch (const std::exception& ex) {
            std::cout << "Ошибка (ожидается): " << ex.what() << std::endl;
        }
        std::cout << std::endl;

        // пустой ISBN
        try {
            Book b_bad2("Плохая книга", "Автор", 2000, "");
        } catch (const std::exception& ex) {
            std::cout << "Ошибка (ожидается): " << ex.what() << std::endl;
        }
        std::cout << std::endl;

        // Тест выдачи и возврата книги
        b1.borrowBook("Иванов");
        std::cout << "Книга выдана Иванову" << std::endl;
        b1.displayInfo();
        std::cout << std::endl;

        // Попытка выдать уже выданную книгу
        try {
            b1.borrowBook("Петров");
        } catch (const std::exception& ex) {
            std::cout << "Ошибка (ожидается): " << ex.what() << std::endl;
        }
        std::cout << std::endl;

        // Возврат книги
        b1.returnBook();
        std::cout << "Книга возвращена" << std::endl;
        b1.displayInfo();
        std::cout << std::endl;

        // Тест User
        User u1("Иванов", "USR_001");
        std::cout << "Пользователь создан успешно" << std::endl;
        u1.displayProfile();
        std::cout << std::endl;

        // Пустое имя
        try {
            User u_bad("", "USR_002");
        } catch (const std::exception& ex) {
            std::cout << "Ошибка (ожидается): " << ex.what() << std::endl;
        }
        std::cout << std::endl;

        // Тест добавления и удаления книг пользователю
        u1.addBook("978-5-17-70490-8");
        u1.addBook("978-5-17-77192-5");
        u1.addBook("978-0-13-110388-8");
        std::cout << "Добавлены 3 книги (максимум)" << std::endl;
        u1.displayProfile();
        std::cout << std::endl;

        // Попытка добавить 4-ю книгу
        try {
            u1.addBook("978-9999-99999-9");
        } catch (const std::exception& ex) {
            std::cout << "Ошибка (ожидается): " << ex.what() << std::endl;
        }
        std::cout << std::endl;

        // Удаление одной книги
        u1.removeBook("978-5-17-70490-8");
        std::cout << "Одна книга удалена" << std::endl;
        u1.displayProfile();
        std::cout << std::endl;

        // Попытка удалить несуществующую книгу
        try {
            u1.removeBook("111-111-111-111");
        } catch (const std::exception& ex) {
            std::cout << "Ошибка (ожидается): " << ex.what() << std::endl;
        }

        // Тест Library
        Library lib("data/library_data.txt");
        lib.addBook(b1);
        lib.addUser(u1);
        std::cout << "Книга и пользователь добавлены в библиотеку" << std::endl;

        lib.displayAllBooks();
        std::cout << std::endl;

        lib.displayAllUsers();
        std::cout << std::endl;


    } catch (const std::exception& ex) {
        std::cerr << "Неожиданная ошибка: " << ex.what() << std::endl;
    }

    return 0;
}
