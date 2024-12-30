#include "../inc/Worker.h"

Worker::Worker(int id, std::string username, std::string password)
    : User(id, username, password) {}

Worker::~Worker() {}

std::string Worker::getType() const {
  return "Worker";
}
