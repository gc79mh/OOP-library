#ifndef LOGINMANAGER_H 
#define LOGINMANAGER_H 

#include "User.h"
#include "Library.h"

#include <iostream>

class LoginManager {
private:
  Library *library;

public:
  LoginManager (Library &library);
  ~LoginManager ();
  

  bool checkData(std::string username, std::string password); 
  User* findUser(std::string username, std::string password); 
  User* loginScreen();
};

#endif
