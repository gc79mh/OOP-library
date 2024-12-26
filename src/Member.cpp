#include "../inc/Member.h"

Member::Member(int memberId) {
  this->memberId = memberId;
}
Member::~Member() {}

std::vector<Book> Member::checkBooks() {
  return this->borrowedBooks;
}

void Member::borrowBook(Book book) {
  this->borrowedBooks.push_back(book);
}

void Member::returnBook(Book book) {
  for (int i = 0 ; i < this->borrowedBooks.size() ; i++) {
    if (this->borrowedBooks[i] == book) {
      this->borrowedBooks.erase(this->borrowedBooks.begin() + i);
      break;
    }
  }
}

int Member::getMemberId() const {
  return this->memberId;
}

bool operator==(const Member &lhs, const Member &rhs) {
  return lhs.getMemberId() == rhs.getMemberId();
}

std::ostream &operator<<(std::ostream &os, const Member &obj) {
  os << "Member Id: ";
  os << obj.getMemberId();
  return os;
}
