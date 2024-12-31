#ifndef SESSIONMANAGER_H 
#define SESSIONMANAGER_H

#include "Member.h"
#include "User.h"
#include "Library.h"
#include "Utils.h"

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

  bool memberSession(Member* user);
  void memberCheckBooks(Member* user);
  void memberRent(Member* user);
  void memberReturn(Member* user);

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
