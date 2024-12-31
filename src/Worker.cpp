#include "../inc/Worker.h"

Worker::Worker(int id, std::string username, std::string password)
    : User(id, username, password) {}

Worker::~Worker() {}

UserType Worker::getType() const {
  return UserType::WORKER;
}
