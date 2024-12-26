#include <iostream>

#include "../inc/Member.h"

int main() {
  Member admin(1);
  Book book("1984", "Orwell");
  Book book2("Mega essa", "esser");
  Book b("ab", "c");

  admin.borrowBook(book);
  admin.borrowBook(book2);
  admin.borrowBook(b);

  std::cout << admin << std::endl;


  return 0;
}
