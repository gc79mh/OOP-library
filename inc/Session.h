#ifndef SESSION_H 
#define SESSION_H

#include "Library.h"
#include "Utils.h"

#include <cstdio>
#include <sstream>

class Session {
protected:
  Library *library;
  Utils u;

  int optionNumber;
  std::string color;

public:
  Session (Library *library);
  ~Session ();
  
  void start();

  int userInput();
  void displayTitle(std::string title);
  void displayOption(std::string text);
  void displaySeparator();
  void displayLibrary();

  void displayLibraryBooks();
  void displayLibraryUsers();

};

#endif
