#include <gtest/gtest.h>
#include "../inc/Library.h"

TEST(LibraryTest, addBook) {
  Library lib;
  
  lib.addBook("title", "author");
  EXPECT_EQ(lib.getBooks().size(), 1);
  EXPECT_EQ(lib.getBooks()[0].second, 1);
  
  lib.addBook("title", "author");
  EXPECT_EQ(lib.getBooks().size(), 1);
  EXPECT_EQ(lib.getBooks()[0].second, 2);

  Book book("title2", "author2");
  lib.addBook(book);
  EXPECT_EQ(lib.getBooks().size(), 2);
  EXPECT_EQ(*(lib.getBooks()[1].first), book);
}

TEST(LibraryTest, removeBook) {
  Library lib;
  Book book("title", "author");
  
  lib.addBook(book);
  lib.removeBook(book);
  EXPECT_EQ(lib.getBooks().size(), 0);
  
  lib.addBook(book);
  lib.addBook(book);
  EXPECT_EQ(lib.getBooks().size(), 1);
  EXPECT_EQ(lib.getBooks()[0].second, 2);
  lib.removeBook(book);
  EXPECT_EQ(lib.getBooks()[0].second, 1);
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
