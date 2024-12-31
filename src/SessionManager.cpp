#include "../inc/SessionManager.h"

SessionManager::SessionManager(Library &library) {
  this->library = &library;
}

SessionManager::~SessionManager() {}

void SessionManager::startSession(User *user) {
}

void SessionManager::memberSession(User *user) {}
void SessionManager::workerSession(User *user) {}
void SessionManager::bossSession(User *user) {}
