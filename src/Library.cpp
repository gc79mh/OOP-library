#include "../inc/Library.h"

Library::Library() {}

Library::~Library() {
  for (auto &user : users) {
    delete user;
    user = nullptr;
  }

  for (auto &book : books) {
    delete book;
    book = nullptr;
  }
}

std::vector<Book *> Library::getBooks() { return books; }

void Library::addBook(std::string title, std::string author) {
  books.push_back(new Book(title, author));
}

bool Library::removeBook(std::string title, std::string author) {
  auto it =
      std::find_if(books.begin(), books.end(), [title, author](Book *book) {
        return (book->getTitle() == title && book->getAuthor() == author);
      });

  if (it != books.end()) {
    delete *it;
    *it = nullptr;
    books.erase(it);
    return true;
  }

  return false;
}

std::vector<User *> Library::getUsers() { return this->users; }

void Library::addUser(std::string username, std::string password) {
  users.push_back(new Member(lastId, username, password));
  lastId++;
}

bool Library::removeUser(int id) {
  auto it = std::find_if(users.begin(), users.end(),
                         [id](User *user) { return user->getId() == id; });

  if (it != users.end()) {
    delete *it;
    *it = nullptr;
    users.erase(it);
    return true;
  }

  return false;
}
