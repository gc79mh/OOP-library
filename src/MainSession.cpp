#include "../inc/MainSession.h"
#include <cstdio>

MainSession::MainSession(Library *library)
    : Session(library), ms(library), ws(library) {
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
    Boss *boss = dynamic_cast<Boss *>(user);
    bossSession(boss);
  }
}

bool MainSession::bossSession(Boss *boss) {
  while (1) {
    u.ClearScreen();
    std::string es = boss->getUsername();

    std::cout << u.Color("Pink") << "Choose an option:   " << u.Color("Base")
              << std::endl;
    std::cout << u.Color("Red") << "1. " << u.Color("Base") << "See Employees"
              << std::endl;
    std::cout << u.Color("Red") << "2. " << u.Color("Base") << "Add Librarian"
              << std::endl;
    std::cout << u.Color("Red") << "3. " << u.Color("Base")
              << "Remove Librarian   " << std::endl;
    std::cout << u.Color("Red") << "4. " << u.Color("Base") << "Log out        "
              << std::endl;
    std::cout << u.Color("Red") << "5. " << u.Color("Base") << "Exit           "
              << std::endl;

    char option;
    std::cout << ": ";
    std::cin >> option;

    switch (option) {
    case '1':
      u.ClearScreen();
      std::cout << u.Color("Pink") << "Employees: " << u.Color("Base")
                << std::endl;
      displayWorkers();
      u.Wait();
      break;
    case '2':
      addWorker();
      break;
    case '3':
      removeWorker();
      break;
    case '4':
      return true;
      break;
    case '5':
      return false;
      break;
    }
  }
  std::cin.ignore(100000, '\n');

  return false;
}
void MainSession::displayWorkers() {
  auto users = library->getUsers();
  for (auto user : users) {
    if (user->getType() == UserType::WORKER) {
      std::cout << " ID: " << u.Color("Blue") << user->getId()
                << u.Color("Base") << " - Username: ";
      std::cout << u.Color("Blue") << user->getUsername() << u.Color("Base");
      std::cout << std::endl;
    }
  }
}
void MainSession::addWorker() {
  u.ClearScreen();

  std::string username;
  std::string password;

  std::cout << u.Color("Pink") << "Add member: " << u.Color("Base")
            << std::endl;
  std::cout << "username: ";
  std::cin >> username;
  std::cout << "password: ";
  std::cin >> password;

  library->addWorker(username, password);
}
void MainSession::removeWorker() {
  u.ClearScreen();

  int id;

  std::cout << u.Color("Pink") << "Remove member: " << u.Color("Base")
            << std::endl;

  displayWorkers();

  std::cout << "ID: ";
  std::cin >> id;

  library->removeUser(id);
}
