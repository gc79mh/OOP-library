#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include "Member.h"

#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Library {
private:
  int lastId = 0;

  std::vector<Book*> books;
  std::vector<int> booksCount;
  std::vector<User*> users;

public:
  Library();
  ~Library();

  std::vector<Book*> getBooks();
  void addBook(std::string title, std::string author);
  void removeBook(std::string title, std::string author);
  
  std::vector<User*> getUsers();
  void addUser(std::string username, std::string password);
  void removeUser(int id);
};

#endif
