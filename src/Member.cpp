#include "../inc/Member.h"

Member::Member(int id, std::string username, std::string password)
    : User(id, username, password) {}

std::vector<Book> Member::checkBooks() const { return this->borrowedBooks; }

void Member::borrowBook(Book book) { this->borrowedBooks.push_back(book); }

void Member::returnBook(Book book) {
  for (int i = 0; i < (int)this->borrowedBooks.size(); i++) {
    if (this->borrowedBooks[i] == book) {
      this->borrowedBooks.erase(this->borrowedBooks.begin() + i);
      break;
    }
  }
}
