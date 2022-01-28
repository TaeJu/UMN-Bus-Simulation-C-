/**
 * @file stop_web_observer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_STOP_WEB_OBSERVER_H_
#define SRC_STOP_WEB_OBSERVER_H_

#include "./my_web_server_session.h"
#include "./data_structs.h"
#include "string"
#include "iostream"
#include "src/iobserver.h"
// class IObserver;

class StopWebObserver : public IObserver {
 public:
    explicit StopWebObserver(MyWebServerSession* session) : session(session) {}
    void Notify(BusData* Info);
    void NotifyStop(StopData* Info);
 private:
    MyWebServerSession* session;};
#endif  // SRC_STOP_WEB_OBSERVER_H_
