#include "../inc/Book.h"

Book::Book(std::string title, std::string author) {
  this->title = title;
  this->author = author;
}

Book::~Book() {}

std::string Book::getTitle() const {
  return title;
}

std::string Book::getAuthor() const {
  return author;
}

bool operator==(const Book& lhs, const Book& rhs) {
  return (lhs.getAuthor() == rhs.getAuthor() && lhs.getTitle() == rhs.getTitle());
}

std::ostream &operator<<(std::ostream &os, const Book &obj) {
  os << "Title: " + obj.getTitle();
  os << std::endl;
  os << "Author: " + obj.getAuthor();
  return os;
};
