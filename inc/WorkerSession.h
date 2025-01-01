#ifndef WORKER_SESSION_H 
#define WORKER_SESSION_H

#include "Member.h"
#include "User.h"
#include "Library.h"
#include "Utils.h"

#include <cstdlib>
#include <sstream>

class WorkerSession {
private:
  Library *library;
  Utils u;

public:
  WorkerSession (Library &library);
  ~WorkerSession ();
  
  void workerSession(Member* user);

  int userInput();

  void displayMenu();
  void displayTitle(std::string title);
  void displayLibraryBooks();
  void displayMemberBooks(Member* user);

  void memberRent(Member* user);
  void memberReturn(Member* user);

};

#endif
