#include "../inc/DebugPrinter.h"
#include <iostream>

DebugPrinter::DebugPrinter() {}

DebugPrinter::~DebugPrinter() {}

void DebugPrinter::Print(Book& book) {
  std::cout << "Title: " + book.getTitle() << std::endl;
  std::cout << "Author: " + book.getAuthor() << std::endl;
}

void DebugPrinter::Print(User* user) {
  std::cout << "User ID: " << user->getId() << std::endl;
  std::cout << "Username: " << user->getUsername() << std::endl;
}


void DebugPrinter::Print(PrivilegeLevel pl) {
  switch (pl) {
    case PrivilegeLevel::BOSS:
      std::cout << "Boss";
      break;
    case PrivilegeLevel::WORKER:
      std::cout << "Worker";
      break;
    case PrivilegeLevel::USER:
      std::cout << "User";
      break;
  }
}

void DebugPrinter::Print(Library& library) {
  std::cout << std::endl; 
  std::cout << "USERS:" << std::endl;
  auto users = library.getUsers();
  for (auto user : users) {
    Print(user);
    std::cout << "Class: ";
    Print(user->getType());
    std::cout << std::endl;
  }

  std::cout << std::endl;
  std::cout << "BOOKS:" << std::endl;
  auto books = library.getBooks();
  for (auto pair : books) {
    Print(*(pair.first));
    std::cout << "Count: " << pair.second << std::endl;
  }
}
