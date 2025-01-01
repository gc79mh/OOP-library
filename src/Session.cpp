#include "../inc/Session.h"

Session::Session(Library &library) {
  this->library = &library;
  optionNumber = 1;
}

Session::~Session() {}

void Session::displayTitle(std::string title) {
  u.ClearScreen();
  std::cout << u.Color(color);
  std::cout << title;
  std::cout << u.Color("Base");
  std::cout << std::endl;
  optionNumber = 1;
}

void Session::displayOption(std::string text) {
  std::cout << u.Color("Red");
  std::cout << optionNumber++ << ". ";
  std::cout << u.Color("Base");
  std::cout << text;
  std::cout << std::endl;
}

int Session::userInput() {
  std::cout << ": ";

  std::string rawInput;

  std::getline(std::cin, rawInput);

  std::istringstream stream(rawInput);

  std::string rawPick;
  stream >> rawPick;

  int pick;
  try {
    pick = std::stoi(rawPick);

  } catch (std::invalid_argument &) {
    pick = -1;

  } catch (std::out_of_range &) {
    pick = -1;
  }

  return pick;
}

void Session::displayLibraryBooks() {
  auto books = library->getBooks();
  for (int i = 0; i < (int)books.size(); i++) {
    auto book = books[i];
    std::cout << " " << i + 1 << ". ";
    std::cout << u.Color("Blue") << book.first->getTitle() << u.Color("Base");
    std::cout << " - " << book.first->getAuthor();
    std::cout << u.Color("Gray") << " x" << book.second << u.Color("Base");
    std::cout << std::endl;
  }
}
void Session::displayLibraryUsers() {
  auto users = library->getUsers();
  for (auto user : users) {
    if (user->getType() == UserType::USER) {
      std::cout << " ID: " << u.Color("Blue") << user->getId()
                << u.Color("Base") << " - Username: ";
      std::cout << u.Color("Blue") << user->getUsername() << u.Color("Base");
      std::cout << std::endl;
    }
  }
}

