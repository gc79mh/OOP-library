#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
  int id;
  std::string username;
  std::string password;

protected:
  User(int id, std::string username, std::string password);

public:
  virtual ~User() = 0;

  int getId() const;
  std::string getUsername() const;
  std::string getPassword() const;
  virtual std::string getType() const = 0;

  bool operator==(const User &other) const;
};

#endif
