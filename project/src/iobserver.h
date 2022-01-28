/**
 * @file iobserver.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

#include "./data_structs.h"
#include "./my_web_server_session.h"
#include "string"
#include "iostream"

class IObserver {
 public:
  virtual void Notify(BusData * Info) = 0;
  virtual void NotifyStop(StopData* Info) = 0;
};
#endif  // SRC_IOBSERVER_H_
