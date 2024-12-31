#include "../inc/Member.h"
#include <gtest/gtest.h>

TEST (MemberTest, Constructor) { 
  Member member1(2137, "Wiktor", "123"); 
  EXPECT_EQ(member1.getId(), 2137);
  EXPECT_EQ(member1.getUsername(), "Wiktor");
  EXPECT_EQ(member1.getPassword(), "123");

  Member member2(2138, "Es", "1"); 
  EXPECT_EQ(member2.getId(), 2138);
  EXPECT_EQ(member2.getUsername(), "Es");
  EXPECT_EQ(member2.getPassword(), "1");
}

TEST (MemberTest, BorrowBook) {
  Member member(2137, "Es", "1"); 
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
  Member member(2137, "Es", "1"); 
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
  Member member1(2137, "Es", "1"); 
  Member member2(2138, "Essa", "2"); 

  EXPECT_EQ(member1 == member2, false);
  EXPECT_EQ(member1 == member1, true);
}
