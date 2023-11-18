#pragma once

#include <exception>
#include <iostream>

using std::cout, std::endl;

class StackException : public std::exception {
  const char *msg;
  StackException() = delete;
public:
  explicit StackException(const char *s) : msg(s) { }
  const char *what() const { return msg; }
};