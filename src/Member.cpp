#include "../inc/Member.h"

Member::Member(int memberId, std::string name, std::string surname) {
  this->memberId = memberId;
  this->name = name;
  this->surname = surname;
}

Member::~Member() {}

std::vector<Book> Member::checkBooks() const { return this->borrowedBooks; }
void Member::borrowBook(Book book) { this->borrowedBooks.push_back(book); }
void Member::returnBook(Book book) {
  for (int i = 0; i < this->borrowedBooks.size(); i++) {
    if (this->borrowedBooks[i] == book) {
      this->borrowedBooks.erase(this->borrowedBooks.begin() + i);
      break;
    }
  }
}

int Member::getMemberId() const { return this->memberId; }
std::string Member::getName() const { return this->name; }
std::string Member::getSurname() const { return this->surname; }

bool operator==(const Member &lhs, const Member &rhs) {
  return lhs.getMemberId() == rhs.getMemberId();
}

std::ostream &operator<<(std::ostream &os, const Member &obj) {
  os << "Member ID: ";
  os << obj.getMemberId() << std::endl;
  os << "Member Name: ";
  os << obj.getName() << " " << obj.getSurname() << std::endl;
  os << "Books: ";
  if (obj.checkBooks().size() == 0) {
    os << "-";
  } else {
    os << std::endl;
    for (int i = 0; i < obj.checkBooks().size(); i++) {
      os << i + 1 << ": ";
      os << obj.checkBooks()[i].getTitle() << " - ";
      os << obj.checkBooks()[i].getAuthor();
      if (i < obj.checkBooks().size() - 1)
        os << std::endl;
    }
  }
  return os;
}
