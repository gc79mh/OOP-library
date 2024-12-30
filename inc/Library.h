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

  std::vector<std::pair<Book*, int>> books;
  std::vector<User*> users;

public:
  Library();
  ~Library();
  
  std::vector<std::pair<Book*, int>> getBooks();
  void addBook(Book book);
  void removeBook(Book book);
  void addBook(std::string title, std::string author);
  void removeBook(std::string title, std::string author);
  
  std::vector<User*> getUsers();
  void addUser(std::string username, std::string password);
  void removeUser(int id);
};

#endif
