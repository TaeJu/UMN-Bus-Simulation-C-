/**
 * @file passenger_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <random>
#include <time.h>
#include <string>
#include "src/bus.h"
#include "src/route.h"
#include "src/small_bus.h"
#include "src/regular_bus.h"
#include "src/large_bus.h"


class BusFactory {
 public:
  static Bus * GenerateBus(std::string, Route *, Route *, double);
  static int stratNum1;
  static int stratNum2;
  static int stratNum3;
};
#endif  // SRC_BUS_FACTORY_H_
