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



using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class StopTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Stop *stop, *stop1, *stop2;
  Passenger * passenger;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete stop;
    delete passenger;

    stop = NULL;
    passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
 TEST_F(StopTests, Constructor){
   stop = new Stop(1);
   EXPECT_EQ(stop->GetId(), 1);
   EXPECT_EQ(stop->GetLongitude(), 44.973723);
   EXPECT_EQ(stop->GetLatitude(), -93.235365);
 }

 TEST_F(StopTests, IdCheck){
   stop = new Stop(2, 35.55, 63.32);
   EXPECT_EQ(stop->GetId(), 2);
 }

 TEST_F(StopTests, UpdateCheck){
   stop = new Stop(2, 35.55, 63.32);
   stop->Update();
   EXPECT_EQ(stop->GetNumPassengersPresent(), 0);
 }

 TEST_F(StopTests, PassengerCheck){
   stop = new Stop(2, 35.55, 63.32);
   passenger = new Passenger();
   EXPECT_EQ(stop->GetNumPassengersPresent(), 0);
   stop->AddPassengers(passenger);
   EXPECT_EQ(stop->GetNumPassengersPresent(), 1);
 }

 /*TEST_F(StopTests, ReportCheck){
   stop = new Stop(2, 35.55, 63.32);
   std::string expected_output_1 = "ID: 2";
   std::string expected_output_2 = "Passengers waiting: 0";
   testing::internal::CaptureStdout();
   stop->Report(std::cout);
   std::string output1 = testing::internal::GetCapturedStdout();
   testing::internal::CaptureStdout();
   stop->Report(std::cout);
   std::string output2 = testing::internal::GetCapturedStdout();
   int p1 = output1.find(expected_output_1);
   int p2 = output2.find(expected_output_2);
   EXPECT_GE(p1, 0);
   EXPECT_GE(p2, 0);
 }*/
