#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <vector>
#include "../inc/Book.h"

class Member {
private:
  int memberId;
  std::vector<Book> borrowedBooks;

public:
  Member(int memberId);
  ~Member();

  std::vector<Book> checkBooks();
  void borrowBook(Book book);
  void returnBook(Book book);
  
  int getMemberId() const;

  friend bool operator==(const Member& lhs, const Member& rhs);
  friend std::ostream &operator<<(std::ostream &os, const Member &obj);
};

#endif
