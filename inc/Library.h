#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include <vector>

class Library {
private:
  std::vector<Book> books;
  std::vector<User*> users;

public:
  Library();
  ~Library();

  void addBook(Book book);
  void addBook(std::string title, std::string author);
  void removeBook(Book book);
  void removeBook(std::string title, std::string author);

  std::vector<User*> getUsers();
  void addUser(User* user);
  void removeUser(int id);
  User *findUserById(int id) const;
};

#endif
