#ifndef DEBUGPRINTER_H 
#define DEBUGPRINTER_H

#include "Book.h"
#include "User.h"
#include "Member.h"
#include "Library.h"

#include <string>
#include <iostream>

class DebugPrinter {
public:
  DebugPrinter();
  ~DebugPrinter();

  void Print(Book book);
  void Print(User* user);
  void Print(Member member);
  void Print(Library library);

};

#endif
