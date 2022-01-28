/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

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

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    //delete passenger;
    //delete passenger1;
    //delete passenger2;

    //passenger = NULL;
    //passenger1 = NULL;
    //passenger2 = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PassengerTests, Constructor) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->GetTotalWait(), 0);
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
  EXPECT_EQ(passenger->GetDestination(), -1);
}

TEST_F(PassengerTests, NameCheck) {
  passenger1 = new Passenger(12, "John Doe");
  passenger2 = new Passenger(12, "Apple Bee");
  std::string expected_output_1 = "Name: John Doe";
  std::string expected_output_2 = "Name: Apple Bee";
  testing::internal::CaptureStdout();
  passenger1->Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();
  testing::internal::CaptureStdout();
  passenger2->Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  int p1 = output1.find(expected_output_1);
  int p2 = output2.find(expected_output_2);
  EXPECT_GE(p1, 0);
  EXPECT_GE(p2, 0);
}

TEST_F(PassengerTests, DestinationIdCheck){
  passenger1 = new Passenger(12, "John Doe");
  passenger2 = new Passenger();
  EXPECT_EQ(passenger1->GetDestination(), 12);
  EXPECT_EQ(passenger2->GetDestination(), -1);
}

TEST_F(PassengerTests, GetTotalWait){
  passenger1 = new Passenger(12, "John Doe");
  passenger2 = new Passenger(12, "Apple Bee");
  int p3 = passenger1->GetTotalWait() + passenger2->GetTotalWait();
  EXPECT_EQ(passenger1->GetTotalWait(), 0);
  EXPECT_EQ(passenger2->GetTotalWait(), 0);
  EXPECT_EQ(p3, 0);
};

TEST_F(PassengerTests, IsOnBusCheck){
  passenger1 = new Passenger(12, "John Doe");
  passenger2 = new Passenger(12, "Apple Bee");
  EXPECT_EQ(passenger1->IsOnBus(), false);
  passenger2->GetOnBus();
  EXPECT_EQ(passenger2->IsOnBus(), true);
};


TEST_F(PassengerTests, GetOnBusCheck){
  passenger1 = new Passenger(12, "John Doe");
  passenger2 = new Passenger(12, "Apple Bee");
  passenger1->GetOnBus();
  int p1 = 1;
  int p2 = 0;
  EXPECT_EQ(p1, 1);
  EXPECT_EQ(p2, 0);
};

TEST_F(PassengerTests, UpdateCheck){
  passenger1 = new Passenger(12, "John Doe");
  passenger2 = new Passenger(12, "Apple Bee");
  passenger1->GetOnBus();
  passenger1->Update();
  int time_on_bus_p1 = 2;
  EXPECT_EQ(time_on_bus_p1, 2);
  passenger2->Update();
  int wait_at_stop_p2 = 1;
  EXPECT_EQ(wait_at_stop_p2, 1);
}
