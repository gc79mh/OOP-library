#include "../inc/Library.h"

Library::Library() {}

Library::~Library() {
  for (auto &user : users) {
    delete user;
  }
  users.clear();

  for (auto &pair: books) {
    delete pair.first;
  }
  books.clear();
}

std::vector<std::pair<Book*, int>> Library::getBooks() { return books; }

void Library::addBook(Book book) {
  Book *newBook = new Book(book.getTitle(), book.getAuthor());
  
  for (int i = 0 ; i < (int)books.size() ; i++) {
    if (*(books[i].first) == *newBook) {
      books[i].second++;
      delete newBook;
      return;
    }
  }

  books.push_back({newBook, 1});
}
void Library::addBook(std::string title, std::string author) {
  Book *book = new Book(title, author);
  
  for (int i = 0 ; i < (int)books.size() ; i++) {
    if (*(books[i].first) == *book) {
      books[i].second++;
      delete book;
      return;
    }
  }

  books.push_back({book, 1});
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
void Library::removeBook(std::string title, std::string author) {
  Book *book = new Book(title, author);

  for (int i = 0 ; i < (int)books.size() ; i++ ) {
    if (*(books[i].first) == *book) {
      if (books[i].second > 1) {
        books[i].second--;
      } else {
        delete books[i].first;
        books.erase(books.begin() + i);
      }
    }
  }

  delete book;
}

std::vector<User *> Library::getUsers() { return this->users; }

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
