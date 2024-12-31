#ifndef BOSS_H 
#define BOSS_H

#include "User.h"

class Boss : public User {
private:

public:
  Boss(int id, std::string username, std::string password);
  ~Boss();

  PrivilegeLevel getType() const override;
};

#endif 
