/**
 * @file file_write_manager.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_FILE_WRITE_MANAGER_H_
#define SRC_FILE_WRITE_MANAGER_H_

#include <file_writer.h>
#include <string>

class FileWriteManager {
  static FileWriter* file_writer;
  ofstream myfile;
 private:
  FileWriteManager() {
  }
 public:
  static FileWriter* getInstance() {
    if (!file_writer) {
      file_writer = new FileWriter;
    }
    return file_writer;
  }
  std::ofstream getLog(std::string name, std::string<std::string> list) {
    return file_writer->Write(name, list);
  }
  virtual ~FileWriteManager() {}
};
#endif  // SRC_FILE_WRITE_MANAGER_H_
