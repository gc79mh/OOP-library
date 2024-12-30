#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include "Member.h"

#include <string>
#include <vector>
#include <algorithm>

class Library {
private:
  int lastId = 0;

  std::vector<Book*> books;
  std::vector<User*> users;

public:
  Library();
  ~Library();

  std::vector<Book*> getBooks();
  void addBook(std::string title, std::string author);
  bool removeBook(std::string title, std::string author);
  
  std::vector<User*> getUsers();
  void addUser(std::string username, std::string password);
  bool removeUser(int id);
};

#endif
