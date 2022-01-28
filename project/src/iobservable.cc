/**
 * @file iobservable.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/iobservable.h"

void IObservable::RegisterObserver(IObserver* bus_) {
  list.push_back(bus_);
}

void IObservable::ClearObserver() {
  list.clear();
}

void IObservable::NotifyStopObserver(StopData* Info) {
  for (std::vector<IObserver*>::const_iterator iter
     = list.begin(); iter != list.end(); ++iter) {
      if (*iter != 0) {
        (*iter)->NotifyStop(Info);
     }
  }
}

void IObservable::NotifyObserver(BusData* Info) {
  for (std::vector<IObserver*>::const_iterator iter
     = list.begin(); iter != list.end(); ++iter) {
      if (*iter != 0) {
        (*iter)->Notify(Info);
     }
  }
}
