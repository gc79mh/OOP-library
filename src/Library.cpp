#include "../inc/Library.h"

Library::Library() {}

Library::~Library() {
  for (auto &user : users) {
    delete user;
  }
  users.clear();

  for (auto &book : books) {
    delete book;
  }
  books.clear();
}

std::vector<Book *> Library::getBooks() { return books; }

void Library::addBook(std::string title, std::string author) {
  Book *book = new Book(title, author);
  
  for (int i = 0 ; i < books.size() ; i++) {
    if (*books[i] == *book) {
      booksCount[i]++;
      return;
    }
  }

  books.push_back(book);
  booksCount.push_back(1);
}

void Library::removeBook(std::string title, std::string author) {
  Book *book = new Book(title, author);

  for (int i = 0 ; i < books.size() ; i++ ) {
    if (*books[i] == *book) {
      books.erase(books.begin() + i);
      booksCount.erase(booksCount.begin() + i);
    }
  }

}

std::vector<User *> Library::getUsers() { return this->users; }

void Library::addUser(std::string username, std::string password) {
  users.push_back(new Member(lastId, username, password));
  lastId++;
}

void Library::removeUser(int id) {
  auto it = std::find_if(users.begin(), users.end(),
                         [id](User *user) { return user->getId() == id; });

  if (it != users.end()) {
    delete *it;
    users.erase(it);
  }
}
