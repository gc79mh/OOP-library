#ifndef LOGINMANAGER_H 
#define LOGINMANAGER_H 

#include "User.h"
#include "Library.h"
#include "Utils.h"

#include <sstream>

class LoginManager {
private:
  Library *library;

public:
  LoginManager (Library &library);
  ~LoginManager ();
  
  User* loginUser();
  void registerUser();
  
  std::string userInput();
  User* findUser(std::string username, std::string password); 
  User* findUser(std::string username); 
};

#endif
