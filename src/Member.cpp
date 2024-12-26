#include "../inc/Member.h"

Member::Member(int memberId) {
  this->memberId = memberId;
}
Member::~Member() {}

std::vector<Book> Member::checkBooks() const {
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
  os << std::endl;
  os << "Books: " << std::endl;
  if (obj.checkBooks().size() == 0) {
    os << "-" << std::endl;
  } else {
    for (int i = 0 ; i < obj.checkBooks().size() ; i++) {
      os << i+1 << ": ";
      os << obj.checkBooks()[i].getTitle() << " - ";
      os << obj.checkBooks()[i].getAuthor();
    }
  }
  return os;
}
