#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
  std::string title;
  std::string author;
  bool isAvailable;

public:
  Book();
  Book(std::string title, std::string author);
  Book(std::string title, std::string author, bool isAvailable);
  ~Book();

  bool checkAvailability();
  void changeAvailability();

  std::string getTitle();
  void setTitle(std::string title);

  std::string getAuthor();
  void setAuthor(std::string author);

  friend std::ostream &operator<<(std::ostream &os, const Book &obj);
};

#endif
