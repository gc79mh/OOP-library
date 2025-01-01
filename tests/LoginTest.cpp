#include <gtest/gtest.h>
#include "../inc/LoginManager.h"

TEST(LoginTest, wrongUser) {
  Library library;
  LoginManager login(library);

  EXPECT_EQ(login.findUser("root11", "rafsafdoot"), nullptr);
}
