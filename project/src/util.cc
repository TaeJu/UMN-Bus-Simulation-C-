/**
 * @file util.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <util.h>

std::list<std::string> Util::processOutput(std::ostringstream ostr) {
  std::list<std::string> list;
  std::string s = ostr.str();
  std::string word = "";
  for (auto x : s) {
    if (x == ' ') {
      list.push_back(word);
      word = "";
    } else {
      word = word + x;
    }
  }
  return list;
}
