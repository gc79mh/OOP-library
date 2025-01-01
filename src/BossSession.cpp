#include "../inc/BossSession.h"

BossSession::BossSession(Library *library) : Session(library) {
  color = "Blue";
}

BossSession::~BossSession() {}

void BossSession::start() {
  while (1) {
    displayLibrary();
    displayOption("Hire Librarian");
    displaySeparator();
    displayOption("Log out");

    int pick = userInput();

    if (pick == 1) {
      displayLibrary();
      addWorker();

    } else if (pick == 2) {
      break;

    } 
  }
}

void BossSession::addWorker() {
  Utils u;

  std::string username;
  std::string password;
  bool taken = false;

  do {
    displayLibrary();
    if (taken) 
          std::cout << "This login is taken! " << std::endl;

    std::cout << "New username: ";
    std::cin >> username;
    std::cout << "New password: ";
    std::cin >> password;
    
    taken = false;

    auto users = library->getUsers();
    for (auto user : users) {
      if (user->getUsername() == username) {
        taken = true;
      }
    }
  } while(taken);

  library->addWorker(username, password);
}
