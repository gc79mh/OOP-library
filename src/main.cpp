#include "../inc/Library.h"
#include "../inc/SessionManager.h"

int main() {
  Library lb;
  SessionManager sm(lb);

  lb.addMember("1", "1");

  lb.addBook("Ksiona", "Autor");
  lb.addBook("Ksiona2", "Autor");

  sm.menu();

  return 0;
}
