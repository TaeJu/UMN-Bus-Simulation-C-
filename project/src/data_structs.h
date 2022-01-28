/**
 * @file data_structs.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_DATA_STRUCTS_H_
#define SRC_DATA_STRUCTS_H_

#include <string>
#include <vector>


struct Position {
    Position() : x(0), y(0) {}
    float x;
    float y;
};

struct Color {
     Color(): red(0), green(0), blue(0), alpha(255) {}
     int red;
     int green;
     int blue;
     int alpha;
};

struct BusData {
    BusData() : id(""), position(Position()), num_passengers(0), capacity(0) {}
    std::string id;
    Position position;
    int num_passengers;
    int capacity;
    Color color;
};

struct StopData {
    StopData() : id(""), position(Position()), num_people(0) {}
    std::string id;
    Position position;
    int num_people;
};

struct RouteData {
    RouteData() : id(""), stops(std::vector<StopData>(0)) {}
    std::string id;
    std::vector<StopData> stops;
};

#endif  // SRC_DATA_STRUCTS_H_
