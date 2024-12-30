#ifndef DEBUGPRINTER_H 
#define DEBUGPRINTER_H

#include "Book.h"
#include "Member.h"

#include <string>
#include <iostream>

class DebugPrinter {
private:
  std::string title;
  std::string author;

public:
  DebugPrinter();
  ~DebugPrinter();

  void Print(Book book);
  void Print(Member user);

};

std::ostream &operator<<(std::ostream &os, const Member &obj);
std::ostream &operator<<(std::ostream &os, const Book &obj);

#endif
