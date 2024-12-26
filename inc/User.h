#ifndef USER_H
#define USER_H

#include <string>
class User {
private:
  std::string name;
  std::string surname;
  std::string login;
  std::string password;

public:
  User();
  ~User();

  
};

#endif 
