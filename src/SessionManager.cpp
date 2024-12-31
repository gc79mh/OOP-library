#include "../inc/SessionManager.h"
#include <cstdio>

SessionManager::SessionManager(Library &library) { this->library = &library; }

SessionManager::~SessionManager() {}

bool SessionManager::startSession(User *user) {
  u.ClearScreen();

  UserType type = user->getType();

  bool sessionContinue;

  Member *member;
  Worker *worker;
  Boss *boss;

  switch (type) {
  case UserType::USER:
    member = dynamic_cast<Member *>(user);
    sessionContinue = memberSession(member);
    return sessionContinue;
    break;
  case UserType::WORKER:
    worker = dynamic_cast<Worker *>(user);
    sessionContinue = workerSession(worker);
    return sessionContinue;
    break;
  case UserType::BOSS:
    boss = dynamic_cast<Boss *>(user);
    sessionContinue = bossSession(boss);
    return sessionContinue;
    break;
  }

  return false;
}

bool SessionManager::memberSession(Member *member) {
  while (1) {
    u.ClearScreen();
    /*std::cout << u.Color("Gray") << "Hi " << member->getUsername() <<
     * u.Color("Base") << std::endl;*/
    std::cout << u.Color("Yellow") << "Choose an option:   " << u.Color("Base")
              << std::endl;
    std::cout << u.Color("Red") << "1. " << u.Color("Base") << "See all books  "
              << std::endl;
    std::cout << u.Color("Red") << "2. " << u.Color("Base") << "See my books   "
              << std::endl;
    std::cout << u.Color("Red") << "3. " << u.Color("Base") << "Rent a new book"
              << std::endl;
    std::cout << u.Color("Red") << "4. " << u.Color("Base") << "Return a book  "
              << std::endl;
    std::cout << u.Color("Red") << "5. " << u.Color("Base") << "Log out        "
              << std::endl;
    std::cout << u.Color("Red") << "6. " << u.Color("Base") << "Exit           "
              << std::endl;

    char option;
    std::cout << ": ";
    std::cin >> option;

    switch (option) {
    case '1':
      u.ClearScreen();
      std::cout << u.Color("Yellow")
                << "Books in the library: " << u.Color("Base") << std::endl;
      displayBooks();
      u.Wait();
      break;
    case '2':
      u.ClearScreen();
      std::cout << u.Color("Yellow") << "Your books: " << u.Color("Base")
                << std::endl;
      memberCheckBooks(member);
      u.Wait();
      break;
    case '3':
      memberRent(member);
      break;
    case '4':
      memberReturn(member);
      break;
    case '5':
      return true;
      break;
    case '6':
      return false;
      break;
    }
  }
  std::cin.ignore(100000, '\n');

  return false;
}
void SessionManager::displayBooks() {
  auto books = library->getBooks();
  for (int i = 0; i < (int)books.size(); i++) {
    auto book = books[i];
    std::cout << " " << i + 1 << ". ";
    std::cout << u.Color("Blue") << book.first->getTitle() << u.Color("Base");
    std::cout << " - " << book.first->getAuthor();
    std::cout << u.Color("Gray") << " x" << book.second << u.Color("Base");
    std::cout << std::endl;
  }
}
void SessionManager::displayUsers() {
  auto users = library->getUsers();
  for (auto user : users) {
    if (user->getType() == UserType::USER) {
      std::cout << " ID: " << u.Color("Blue") << user->getId()
                << u.Color("Base") << " - Username: ";
      std::cout << u.Color("Blue") << user->getUsername() << u.Color("Base");
      std::cout << std::endl;
    }
  }
}

void SessionManager::memberCheckBooks(Member *member) {
  auto books = member->checkBooks();
  for (int i = 0; i < (int)books.size(); i++) {
    auto book = books[i];
    std::cout << " " << i + 1 << ". ";
    std::cout << u.Color("Blue") << book.getTitle() << u.Color("Base");
    std::cout << " - " << book.getAuthor();
    std::cout << std::endl;
  }
}
void SessionManager::memberRent(Member *member) {
  u.ClearScreen();

  std::cout << u.Color("Yellow") << "Pick a book rent: " << u.Color("Base")
            << std::endl;

  displayBooks();

  std::cout << ": ";
  int option;
  std::cin >> option;

  auto books = library->getBooks();
  if (option - 1 >= (int)books.size() || option < 1)
    return;
  auto book = *books[option - 1].first;

  member->borrowBook(book);
  library->removeBook(book);
}

void SessionManager::memberReturn(Member *member) {
  u.ClearScreen();

  std::cout << u.Color("Yellow") << "Pick a book to return: " << u.Color("Base")
            << std::endl;

  memberCheckBooks(member);

  std::cout << ": ";
  int option;
  std::cin >> option;

  auto books = member->checkBooks();
  if (option - 1 >= (int)books.size() || option < 1)
    return;
  auto book = books[option - 1];

  member->returnBook(book);
  library->addBook(book);
}

bool SessionManager::workerSession(Worker *worker) {
  while (1) {
    u.ClearScreen();
    std::string s = worker->getUsername();

    std::cout << u.Color("Green") << "Choose an option:   " << u.Color("Base")
              << std::endl;
    std::cout << u.Color("Red") << "1. " << u.Color("Base") << "See all books  "
              << std::endl;
    std::cout << u.Color("Red") << "2. " << u.Color("Base") << "Add book       "
              << std::endl;
    std::cout << u.Color("Red") << "3. " << u.Color("Base") << "Remove book    "
              << std::endl;
    std::cout << u.Color("Red") << "4. " << u.Color("Base") << "See all users  "
              << std::endl;
    std::cout << u.Color("Red") << "5. " << u.Color("Base") << "Add user       "
              << std::endl;
    std::cout << u.Color("Red") << "6. " << u.Color("Base") << "Remove user    "
              << std::endl;
    std::cout << u.Color("Red") << "7. " << u.Color("Base") << "Log out        "
              << std::endl;
    std::cout << u.Color("Red") << "8. " << u.Color("Base") << "Exit           "
              << std::endl;

    char option;
    std::cout << ": ";
    std::cin >> option;

    switch (option) {
    case '1':
      u.ClearScreen();
      std::cout << u.Color("Green")
                << "Books in the library: " << u.Color("Base") << std::endl;
      displayBooks();
      u.Wait();
      break;
    case '2':
      addBook();
      break;
    case '3':
      removeBook();
      break;
    case '4':
      u.ClearScreen();
      std::cout << u.Color("Green") << "Registered users: " << u.Color("Base")
                << std::endl;
      displayUsers();
      u.Wait();
      break;
    case '5':
      addMember();
      break;
    case '6':
      removeMember();
      break;
    case '7':
      return true;
      break;
    case '8':
      return false;
      break;
    }
  }
  std::cin.ignore(100000, '\n');

  return false;
}

void SessionManager::addBook() {
  u.ClearScreen();
  
  std::string title;
  std::string author;
  int count;

  std::cout << u.Color("Green") << "Add a book: " << u.Color("Base") << std::endl;
  std::cout << "Title: ";
  std::cin.ignore();
  getline(std::cin, title);
  std::cout << "Author: ";
  std::cin.ignore();
  getline(std::cin, author);
  std::cout << "Count: ";
  std::cin >> count;

  for (int i = 0 ; i < count ; i++) {
    library->addBook(title, author);
  }

}
void SessionManager::removeBook() {
  u.ClearScreen();
  
  int count, option;

  std::cout << u.Color("Green") << "Remove a book: " << u.Color("Base") << std::endl;
  
  displayBooks();
  
  std::cout << ": ";
  std::cin >> option;
  std::cout << "Count: ";
  std::cin >> count;
  
  auto books = library->getBooks();
  if (count > books[option - 1].second) count = books[option - 1].second;
  for (int i = 0 ; i < count ; i++) {
    library->removeBook(books[option-1].first->getTitle(),books[option-1].first->getAuthor());
  }

}
void SessionManager::addMember() {
  u.ClearScreen();
  
  std::string username;
  std::string password;

  std::cout << u.Color("Green") << "Add member: " << u.Color("Base") << std::endl;
  std::cout << "username: ";
  std::cin >> username;
  std::cout << "password: ";
  std::cin >> password;

  library->addMember(username, password);

}
void SessionManager::removeMember() {
  u.ClearScreen();
  
  int id;

  std::cout << u.Color("Green") << "Remove member: " << u.Color("Base") << std::endl;
  
  displayUsers();
  
  std::cout << "ID: ";
  std::cin >> id;
  
  library->removeUser(id);

}

bool SessionManager::bossSession(Boss *boss) {
  while (1) {
    u.ClearScreen();
    std::string es = boss->getUsername();

    std::cout << u.Color("Pink") << "Choose an option:   " << u.Color("Base")
              << std::endl;
    std::cout << u.Color("Red") << "1. " << u.Color("Base") << "See Employees"
              << std::endl;
    std::cout << u.Color("Red") << "2. " << u.Color("Base") << "Add Librarian"
              << std::endl;
    std::cout << u.Color("Red") << "3. " << u.Color("Base") << "Remove Librarian   "
              << std::endl;
    std::cout << u.Color("Red") << "4. " << u.Color("Base") << "Log out        "
              << std::endl;
    std::cout << u.Color("Red") << "5. " << u.Color("Base") << "Exit           "
              << std::endl;

    char option;
    std::cout << ": ";
    std::cin >> option;

    switch (option) {
    case '1':
      u.ClearScreen();
      std::cout << u.Color("Pink")
                << "Employees: " << u.Color("Base") << std::endl;
      displayWorkers();
      u.Wait();
      break;
    case '2':
      addWorker();
      break;
    case '3':
      removeWorker();
      break;
    case '4':
      return true;
      break;
    case '5':
      return false;
      break;
    }
  }
  std::cin.ignore(100000, '\n');

  return false;
}
void SessionManager::displayWorkers() {
  auto users = library->getUsers();
  for (auto user : users) {
    if (user->getType() == UserType::WORKER) {
      std::cout << " ID: " << u.Color("Blue") << user->getId()
                << u.Color("Base") << " - Username: ";
      std::cout << u.Color("Blue") << user->getUsername() << u.Color("Base");
      std::cout << std::endl;
    }
  }
}
void SessionManager::addWorker() {
  u.ClearScreen();
  
  std::string username;
  std::string password;

  std::cout << u.Color("Pink") << "Add member: " << u.Color("Base") << std::endl;
  std::cout << "username: ";
  std::cin >> username;
  std::cout << "password: ";
  std::cin >> password;

  library->addWorker(username, password);

}
void SessionManager::removeWorker() {
  u.ClearScreen();
  
  int id;

  std::cout << u.Color("Pink") << "Remove member: " << u.Color("Base") << std::endl;
 
  displayWorkers();
  
  std::cout << "ID: ";
  std::cin >> id;
  
  library->removeUser(id);

}
