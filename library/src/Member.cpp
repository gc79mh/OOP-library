#include "../inc/Member.h"

Member::Member() {};
Member::~Member() {};

void Member::borrowBook(Book) {};
void Member::returnBook(Book) {};

int Member::getMemberId() { return memberId; };

void Member::setMemberId(int a) { this->memberId = a; };

std::ostream &operator<<(std::ostream &os, const Member &obj) {
  // write obj to stream
  return os;
};
