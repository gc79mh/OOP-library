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
  std::cout << "user: " << user->getUsername() << std::endl;
}
void SessionManager::workerSession(User *user) {
  std::cout << "worker " << user->getUsername() << std::endl;
}
void SessionManager::bossSession(User *user) {
  std::cout << "boss " << user->getUsername() << std::endl;
}
