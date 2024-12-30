#ifndef WORKER_H 
#define WORKER_H

#include "User.h"

class Worker : public User {
private:

public:
  Worker(int id, std::string username, std::string password);
  ~Worker();

  std::string getType() const override;
};

#endif 
