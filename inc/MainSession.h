#ifndef SESSION_MANAGER_H 
#define SESSION_MANAGER_H

#include "BossSession.h"
#include "Member.h"
#include "User.h"
#include "Library.h"
#include "Utils.h"
#include "MemberSession.h"
#include "LoginManager.h"
#include "Session.h"
#include "WorkerSession.h"

class MainSession : public Session{
private:
  MemberSession ms;
  WorkerSession ws;
  BossSession bs;

public:
  MainSession (Library *library);
  ~MainSession ();

  void start();
  void startSession(User *user);

};

#endif
