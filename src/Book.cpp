#include "../inc/Book.h"
#include <memory>

Book::Book() {
  this->title = "Unknown";
  this->author = "Unknown";
}

Book::Book(std::string title, std::string author) {
  this->title = title;
  this->author = author;
}

Book::~Book() {}

bool Book::checkAvailability() {
  return isAvailable;
}

void Book::changeAvailability() {
  this->isAvailable = !isAvailable;
}

std::string Book::getTitle() {
  return title;
}

void Book::setTitle(std::string title) {
  this->title = title;
}

std::string Book::getAuthor() {
  return author;
}

void Book::setAuthor(std::string author) {
  this->author = author;
}
