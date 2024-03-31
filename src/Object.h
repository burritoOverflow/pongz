#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
 public:
  virtual std::string toString() = 0;
};

#endif