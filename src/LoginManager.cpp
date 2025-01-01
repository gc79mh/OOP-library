#include "../inc/LoginManager.h"

LoginManager::LoginManager(Library &library) { this->library = &library; }
LoginManager::~LoginManager() {}

User *LoginManager::findUser(std::string username, std::string password) {
  auto users = library->getUsers();
  for (auto user : users) {
    if (user->getUsername() == username && user->getPassword() == password) {
      return user;
    }
  }
  return nullptr;
}

User *LoginManager::findUser(std::string username) {
  auto users = library->getUsers();
  for (auto user : users) {
    if (user->getUsername() == username) {
      return user;
    }
  }
  return nullptr;
}

std::string LoginManager::userInput() {
  std::string rawInput;

  std::getline(std::cin, rawInput);

  std::istringstream stream(rawInput);

  std::string firstWord;
  stream >> firstWord;

  return firstWord;
}

User *LoginManager::loginUser() {
  Utils u;

  std::string username;
  std::string password;

  User *user;

  std::cout << "Login: ";
  username = userInput();
  std::cout << "Password: ";
  password = userInput();

  user = findUser(username, password);

  return user;
}

bool LoginManager::registerUser() {
  Utils u;

  std::string username;
  std::string password;

  User *user;
  bool taken = false;

  std::cout << "New username: ";
  username = userInput();
  std::cout << "New password: ";
  password = userInput();

  user = findUser(username);

  if (user == nullptr) {
    library->addMember(username, password);
  } else {
    taken = true;
  }
  return taken;
}
