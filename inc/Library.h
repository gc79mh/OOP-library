#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include <iostream>
#include <string>
#include <vector>

class Library {
private:
  std::vector<Book> books;
  std::vector<Member> members;

public:
  Library();
  ~Library();

  void addBook(Book book);
  void addBook(std::string title, std::string author);
  void removeBook(Book book);
  void removeBook(std::string title, std::string author);
  
  std::vector<Member> showMembers();
  void registerNewMember(std::string name, std::string surname);
  void removeMember(int memberId);

  friend std::ostream &operator<<(std::ostream &os, const Library &obj);
};

#endif 
