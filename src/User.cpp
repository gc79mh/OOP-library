#include "../inc/User.h"

User::User(int id, std::string username, std::string password) {
  this->id = id;
  this->username = username;
  this->password = password;
}

User::~User() {}

int User::getId() const {
    return id;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

bool User::operator==(const User& other) const {
    return this->id == other.id;
}
