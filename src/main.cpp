#include "../inc/Library.h"
#include "../inc/MainSession.h"

int main() {
  Library *library = new Library();
  MainSession session(library);
  
  session.start();

  delete library;
  return 0;
}
