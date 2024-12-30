#include <gtest/gtest.h>
#include "../inc/Library.h"

TEST(LibraryTest, addBook) {
  Library lib;
  lib.addBook("title", "author");

  auto es = *(lib.getBooks()[0]);
  EXPECT_EQ(es.getTitle(), "title");
}

TEST(LibraryTest, removeBook) {
  Library lib;
  lib.addBook("title", "author");
  lib.removeBook("title", "author");

  EXPECT_EQ(lib.getBooks().size(), 0);
}

TEST(LibraryTest, addUser) {
  Library lib;
  lib.addUser("User", "passwd");

  auto es = lib.getUsers()[0];
  EXPECT_EQ(es->getUsername(), "User");
}

TEST(LibraryTest, removeUser) {
  Library lib;
  lib.addUser("user", "passwd");
  lib.removeUser(0);

  EXPECT_EQ(lib.getUsers().size(), 0);
}
