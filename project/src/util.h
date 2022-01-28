/**
 * @file util.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>

class Util {
 public:
  std::list<std::string> processOutput(std::ostringstream);
};
#endif  // SRC_UTIL_H_
