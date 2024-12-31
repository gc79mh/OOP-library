#ifndef USER_H
#define USER_H

#include "PrivilegeLevel.h"

#include <string>

class User {
protected:
  int id;
  std::string username;
  std::string password;

public:
  User(int id, std::string username, std::string password);
  virtual ~User() = 0;

  int getId() const;
  std::string getUsername() const;
  std::string getPassword() const;
  virtual PrivilegeLevel getType() const = 0;

  bool operator==(const User &other) const;
};

#endif
