#ifndef MEMBER_H
#define MEMBER_H

#include "../inc/Book.h"
#include <vector>

class Member {
private:
  int memberId;
  std::vector<Book> borrowBooks;

public:
  Member();
  ~Member();

  void borrowBook(Book);
  void returnBook(Book);

  int getMemberId();
  void setMemberId(int);

  friend std::ostream &operator<<(std::ostream &os, const Member &obj);
};

#endif
