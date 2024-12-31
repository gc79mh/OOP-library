#ifndef SESSIONMANAGER_H 
#define SESSIONMANAGER_H

#include "User.h"
#include "Library.h"
#include "Utils.h"

class SessionManager {
private:
  Library *library;

public:
  SessionManager (Library &library);
  ~SessionManager ();

  void startSession(User* user);

  void memberSession(User* user);
  void workerSession(User* user);
  void bossSession(User* user);

};

#endif
