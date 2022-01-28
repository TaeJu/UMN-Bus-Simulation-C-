/**
 * @file bus_web_observer.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/bus_web_observer.h"
#include <sstream>

void BusWebObserver::NotifyStop(StopData* Info) {}

void BusWebObserver::Notify(BusData* Info) {
  picojson::object data;
  data["command"] = picojson::value("observe");
  std::stringstream ss;
  ss << "Bus " << Info->id << "\n";
  ss << "-----------------------------\n";
  ss << "  * Position: (" << Info->position.x <<
   "," << Info->position.y << ")\n";
  ss << "  * Passengers: " << Info->num_passengers << "\n";
  ss << "  * Capacity: " << Info->capacity << "\n";
  data["text"] = picojson::value(ss.str());
  picojson::value ret(data);
  session->sendJSON(ret);
}
