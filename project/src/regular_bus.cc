/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <string>
#include <iostream>

#include "src/regular_bus.h"

RegularBus::RegularBus(std::string name, Route * out, Route * in,
   int capacity, double speed) : Bus(name, out, in, capacity, speed) {}


void RegularBus::Report(std::ostream& out) {
  /*out << "Type: RegularBus" << std::endl;
  out << "Name: " << this->GetName() << std::endl;
  out << "Speed: " << this->GetSpeed() << std::endl;
  out << "Distance to next stop: " << this->GetDistanceRemaining() << std::endl;
  out << "\tPassengers (" << this->GetCapacity() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = this->GetPassenger().begin();
  it != this->GetPassenger().end(); it++) {
    (*it)->Report(out);
  }*/
  out << "Type: RegularBus" << std::endl;
  out << "Name: " << name_ << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
                                        it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}
