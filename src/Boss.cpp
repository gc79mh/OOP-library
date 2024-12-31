#include "../inc/Boss.h"

Boss::Boss(int id, std::string username, std::string password)
    : User(id, username, password) {}

Boss::~Boss() {}

PrivilegeLevel Boss::getType() const {
  return PrivilegeLevel::BOSS;
}
