#include "../inc/Book.h"
#include <gtest/gtest.h>

TEST(BookTest, Constructor_Base) {
  Book book1("1984", "George Orwell");
  EXPECT_EQ(book1.getTitle(), "1984");
  EXPECT_EQ(book1.getAuthor(), "George Orwell");
}

TEST(BookTest, Constructor_Availability) {
  Book book2("The Hobbit", "J.R.R. Tolkien", false);
  EXPECT_EQ(book2.getTitle(), "The Hobbit");
  EXPECT_EQ(book2.getAuthor(), "J.R.R. Tolkien");
  EXPECT_EQ(book2.checkAvailability(), false);
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

TEST(BookTest, Availability) {
  Book book("1984", "George Orwell");
  EXPECT_EQ(book.checkAvailability(), true);

  book.changeAvailability();
  EXPECT_EQ(book.checkAvailability(), false);
}
