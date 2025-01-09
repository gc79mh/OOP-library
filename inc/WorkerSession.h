#ifndef WORKER_SESSION_H 
#define WORKER_SESSION_H

#include "Member.h"
#include "Session.h"
#include "User.h"
#include "Library.h"
#include "Utils.h"
#include "Worker.h"

#include <cstdlib>
#include <sstream>

class WorkerSession : public Session{
public:
  WorkerSession (Library *library);
  ~WorkerSession ();
  
  void start();

  void addBook();
  void removeBook();
  void displayUsers();

};

#endif
