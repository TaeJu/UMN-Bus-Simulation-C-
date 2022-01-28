/**
 * @file file_write.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_FILE_WRITER_H_
#define SRC_FILE_WRITER_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>

class FileWriter {
 public:
  std::ofstream Write(std::string, std::list<std::string>);
 private:
  std::ofstream myBusFile;
};
#endif  // SRC_FILE_WRITER_H_
