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
class RouteTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Stop *stop, *stop1, **stop2;
  Route *route, *route1, *route2;
  Passenger * passenger;
  RandomPassengerGenerator *random_passenger_generator;




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
    //delete random_passenger_generator;

    stop = NULL;
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

 TEST_F(RouteTests, Constructor){
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
   route = new Route("EastBank", stop2, distance_, 6, &random_passenger_generator);
   EXPECT_EQ(route->GetName(), "EastBank");
   EXPECT_EQ(route->GetStops(), stop_list_);
 }

 TEST_F(RouteTests, IsAtEndCheck){
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
   route = new Route("Coffman", stop2, distance_, 6, &random_passenger_generator);
   EXPECT_EQ(route->IsAtEnd(), false);
 }

 /*TEST_F(RouteTests, ReportCheck){
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
   route = new Route("EastBank", stop2, distance_, 6, &random_passenger_generator);
   std::string expected_output_1 = "Name: EastBank";
   std::string expected_output_2 = "Num stops: 6";
   testing::internal::CaptureStdout();
   route->Report(std::cout);
   std::string output1 = testing::internal::GetCapturedStdout();
   testing::internal::CaptureStdout();
   stop->Report(std::cout);
   std::string output2 = testing::internal::GetCapturedStdout();
   int p1 = output1.find(expected_output_1);
   int p2 = output2.find(expected_output_2);
   EXPECT_GE(p1, 0);
   EXPECT_GE(p2, 0);
 }*/
