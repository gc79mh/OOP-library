#include "../inc/Library.h"
#include "../inc/MainSession.h"

int main() {
  Library *library = new Library("3", "3");
  MainSession session(library);

  library->addMember("1", "1");
  library->addWorker("2", "2");

  library->addBook("Ksiona", "Autor");
  library->addBook("Ksiona2", "Autor");
  library->addBook("es", "1");

  session.start();
  delete library;
  return 0;
}
