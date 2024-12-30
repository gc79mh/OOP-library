#ifndef WORKER_H 
#define WORKER_H

#include "User.h"

#include <string>

class Worker : public User {
private:

public:
  Worker(int id, std::string username, std::string password);

  std::string getType() const override;
};

#endif 
