#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

class Utils {
private:

public:
  Utils();
  ~Utils();

  void ClearScreen();
  std::string Color(std::string color);
  void Wait();

};

#endif
