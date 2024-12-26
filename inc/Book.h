#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
  std::string title;
  std::string author;

public:
  Book(std::string title, std::string author);
  ~Book();

  std::string getTitle() const;
  std::string getAuthor() const;

  friend std::ostream &operator<<(std::ostream &os, const Book &obj);
  friend bool operator==(const Book& lhs, const Book& rhs);
};

#endif
