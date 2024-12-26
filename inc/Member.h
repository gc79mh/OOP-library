#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <vector>
#include "../inc/Book.h"

class Member {
private:
  int memberId;
  std::string name;
  std::string surname;
  std::vector<Book> borrowedBooks;

public:
  Member(int memberId, std::string name, std::string surname);
  ~Member();
  
  int getMemberId() const;
  std::string getName() const;
  std::string getSurname() const;

  std::vector<Book> checkBooks() const;
  void borrowBook(Book book);
  void returnBook(Book book);

  friend bool operator==(const Member& lhs, const Member& rhs);
  friend std::ostream &operator<<(std::ostream &os, const Member &obj);
};

#endif
