/**
 * @file file_write.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <file_writer.h>

std::ofstream FileWriter::Write(std::string name, std::list<std::string> list) {
    if (name == "BusData.csv") {
    // myBusFile.open(name);
    std::ofstream temp;
    temp.open(name);
    int j = 0;  // line mover
    for (std::list<std::string>::iterator it = list.begin();
    it != list.end(); it++) {
      if ( j == 17 ) {
        temp << *it << "," << std::endl;
        j = 0;
      } else {
      temp << *it << ",";
      j++;
    }
  }
  return temp;
  }
}
