#include "../inc/LoginManager.h"

LoginManager::LoginManager(Library &library) { this->library = &library; }
LoginManager::~LoginManager() {}

bool LoginManager::checkData(std::string username, std::string password) {
  auto users = library->getUsers();
  for (auto user : users) {
    if (user->getUsername() == username && user->getPassword() == password) {
      return true;
    }
  }
  return false;
}

User* LoginManager::findUser(std::string username, std::string password) {
  auto users = library->getUsers();
  for (auto user : users) {
    if (user->getUsername() == username && user->getPassword() == password) {
      return user;
    }
  }
  return nullptr;
}

User* LoginManager::loginScreen() {
  std::string username;
  std::string password;
  do {
    /*std::cout << "\033[2J\033[1;1H";*/
    std::cout << "Login: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
  } while (!checkData(username, password));

  return findUser(username, password);
}
