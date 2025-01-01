#include "../inc/Library.h"
#include "../inc/MainSession.h"

int main() {
  Library *library = new Library();
  MainSession session(library);
  
  library->addWorker("1", "1");

  session.start();

  delete library;
  return 0;
}
