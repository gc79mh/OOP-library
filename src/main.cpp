#include "../inc/DebugPrinter.h"
#include "../inc/Library.h"
#include "../inc/LoginManager.h"
#include "../inc/SessionManager.h"

int main() {
  DebugPrinter dp;
  Library lb;
  LoginManager lm(lb);
  SessionManager sm(lb);

  lb.addMember("1", "1");

  lb.addBook("Ksiona", "Autor");
  lb.addBook("Ksiona2", "Autor");

  User *currentUser;

  while (true) {
    currentUser = lm.loginScreen();
    sm.startSession(currentUser);
  }

  return 0;
}
