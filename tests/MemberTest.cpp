#include "../inc/Member.h"
#include <gtest/gtest.h>

TEST (MemberTest, Constructor) { 
  Member member1(100); 
  EXPECT_EQ(member1.getMemberId(), 100);
  
  Member member2(200); 
  EXPECT_EQ(member2.getMemberId(), 200);
}

TEST (MemberTest, BorrowBook) {
  Member member(2137);
  Book book1("1984", "Orwell");
  Book book2("The Hobbit", "Tolkien");

  member.borrowBook(book1);
  
  EXPECT_EQ(member.checkBooks().size(), 1); 
  EXPECT_EQ(member.checkBooks()[0], book1);
  
  member.borrowBook(book2);

  EXPECT_EQ(member.checkBooks().size(), 2);
  EXPECT_EQ(member.checkBooks()[0], book1);
  EXPECT_EQ(member.checkBooks()[1], book2);
}

TEST (MemberTest, ReturnBook) {
  Member member(2137);
  Book book1("1984", "Orwell");
  Book book2("The Hobbit", "Tolkien");

  member.borrowBook(book1);
  member.borrowBook(book2);
  
  EXPECT_EQ(member.checkBooks().size(), 2);
  EXPECT_EQ(member.checkBooks()[0], book1);
  EXPECT_EQ(member.checkBooks()[1], book2);

  member.returnBook(book1);

  EXPECT_EQ(member.checkBooks().size(), 1);
  EXPECT_EQ(member.checkBooks()[0], book2);
}

TEST (MemberTest, Comparison) {
  Member member1(2137);
  Member member2(1);

  EXPECT_EQ(member1 == member2, false);
}
