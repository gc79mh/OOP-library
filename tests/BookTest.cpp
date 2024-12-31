#include "../inc/Book.h"
#include <gtest/gtest.h>

TEST(BookTest, Constructor) {
  Book book1("1984", "George Orwell");
  EXPECT_EQ(book1.getTitle(), "1984");
  EXPECT_EQ(book1.getAuthor(), "George Orwell");
}

TEST(BookTest, AssignmentOperator) {
  Book book1("1984", "George Orwell");
  Book book2 = book1;
  
  EXPECT_EQ(book2.getTitle(), "1984");
  EXPECT_EQ(book2.getAuthor(), "George Orwell");
}

TEST(BookTest, ComparisonOperator) {
  Book book1("1984", "George Orwell");
  Book book2("1984", "George Orwell");
  Book book3("The Hobbit", "J.R.R. Tolkien");

  EXPECT_EQ(book1 == book2, true);
  EXPECT_EQ(book1 == book3, false);
}
