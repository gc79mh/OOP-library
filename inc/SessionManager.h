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

  bool startSession(User* user);

  bool memberSession(User* user);
  bool workerSession(User* user);
  bool bossSession(User* user);

};

#endif
