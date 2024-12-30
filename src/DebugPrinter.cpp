#include "../inc/DebugPrinter.h"

void DebugPrinter::Print(Book book) {
  std::cout << "Title: " + book.getTitle();
  std::cout << std::endl;
  std::cout << "Author: " + book.getAuthor();
}

std::ostream &operator<<(std::ostream &os, const Member &obj) {
  std::cout << "Member ID: ";
  std::cout << obj.getId() << std::endl;
  std::cout << "Member Name: ";
  std::cout << obj.getUsername() << std::endl;
  std::cout << "Books: ";
  if (obj.checkBooks().size() == 0) {
    std::cout << "-";
  } else {
    std::cout << std::endl;
    for (int i = 0; i < obj.checkBooks().size(); i++) {
      std::cout << i + 1 << ": ";
      std::cout << obj.checkBooks()[i].getTitle() << " - ";
      std::cout << obj.checkBooks()[i].getAuthor();
      if (i < obj.checkBooks().size() - 1)
        std::cout << std::endl;
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
