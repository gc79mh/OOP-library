#include "../inc/SessionManager.h"

SessionManager::SessionManager(Library &library) { 
  this->library = &library;
}

SessionManager::~SessionManager() {}

void SessionManager::startSession(User *user) {
  UserType type = user->getType();
  switch (type) {
  case UserType::USER:
    memberSession(user);
    break;
  case UserType::WORKER:
    workerSession(user);
    break;
  case UserType::BOSS:
    bossSession(user);
    break;
  }
}

void SessionManager::memberSession(User *user) {
  Utils u;
  u.ClearScreen();

  std::cout << "Hi " << user->getUsername() << std::endl;
  std::cout << "Choose an option: " << std::endl;
  std::cout << "1. Rent a new book" << std::endl;
  std::cout << "2. Give back book" << std::endl;
  std::cout << "3. Exit" << std::endl;
  std::cout << " " << std::endl;
  
  int option;
  std::cout << ": ";
  std::cin >> option;
}
void SessionManager::workerSession(User *user) {
  std::cout << "worker " << user->getUsername() << std::endl;
}
void SessionManager::bossSession(User *user) {
  std::cout << "boss " << user->getUsername() << std::endl;
}
