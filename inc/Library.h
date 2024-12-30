#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include "Member.h"
#include "Worker.h"

#include <string>
#include <vector>
#include <algorithm>

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
  void addBook(Book *book);
  void addBook(std::string title, std::string author);
  void removeBook(Book book);
  void removeBook(Book *book);
  void removeBook(std::string title, std::string author);
  
  std::vector<User*> getUsers();
  void removeUser(int id);
  void addMember(std::string username, std::string password);
  void addWorker(std::string username, std::string password);
};

#endif
