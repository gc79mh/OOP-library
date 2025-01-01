#ifndef SESSION_MANAGER_H 
#define SESSION_MANAGER_H

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

public:
  MainSession (Library *library);
  ~MainSession ();

  void start();
  void startSession(User *user);

  bool bossSession(Boss* boss);
  
  void displayWorkers();
  void addWorker();
  void removeWorker();

};

#endif
