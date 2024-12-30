#include "../inc/Library.h"

Library::Library() {}

Library::~Library() {
  for (auto &user : users) {
    delete user;
  }
}

void Library::addBook(Book book) {}
void Library::addBook(std::string title, std::string author) {}
void Library::removeBook(Book book) {}
void Library::removeBook(std::string title, std::string author) {}

std::vector<User*> Library::getUsers() { return this->users; }
void Library::addUser(User *user) { users.push_back(user); }
void Library::removeUser(int id) {}
User* Library::findUserById(int id) const {
  for (const auto &user : users) {
    if (user->getId() == id) {
      return user;
    }
  }
  return nullptr; // Return nullptr if not found
}
