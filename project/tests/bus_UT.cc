/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"
#include "../src/bus.h"
#include "../src/passenger_generator.h"
#include "../src/random_passenger_generator.h"


using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BusTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Stop *stop, *stop1, **stop2, **stop3;
  Route *route, *route1, *route2;
  Passenger * passenger;
  RandomPassengerGenerator *random_passenger_generator;
  Bus *bus, *bus1, *bus2;




  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
    //random_passenger_generator = new PassengerGenerator();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete stop;
    delete route;
    delete passenger;
    delete bus;
    //delete random_passenger_generator;

    stop = NULL;
    bus = NULL;
    //random_passenger_generator = NULL;
    route = NULL;
    passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
 TEST_F(BusTests, Constructor){
   stop2 = new Stop *[6];
   std::list<double> list_;
   std::list<Stop *> stop_list_;
   Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
   Stop stop_CC_EB_2(1); //student union station
   Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave
   Stop stop_CC_EB_4(3, 45, -94); //before transit
   Stop stop_CC_EB_5(4, 46, -95); //st paul 1
   Stop stop_CC_EB_6(5, 47, -96); //st paul 2
   stop_list_.push_back(&stop_CC_EB_1);
   stop2[0] = &stop_CC_EB_1;
   stop_list_.push_back(&stop_CC_EB_2);
   stop2[1] = &stop_CC_EB_2;
   stop_list_.push_back(&stop_CC_EB_3);
   stop2[2] = &stop_CC_EB_3;
   stop_list_.push_back(&stop_CC_EB_4);
   stop2[3] = &stop_CC_EB_4;
   stop_list_.push_back(&stop_CC_EB_5);
   stop2[4] = &stop_CC_EB_5;
   stop_list_.push_back(&stop_CC_EB_6);
   stop2[5] = &stop_CC_EB_6;
   double *distance_ = new double[5];
   distance_[0] = 1.2;
   distance_[1] = 2.2;
   distance_[2] = 3.3;
   distance_[3] = 4.4;
   distance_[4] = 5.5;
   RandomPassengerGenerator random_passenger_generator(list_, stop_list_);
   stop3 = new Stop *[6];
   std::list<double> list2_;
   std::list<Stop *> stop_list2_;
   Stop stop_CC_WB_1(6, 47, -96); //st paul 2
   Stop stop_CC_WB_2(7, 46, -95); //st paul 1
   Stop stop_CC_WB_3(8, 45, -94); //before transit
   Stop stop_CC_WB_4(9, 44.973820, -93.227117); //Oak St & Washington Ave
   Stop stop_CC_WB_5(10); //student union station
   Stop stop_CC_WB_6(11, 43, -92.5); //West bank station
   stop_list2_.push_back(&stop_CC_EB_1);
   stop3[0] = &stop_CC_EB_1;
   stop_list2_.push_back(&stop_CC_EB_2);
   stop3[1] = &stop_CC_EB_2;
   stop_list2_.push_back(&stop_CC_EB_3);
   stop3[2] = &stop_CC_EB_3;
   stop_list2_.push_back(&stop_CC_EB_4);
   stop3[3] = &stop_CC_EB_4;
   stop_list2_.push_back(&stop_CC_EB_5);
   stop3[4] = &stop_CC_EB_5;
   stop_list2_.push_back(&stop_CC_EB_6);
   stop3[5] = &stop_CC_EB_6;
   double *distance2_ = new double[5];
   distance2_[0] = 5.5;
   distance2_[1] = 4.4;
   distance2_[2] = 3.3;
   distance2_[3] = 2.2;
   distance2_[4] = 1.2;
   RandomPassengerGenerator random_passenger_generator2(list2_, stop_list2_);

   route1 = new Route("EastBank", stop2, distance_, 6, &random_passenger_generator);
   route2 = new Route("WestBank", stop3, distance2_, 6, &random_passenger_generator2);
   bus1 = new Bus("Tayo", route1, route2, 60, 5.5);
   //Bus bus2("Tayo2", &route2, &route1, 60, 5.5);

   EXPECT_EQ(bus1->GetName(), "Tayo");
   EXPECT_EQ(bus1->GetNextStop(), route1->GetDestinationStop());
   EXPECT_EQ(bus1->GetNumPassengers(), 0);
   EXPECT_EQ(bus1->GetCapacity(), 60);
 }

 TEST_F(BusTests, TripCompleteCheck){
   stop2 = new Stop *[6];
   std::list<double> list_;
   std::list<Stop *> stop_list_;
   Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
   Stop stop_CC_EB_2(1); //student union station
   Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave
   Stop stop_CC_EB_4(3, 45, -94); //before transit
   Stop stop_CC_EB_5(4, 46, -95); //st paul 1
   Stop stop_CC_EB_6(5, 47, -96); //st paul 2
   stop_list_.push_back(&stop_CC_EB_1);
   stop2[0] = &stop_CC_EB_1;
   stop_list_.push_back(&stop_CC_EB_2);
   stop2[1] = &stop_CC_EB_2;
   stop_list_.push_back(&stop_CC_EB_3);
   stop2[2] = &stop_CC_EB_3;
   stop_list_.push_back(&stop_CC_EB_4);
   stop2[3] = &stop_CC_EB_4;
   stop_list_.push_back(&stop_CC_EB_5);
   stop2[4] = &stop_CC_EB_5;
   stop_list_.push_back(&stop_CC_EB_6);
   stop2[5] = &stop_CC_EB_6;
   double *distance_ = new double[5];
   distance_[0] = 1.2;
   distance_[1] = 2.2;
   distance_[2] = 3.3;
   distance_[3] = 4.4;
   distance_[4] = 5.5;
   RandomPassengerGenerator random_passenger_generator(list_, stop_list_);
   stop3 = new Stop *[6];
   std::list<double> list2_;
   std::list<Stop *> stop_list2_;
   Stop stop_CC_WB_1(6, 47, -96); //st paul 2
   Stop stop_CC_WB_2(7, 46, -95); //st paul 1
   Stop stop_CC_WB_3(8, 45, -94); //before transit
   Stop stop_CC_WB_4(9, 44.973820, -93.227117); //Oak St & Washington Ave
   Stop stop_CC_WB_5(10); //student union station
   Stop stop_CC_WB_6(11, 43, -92.5); //West bank station
   stop_list2_.push_back(&stop_CC_EB_1);
   stop3[0] = &stop_CC_EB_1;
   stop_list2_.push_back(&stop_CC_EB_2);
   stop3[1] = &stop_CC_EB_2;
   stop_list2_.push_back(&stop_CC_EB_3);
   stop3[2] = &stop_CC_EB_3;
   stop_list2_.push_back(&stop_CC_EB_4);
   stop3[3] = &stop_CC_EB_4;
   stop_list2_.push_back(&stop_CC_EB_5);
   stop3[4] = &stop_CC_EB_5;
   stop_list2_.push_back(&stop_CC_EB_6);
   stop3[5] = &stop_CC_EB_6;
   double *distance2_ = new double[5];
   distance2_[0] = 5.5;
   distance2_[1] = 4.4;
   distance2_[2] = 3.3;
   distance2_[3] = 2.2;
   distance2_[4] = 1.2;
   RandomPassengerGenerator random_passenger_generator2(list2_, stop_list2_);

   route1 = new Route("EastBank", stop2, distance_, 6, &random_passenger_generator);
   route2 = new Route("WestBank", stop3, distance2_, 6, &random_passenger_generator2);
   bus1 = new Bus("Tayo", route1, route2, 60, 5.5);

   EXPECT_EQ(bus1->IsTripComplete(), false);

 }

 TEST_F(BusTests, MoveTest){
   stop2 = new Stop *[6];
   std::list<double> list_;
   std::list<Stop *> stop_list_;
   Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
   Stop stop_CC_EB_2(1); //student union station
   Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave
   Stop stop_CC_EB_4(3, 45, -94); //before transit
   Stop stop_CC_EB_5(4, 46, -95); //st paul 1
   Stop stop_CC_EB_6(5, 47, -96); //st paul 2
   stop_list_.push_back(&stop_CC_EB_1);
   stop2[0] = &stop_CC_EB_1;
   stop_list_.push_back(&stop_CC_EB_2);
   stop2[1] = &stop_CC_EB_2;
   stop_list_.push_back(&stop_CC_EB_3);
   stop2[2] = &stop_CC_EB_3;
   stop_list_.push_back(&stop_CC_EB_4);
   stop2[3] = &stop_CC_EB_4;
   stop_list_.push_back(&stop_CC_EB_5);
   stop2[4] = &stop_CC_EB_5;
   stop_list_.push_back(&stop_CC_EB_6);
   stop2[5] = &stop_CC_EB_6;
   double *distance_ = new double[5];
   distance_[0] = 1.2;
   distance_[1] = 2.2;
   distance_[2] = 3.3;
   distance_[3] = 4.4;
   distance_[4] = 5.5;
   RandomPassengerGenerator random_passenger_generator(list_, stop_list_);
   stop3 = new Stop *[6];
   std::list<double> list2_;
   std::list<Stop *> stop_list2_;
   Stop stop_CC_WB_1(6, 47, -96); //st paul 2
   Stop stop_CC_WB_2(7, 46, -95); //st paul 1
   Stop stop_CC_WB_3(8, 45, -94); //before transit
   Stop stop_CC_WB_4(9, 44.973820, -93.227117); //Oak St & Washington Ave
   Stop stop_CC_WB_5(10); //student union station
   Stop stop_CC_WB_6(11, 43, -92.5); //West bank station
   stop_list2_.push_back(&stop_CC_EB_1);
   stop3[0] = &stop_CC_EB_1;
   stop_list2_.push_back(&stop_CC_EB_2);
   stop3[1] = &stop_CC_EB_2;
   stop_list2_.push_back(&stop_CC_EB_3);
   stop3[2] = &stop_CC_EB_3;
   stop_list2_.push_back(&stop_CC_EB_4);
   stop3[3] = &stop_CC_EB_4;
   stop_list2_.push_back(&stop_CC_EB_5);
   stop3[4] = &stop_CC_EB_5;
   stop_list2_.push_back(&stop_CC_EB_6);
   stop3[5] = &stop_CC_EB_6;
   double *distance2_ = new double[5];
   distance2_[0] = 5.5;
   distance2_[1] = 4.4;
   distance2_[2] = 3.3;
   distance2_[3] = 2.2;
   distance2_[4] = 1.2;
   RandomPassengerGenerator random_passenger_generator2(list2_, stop_list2_);

   route1 = new Route("EastBank", stop2, distance_, 6, &random_passenger_generator);
   route2 = new Route("WestBank", stop3, distance2_, 6, &random_passenger_generator2);
   bus1 = new Bus("Tayo", route1, route2, 60, 5.5);
   passenger = new Passenger();
   
   EXPECT_EQ(bus1->Move(), false);
   bus1->LoadPassenger(passenger);
   bus1->Move();
   bus1->UpdateBusData();
   bus1->Update();
   EXPECT_EQ(bus1->Move(), true);
 }

 TEST_F(BusTests, LoadPassengerCheck){
   stop2 = new Stop *[6];
   std::list<double> list_;
   std::list<Stop *> stop_list_;
   Stop stop_CC_EB_1(0, 43, -92.5); //West bank station
   Stop stop_CC_EB_2(1); //student union station
   Stop stop_CC_EB_3(2, 44.973820, -93.227117); //Oak St & Washington Ave
   Stop stop_CC_EB_4(3, 45, -94); //before transit
   Stop stop_CC_EB_5(4, 46, -95); //st paul 1
   Stop stop_CC_EB_6(5, 47, -96); //st paul 2
   stop_list_.push_back(&stop_CC_EB_1);
   stop2[0] = &stop_CC_EB_1;
   stop_list_.push_back(&stop_CC_EB_2);
   stop2[1] = &stop_CC_EB_2;
   stop_list_.push_back(&stop_CC_EB_3);
   stop2[2] = &stop_CC_EB_3;
   stop_list_.push_back(&stop_CC_EB_4);
   stop2[3] = &stop_CC_EB_4;
   stop_list_.push_back(&stop_CC_EB_5);
   stop2[4] = &stop_CC_EB_5;
   stop_list_.push_back(&stop_CC_EB_6);
   stop2[5] = &stop_CC_EB_6;
   double *distance_ = new double[5];
   distance_[0] = 1.2;
   distance_[1] = 2.2;
   distance_[2] = 3.3;
   distance_[3] = 4.4;
   distance_[4] = 5.5;
   RandomPassengerGenerator random_passenger_generator(list_, stop_list_);
   stop3 = new Stop *[6];
   std::list<double> list2_;
   std::list<Stop *> stop_list2_;
   Stop stop_CC_WB_1(6, 47, -96); //st paul 2
   Stop stop_CC_WB_2(7, 46, -95); //st paul 1
   Stop stop_CC_WB_3(8, 45, -94); //before transit
   Stop stop_CC_WB_4(9, 44.973820, -93.227117); //Oak St & Washington Ave
   Stop stop_CC_WB_5(10); //student union station
   Stop stop_CC_WB_6(11, 43, -92.5); //West bank station
   stop_list2_.push_back(&stop_CC_EB_1);
   stop3[0] = &stop_CC_EB_1;
   stop_list2_.push_back(&stop_CC_EB_2);
   stop3[1] = &stop_CC_EB_2;
   stop_list2_.push_back(&stop_CC_EB_3);
   stop3[2] = &stop_CC_EB_3;
   stop_list2_.push_back(&stop_CC_EB_4);
   stop3[3] = &stop_CC_EB_4;
   stop_list2_.push_back(&stop_CC_EB_5);
   stop3[4] = &stop_CC_EB_5;
   stop_list2_.push_back(&stop_CC_EB_6);
   stop3[5] = &stop_CC_EB_6;
   double *distance2_ = new double[5];
   distance2_[0] = 5.5;
   distance2_[1] = 4.4;
   distance2_[2] = 3.3;
   distance2_[3] = 2.2;
   distance2_[4] = 1.2;
   RandomPassengerGenerator random_passenger_generator2(list2_, stop_list2_);

   route1 = new Route("EastBank", stop2, distance_, 6, &random_passenger_generator);
   route2 = new Route("WestBank", stop3, distance2_, 6, &random_passenger_generator2);
   bus1 = new Bus("Tayo", route1, route2, 60, 5.5);
   bus2 = new Bus("Tayo2", route2, route1, 0, 5.5);
   passenger = new Passenger();
   EXPECT_EQ(bus1->LoadPassenger(passenger), true);
   EXPECT_EQ(bus2->LoadPassenger(passenger), false);
 }
