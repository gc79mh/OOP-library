#include "../inc/Library.h"
#include "../inc/MainSession.h"

int main() {
  Library library;
  MainSession session(library);

  library.addMember("1", "1");

  library.addBook("Ksiona", "Autor");
  library.addBook("Ksiona2", "Autor");

  session.start();

  return 0;
}
