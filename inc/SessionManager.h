#ifndef SESSION_MANAGER_H 
#define SESSION_MANAGER_H

#include "Member.h"
#include "User.h"
#include "Library.h"
#include "Utils.h"
#include "MemberSession.h"
#include "LoginManager.h"

class SessionManager {
private:
  Library *library;
  Utils u;

  int optionNumber;
  MemberSession ms;

public:
  SessionManager (Library &library);
  ~SessionManager ();

  void menu();
  void startSession(User *user);

  int userInput();

  void displayTitle(std::string title);
  void displayOption(std::string text);


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
