#include "../inc/Member.h"

Member::Member(int id, std::string username, std::string password)
    : User(id, username, password) {}

Member::~Member() {}

std::vector<Book> Member::getBooks() const { 
  return borrowedBooks;
}

void Member::borrowBook(Book book) { 
  borrowedBooks.push_back(book);
}

void Member::returnBook(Book book) {
  for (int i = 0; i < (int) borrowedBooks.size(); i++) {
    if (borrowedBooks[i] == book) {
      borrowedBooks.erase(borrowedBooks.begin() + i);
      break;
    }
  }
}

UserType Member::getType() const {
  return UserType::USER;
}
