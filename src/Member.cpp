#include "../inc/Member.h"

Member::Member(int memberId) {
  this->memberId = memberId;
};
Member::~Member() {};

void Member::borrowBook(Book book) {
  this->borrowedBooks.push_back(book);
};

void Member::returnBook(Book book) {
  for (int i = 0; i < this->borrowedBooks.size(); i++) {
    if (this->borrowedBooks[i] == book) {
      return;
    }
  }
};

int Member::getMemberId() { return memberId; };

std::ostream &operator<<(std::ostream &os, const Member &obj) {
  // write obj to stream
  return os;
};
