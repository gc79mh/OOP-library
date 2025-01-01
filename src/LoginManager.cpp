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

  do {
    u.ClearScreen();
    std::cout << "Login: ";
    username = userInput();
    std::cout << "Password: ";
    password = userInput();

    user = findUser(username, password);

  } while (user == nullptr);

  return user;
}

void LoginManager::registerUser() {
  Utils u;

  std::string username;
  std::string password;

  User *user;
  bool taken = false;

  while (1) {
    u.ClearScreen();

    if (taken) std::cout << "This login is taken! " << std::endl;

    std::cout << "New username: ";
    username = userInput();
    std::cout << "New password: ";
    password = userInput();

    user = findUser(username);

    if(user == nullptr) {
      break;
    } else {
      taken = true; 
    }

  }

  library->addMember(username, password);

}
