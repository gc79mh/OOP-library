#include "../inc/MemberSession.h"
#include <cstdio>
#include <string>

MemberSession::MemberSession(Library &library) { this->library = &library; }

MemberSession::~MemberSession() {}

void MemberSession::displayTitle(std::string title) {
  u.ClearScreen();
  std::cout << u.Color("Yellow");
  std::cout << title;
  std::cout << u.Color("Base");
  std::cout << std::endl;
}
void MemberSession::displayMenu() {
  displayTitle("Pick an action: ");
  std::cout << u.Color("Red") << "1. " << u.Color("Base") << "See all books  " << std::endl;
  std::cout << u.Color("Red") << "2. " << u.Color("Base") << "See my books   " << std::endl;
  std::cout << u.Color("Red") << "3. " << u.Color("Base") << "Rent a new book" << std::endl;
  std::cout << u.Color("Red") << "4. " << u.Color("Base") << "Return a book  " << std::endl;
  std::cout << u.Color("Red") << "5. " << u.Color("Base") << "Log out        " << std::endl;
}

int MemberSession::userInput() {
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

void MemberSession::memberSession(Member *member) {
  while (1) {
    displayMenu();

    int pick = userInput();

    if (pick == 1) {
      displayTitle("Books in the library:");
      displayLibraryBooks();
      u.Wait();

    } else if (pick == 2) {
      displayTitle("Your books:");
      displayMemberBooks(member);
      u.Wait();

    } else if (pick == 3) {
      memberRent(member);

    } else if (pick == 4) {
      memberReturn(member);

    } else if (pick == 5) {
      break;

    } 
  }
}

void MemberSession::displayLibraryBooks() {
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

void MemberSession::displayMemberBooks(Member *member) {
  auto books = member->checkBooks();
  for (int i = 0; i < (int)books.size(); i++) {
    auto book = books[i];
    std::cout << " " << i + 1 << ". ";
    std::cout << u.Color("Blue") << book.getTitle() << u.Color("Base");
    std::cout << " - " << book.getAuthor();
    std::cout << std::endl;
  }
}

void MemberSession::memberRent(Member *member) {
  displayTitle("Pick a book you want to rent out:");
  displayLibraryBooks();

  int pick = userInput();

  auto books = library->getBooks();
  if (pick - 1 >= (int)books.size() || pick < 1)
    return;

  auto book = *books[pick - 1].first;

  member->borrowBook(book);
  library->removeBook(book);
}

void MemberSession::memberReturn(Member *member) {
  displayTitle("Pick a book you want to return:");
  displayMemberBooks(member);

  int pick = userInput();

  auto books = member->checkBooks();
  if (pick - 1 >= (int)books.size() || pick < 1)
    return;

  auto book = books[pick - 1];

  member->returnBook(book);
  library->addBook(book);
}
