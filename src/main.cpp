#include <iostream>

#include "../inc/Member.h"

int main() {
  Member admin(1);
  Book book("1984", "Orwell");

  admin.borrowBook(book);
  std::cout << admin << std::endl;


  return 0;
}
