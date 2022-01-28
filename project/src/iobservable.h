/**
 * @file iobservable.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_IOBSERVABLE_H_
#define SRC_IOBSERVABLE_H_

#include "vector"
#include "list"
#include "string"
#include "iostream"
#include "./data_structs.h"
#include "src/iobserver.h"

class IObservable {
 public:
  void RegisterObserver(IObserver* bus_);
  void ClearObserver();
  void NotifyObserver(BusData* Info);
  void NotifyStopObserver(StopData* Info);
 private:
  std::vector<IObserver *> list;
  // list that keeps track of all the buses that are observing
};

#endif  // SRC_IOBSERVABLE_H_
