#include "../inc/MainSession.h"
#include <cstdio>

MainSession::MainSession(Library *library)
    : Session(library), ms(library), ws(library), bs(library) {
  color = "Red";
}

MainSession::~MainSession() {}

void MainSession::start() {
  LoginManager lm(*library);

  while (1) {
    displayLibrary();
    displayOption("Login");
    displayOption("Register");
    displayOption("Exit");

    int pick = userInput();

    if (pick == 1) {
      displayLibrary();
      User *user = lm.loginUser();
      if (user != nullptr)
        startSession(user);

    } else if (pick == 2) {
      bool taken = false;
      do {
        displayLibrary();
        if (taken)
          std::cout << "This login is taken! " << std::endl;
        taken = lm.registerUser();
      } while (taken);
    } else if (pick == 3) {
      break;
    }
  }
}

void MainSession::startSession(User *user) {
  UserType type = user->getType();

  if (type == UserType::USER) {
    Member *member = dynamic_cast<Member *>(user);
    ms.start(member);
  }
  if (type == UserType::WORKER) {
    ws.start();
  }
  if (type == UserType::BOSS) {
    bs.start();
  }
}

