/**
 * @file visualization_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef WEB_VISUALIZATION_SIMULATOR_H_
#define WEB_VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <memory>
#include <iostream>
#include <list>
#include <string>

#include "src/bus_web_observer.h"
#include "src/stop_web_observer.h"
#include "web_code/web/web_interface.h"
#include "src/config_manager.h"
#include "src/bus_factory.h"
#include "src/iobserver.h"
#include "src/iobservable.h"
// #include "src/file_write_manager.h"

class Route;
class Bus;
class Stop;

class VisualizationSimulator {
 public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        void Pause();
        void Update();

        void AddListener(std::string id, IObserver* observer);
        void AddStopListener(std::string id, IObserver* observer);
        void ClearListeners();

 private:
        WebInterface* webInterface_;
        ConfigManager* configManager_;
        BusFactory* fac;
        BusWebObserver* observer_;

        std::vector<int> busStartTimings_;
        std::vector<int> timeSinceLastBus_;
        int numTimeSteps_;
        int simulationTimeElapsed_;
        std::string id_;
        std::string bus_stats_file_name;

        std::vector<Route *> prototypeRoutes_;
        std::vector<Bus *> busses_;
        int busId = 1000;
};

#endif  // WEB_VISUALIZATION_SIMULATOR_H_
