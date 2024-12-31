#include "../inc/Utils.h"

Utils::Utils() {}
Utils::~Utils() {}

void Utils::ClearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

void Utils::Wait() {
  std::cin.get();
  std::cin.ignore(100000, '\n');
}

std::string Utils::Color(std::string color) {
  if (color == "Base") {
    return "\e[0m";
  } else if (color == "Red") {
    return "\e[1;31m";
  } else if (color == "Blue") {
    return "\e[1;34m";
  } else if (color == "Yellow") {
    return "\e[1;33m";
  } else if (color == "Gray") {
    return "\e[1;90m";
  } else if (color == "Green") {
    return "\e[1;32m";
  } else if (color == "Pink") {
    return "\e[36m";
  }
  return "";
}
