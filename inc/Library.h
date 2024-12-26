#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <iostream>
#include <vector>

class Library {
private:
  std::vector<Book> books;
  std::vector<Member> members;

public:
  Library();
  ~Library();

  void addBook(Book book);
  void removeBook(Book book);

  void registerMember(Member member);
  void removeMember(Member member);

  friend std::ostream &operator<<(std::ostream &os, const Library &obj);
};

#endif 
