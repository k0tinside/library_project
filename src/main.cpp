#include <iostream>
#include "Book.h"

int main() {
    Book b("Test book", "Author", 2000, "123");
    std::cout << b.getTitle() << "\n";
    return 0;
}