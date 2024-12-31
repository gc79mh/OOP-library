#ifndef WORKER_H 
#define WORKER_H

#include "PrivilegeLevel.h"
#include "User.h"

class Worker : public User {
private:

public:
  Worker(int id, std::string username, std::string password);
  ~Worker();

  PrivilegeLevel getType() const override;
};

#endif 
