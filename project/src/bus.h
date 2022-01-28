/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <fstream>

#include "src/data_structs.h"

#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/iobservable.h"
#include "src/iobserver.h"
#include "src/bus_web_observer.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class Bus : public IObservable {
 public:
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
  bool IsTripComplete();
  bool LoadPassenger(Passenger *);  // returning revenue delta
  bool Move();
  void Update();
  void NotifyObserver(BusData * Info);
  virtual void Report(std::ostream&);
  void ClearBusOstr();
  void ClearPasOstr();

  // Vis Getters
  void UpdateBusData();
  BusData GetBusData() const;
  std::string GetName() const { return name_; }
  Stop * GetNextStop() const { return next_stop_; }
  size_t GetNumPassengers() const { return passengers_.size(); }
  int GetCapacity() const { return passenger_max_capacity_; }
  double GetSpeed() const { return speed_; }
  int GetDistanceRemaining() const { return distance_remaining_; }
  std::list<Passenger *> GetPassenger() const {return passengers_; }

 protected:
  double speed_;
  // std::string* name2;
  std::string name_;
  double distance_remaining_;
  std::list<Passenger *> passengers_;
  std::ostringstream bus_ostr;
  std::ostringstream passenger_ostr;
  std::string type1 = "Small Bus";
  std::string type2 = "Standard Bus";
  std::string type3 = "Large Bus";

 private:
  int UnloadPassengers();  // returning revenue delta
  // bool Refuel();
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;

  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;

    // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
    // when negative?, unload/load procedure occurs
                              // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete

  // Vis data for bus
  BusData bus_data_;
};
#endif  // SRC_BUS_H_
