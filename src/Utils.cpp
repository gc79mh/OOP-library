#include "../inc/Utils.h"

Utils::Utils() {}
Utils::~Utils() {}

void Utils::ClearScreen() { std::cout << "\033[2J\033[1;1H"; }

std::string Utils::Color(std::string color) {
  if (color == "Base") {
    return "\e[0m";
  } else if (color == "Red") {
    return "\e[31m";
  }
  return "";
}
