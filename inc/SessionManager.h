#ifndef SESSION_MANAGER_H 
#define SESSION_MANAGER_H

#include "Member.h"
#include "User.h"
#include "Library.h"
#include "Utils.h"
#include "MemberSession.h"

class SessionManager {
private:
  Library *library;
  Utils u;

public:
  SessionManager (Library &library);
  ~SessionManager ();

  bool startSession(User* user);

  void displayBooks();
  void displayUsers();

  bool workerSession(Worker* worker);

  void addMember();
  void removeMember();
  void addBook();
  void removeBook();

  bool bossSession(Boss* boss);
  
  void displayWorkers();
  void addWorker();
  void removeWorker();

};

#endif
