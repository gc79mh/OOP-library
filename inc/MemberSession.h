#ifndef MEMBER_SESSION_H 
#define MEMBER_SESSION_H

#include "Member.h"
#include "User.h"
#include "Library.h"
#include "Utils.h"

#include <cstdlib>
#include <sstream>

class MemberSession {
private:
  Library *library;
  Utils u;

public:
  MemberSession (Library &library);
  ~MemberSession ();
  
  void memberSession(Member* user);

  int userInput();

  void displayMenu();
  void displayTitle(std::string title);
  void displayLibraryBooks();
  void displayMemberBooks(Member* user);

  void memberRent(Member* user);
  void memberReturn(Member* user);

};

#endif
