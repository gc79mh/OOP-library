#include "../inc/DebugPrinter.h"

DebugPrinter::DebugPrinter() {}

DebugPrinter::~DebugPrinter() {}

void DebugPrinter::Print(Book book) {
  std::cout << "Title: " + book.getTitle() << std::endl;
  std::cout << "Author: " + book.getAuthor() << std::endl;
}

void DebugPrinter::Print(User* user) {
  std::cout << "User ID: " << user->getId() << std::endl;
  std::cout << "Username: " << user->getUsername() << std::endl;
}

void DebugPrinter::Print(Library library) {
  
  std::cout << "USERS:" << std::endl;
  auto users = library.getUsers();
  for (auto user : users) {
    Print(user);
  }

  std::cout << std::endl;
  std::cout << "BOOKS:" << std::endl;
  auto books = library.getBooks();
  for (auto book : books) {
    Print(*book);
  }
}
