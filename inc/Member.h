#ifndef MEMBER_H
#define MEMBER_H

#include "../inc/Book.h"
#include <vector>

class Member {
private:
  int memberId;
  std::vector<Book> borrowedBooks;

public:
  Member(int memberId);
  ~Member();

  void borrowBook(Book book);
  void returnBook(Book book);

  int getMemberId();

  friend std::ostream &operator<<(std::ostream &os, const Member &obj);
};

#endif
