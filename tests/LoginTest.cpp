#include <gtest/gtest.h>
#include "../inc/LoginManager.h"

TEST(LoginTest, findRoot) {
  Library library;
  LoginManager login(library);

  EXPECT_EQ(login.checkUser("root", "root"), true);
}

TEST(LoginTest, wrongUser) {
  Library library;
  LoginManager login(library);

  EXPECT_EQ(login.checkUser("root11", "rafsafdoot"), false);
}

TEST(LoginTest, findUser) {
  Library library;
  LoginManager login(library);
  
  library.addMember("11", "12");

  EXPECT_EQ(login.checkUser("11", "12"), true);
}
