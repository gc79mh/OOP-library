#include "../inc/WorkerSession.h"

WorkerSession::WorkerSession(Library *library) : Session(library) {
  color = "Green";
}

WorkerSession::~WorkerSession() {}

void WorkerSession::start() {
  while (1) {
    displayLibrary();
    displayOption("See all books");
    displayOption("Add a book");
    displayOption("Remove a book");
    displaySeparator();
    displayOption("See all users");
    displaySeparator();
    displayOption("Log out");

    int pick = userInput();

    if (pick == 1) {
      displayLibrary();
      displayTitle("Books in the library:");
      displayLibraryBooks();
      u.Wait();

    } else if (pick == 2) {
      displayLibrary();
      addBook();

    } else if (pick == 3) {
      displayLibrary();
      removeBook();

    } else if (pick == 4) {
      displayLibrary();
      displayUsers(); 
      u.Wait();

    } else if (pick == 5) {
      break;
    }
  }
}

void WorkerSession::addBook() {

  std::string title;
  std::string author;
  int count;

  std::cout << "Title: ";
  getline(std::cin, title);
  std::cout << "Author: ";
  getline(std::cin, author);
  std::cout << "Count";
  count = userInput();

  for (int i = 0; i < count; i++) {
    library->addBook(title, author);
  }
}

void WorkerSession::removeBook() {

  int count, option;

  displayLibraryBooks();
  
  option = userInput();
  std::cout << "Count";
  count = userInput();

  auto books = library->getBooks();
  if (count > books[option - 1].second)
    count = books[option - 1].second;
  for (int i = 0; i < count; i++) {
    library->removeBook(books[option - 1].first->getTitle(),
                        books[option - 1].first->getAuthor());
  }
}

void WorkerSession::displayUsers() {
  auto users = library->getUsers();
  displayTitle("Users:");
  for (auto user : users) {
    if (user->getType() == UserType::USER) {
      Member *member = dynamic_cast<Member*>(user);
      std::cout << user->getUsername() << ": " << u.Color("Red") << "User" << u.Color("Base") << std::endl;

      auto books = member->getBooks();
      for (auto book : books) {
        std::cout << " " << u.Color("Blue") << book.getTitle() << u.Color("Base") << " - " << book.getAuthor() << std::endl;
      }

    } else if (user->getType() == UserType::WORKER) {
      std::cout << user->getUsername() << ": " << u.Color("Red") << "Librarian" << u.Color("Base") << std::endl;

    } else if (user->getType() == UserType::BOSS) {
      std::cout << user->getUsername() << ": " << u.Color("Red") << "Boss" << u.Color("Base") << std::endl;

    }
  }
}
