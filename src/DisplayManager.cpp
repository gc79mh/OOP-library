#include <iostream>
#include "../inc/Member.h"
#include "../inc/Book.h"

std::ostream &operator<<(std::ostream &os, const Member &obj) {
  os << "Member ID: ";
  os << obj.getId() << std::endl;
  os << "Member Name: ";
  os << obj.getUsername() << std::endl;
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

std::ostream &operator<<(std::ostream &os, const Book &obj) {
  os << "Title: " + obj.getTitle();
  os << std::endl;
  os << "Author: " + obj.getAuthor();
  return os;
};
