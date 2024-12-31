#include "../inc/DebugPrinter.h"
#include "../inc/Library.h"
#include "../inc/LoginManager.h"
#include "../inc/SessionManager.h"

int main() {
  DebugPrinter dp;
  Library lb;
  LoginManager lm(lb);
  SessionManager sm(lb);

  User *currentUser;
  bool sessionContinue;

  do {
    currentUser = lm.loginScreen();
    sessionContinue = sm.startSession(currentUser);

  } while (sessionContinue);

  return 0;
}
