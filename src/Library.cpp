#include "../inc/Library.h"

Library::Library() {
  lastId = 0;
  users.push_back(new Boss(lastId++, "root", "root"));
}

Library::Library(std::string rootUsername, std::string rootPassword) {
  lastId = 0;
  users.push_back(new Boss(lastId++, rootUsername, rootPassword));
}

Library::~Library() {
  for (auto &user : users) {
    delete user;
  }
  for (auto &pair: books) {
    delete pair.first;
  }
}

std::vector<std::pair<Book*, int>> Library::getBooks() {
  return books;
}

void Library::addBook(Book book) {
  Book *newBook = new Book(book.getTitle(), book.getAuthor());
  addBook(newBook); 
}
void Library::addBook(std::string title, std::string author) {
  Book *newBook = new Book(title, author);
  addBook(newBook);  
}
void Library::addBook(Book *book) {
  for (int i = 0 ; i < (int)books.size() ; i++) {
    if (*(books[i].first) == *book) {
      books[i].second++;
      delete book;
      return;
    }
  }

  books.push_back({book, 1});
}

void Library::removeBook(std::string title, std::string author) {
  Book newBook(title, author);
  removeBook(newBook);
}
void Library::removeBook(Book book) {

  for (int i = 0 ; i < (int)books.size() ; i++ ) {
    if (*(books[i].first) == book) {
      if (books[i].second > 1) {
        books[i].second--;
      } else {
        delete books[i].first;
        books.erase(books.begin() + i);
      }
    }
  }
}

std::vector<User *> Library::getUsers() { 
  return users;
}

void Library::removeUser(int id) {
  auto it = std::find_if(users.begin(), users.end(),
                         [id](User *user) { return user->getId() == id; });

  if (it != users.end()) {
    delete *it;
    users.erase(it);
  }
}

void Library::addMember(std::string username, std::string password) {
  users.push_back(new Member(lastId, username, password));
  lastId++;
}

void Library::addWorker(std::string username, std::string password) {
  users.push_back(new Worker(lastId, username, password));
  lastId++;
}
