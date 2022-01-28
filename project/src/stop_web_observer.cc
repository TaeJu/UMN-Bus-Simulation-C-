/**
 * @file stop_web_observer.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/stop_web_observer.h"
#include <sstream>

void StopWebObserver::NotifyStop(StopData* Info) {
  picojson::object data;
  data["command"] = picojson::value("observeS");
  std::stringstream ss;
  ss << "Stop " << Info->id << "\n";
  ss << "-----------------------------\n";
  ss << "  * Position: (" << Info->position.x <<
   "," << Info->position.y << ")\n";
  ss << "  * Num of People: " << Info->num_people << "\n";
  data["text"] = picojson::value(ss.str());
  picojson::value ret(data);
  session->sendJSON(ret);
}

void StopWebObserver::Notify(BusData* Info) {}
