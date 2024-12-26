#include "../inc/Member.h"
#include <gtest/gtest.h>

TEST (MemberTest, Constructor) { 
  Member member1(2137, "Jan", "Kowalski"); 
  EXPECT_EQ(member1.getMemberId(), 2137);
  EXPECT_EQ(member1.getName(), "Jan");
  EXPECT_EQ(member1.getSurname(), "Kowalski");

  Member member2(2138, "Adam", "Kowalski"); 
  EXPECT_EQ(member1.getMemberId(), 2138);
  EXPECT_EQ(member1.getName(), "Adam");
  EXPECT_EQ(member1.getSurname(), "Kowalski");
}

TEST (MemberTest, BorrowBook) {
  Member member(2137, "Jan", "Kowalski"); 
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
  Member member(2137, "Jan", "Kowalski"); 
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
  Member member1(2137, "Jan", "Kowalski"); 
  Member member2(2138, "Adam", "Kowalski"); 

  EXPECT_EQ(member1 == member2, false);
}
