#include "../inc/SessionManager.h"

SessionManager::SessionManager(Library &library) { this->library = &library; }

SessionManager::~SessionManager() {}

bool SessionManager::startSession(User *user) {
  Utils u;
  u.ClearScreen();

  UserType type = user->getType();

  bool sessionContinue;

  switch (type) {
  case UserType::USER:
    sessionContinue = memberSession(user);
    return sessionContinue;
    break;
  case UserType::WORKER:
    sessionContinue = workerSession(user);
    return sessionContinue;
    break;
  case UserType::BOSS:
    sessionContinue = bossSession(user);
    return sessionContinue;
    break;
  }

  return false;
}

bool SessionManager::memberSession(User *user) {
  Utils u;

  std::cout << "Hi " << user->getUsername() << std::endl;
  std::cout << "Choose an option:   " << std::endl;
  std::cout << u.Color("Red") << "1. " << u.Color("Base") << "Rent a new book"
            << std::endl;
  std::cout << u.Color("Red") << "2. " << u.Color("Base") << "Return a book  "
            << std::endl;
  std::cout << u.Color("Red") << "3. " << u.Color("Base") << "Log out        "
            << std::endl;
  std::cout << u.Color("Red") << "4. " << u.Color("Base") << "Exit           "
            << std::endl;

  int option;
  std::cout << ": ";
  std::cin >> option;

  switch (option) {
  case 1:
    /*memberRent();*/
    break;
  case 2:
    /*memberReturn();*/
    break;
  case 3:
    return true;
    break;
  case 4:
    break;
  }
  return false;
}
bool SessionManager::workerSession(User *user) {
  std::cout << "worker " << user->getUsername() << std::endl;
  return 0;
}
bool SessionManager::bossSession(User *user) {
  std::cout << "boss " << user->getUsername() << std::endl;
  return 0;
}
