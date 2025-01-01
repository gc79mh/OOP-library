#include "../inc/MemberSession.h"
#include <cstdio>
#include <string>

MemberSession::MemberSession(Library &library) : Session(library) {
  color = "Yellow";
}

MemberSession::~MemberSession() {}

void MemberSession::start(Member *member) {
  while (1) {
    displayTitle("Choose: ");
    displayOption("Available books");
    displayOption("My books");
    displayOption("Rent a book");
    displayOption("Return a book");
    displayOption("Log out");

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
