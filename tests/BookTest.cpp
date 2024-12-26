#include <gtest/gtest.h>
#include "../inc/Book.h"

// Test the default constructor
TEST(BookTest, DefaultConstructor) {
    Book book;
    // Verify initial state (assuming Book has some getters for title/author)
    EXPECT_EQ(book.getTitle(), "Unknown");
    EXPECT_EQ(book.getAuthor(), "Unknown");
}

// Test parameterized constructor (if any)
// For example, assuming there's a constructor Book(std::string title, std::string author)
TEST(BookTest, ParameterizedConstructor) {
    Book book("1984", "George Orwell");
    EXPECT_EQ(book.getTitle(), "1984");
    EXPECT_EQ(book.getAuthor(), "George Orwell");
}

// Test assignment operator
TEST(BookTest, AssignmentOperator) {
    Book book1("1984", "George Orwell");
    Book book2;
    book2 = book1;
    EXPECT_EQ(book2.getTitle(), "1984");
    EXPECT_EQ(book2.getAuthor(), "George Orwell");
}

