#ifndef MEMBER_H
#define MEMBER_H

#include "Book.h"
#include "User.h"

#include <vector>

class Member : public User {
private:
  std::vector<Book> borrowedBooks;

public:
  Member(int id, std::string username, std::string password);

  std::vector<Book> checkBooks() const;
  void borrowBook(Book book);
  void returnBook(Book book);
};

#endif
