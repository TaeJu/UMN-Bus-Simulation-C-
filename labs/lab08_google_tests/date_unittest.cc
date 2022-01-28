#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  test_day = Date(2020, 3, 1);
  test_day2 = Date();
  test_day3 = Date(2016, 1, 1);
  test_day4 = Date(2016, 3, 1);
  test_day5 = Date(2018, 12, 1);
  }
  int x = 10;
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
  Date test_day;
  Date test_day2;
  Date test_day3;
  Date test_day4;
  Date test_day5;
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);      // Halloween
  Date epoch(0);


  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  std::string expected_out_4 = "1970-01-01\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  epoch.PrintDate(true);
  std::string output4 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
  EXPECT_EQ(output4, expected_out_4);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  Date epoch(0);

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  std::string expected_out_4 = "1970-01-01";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  epoch.PrintDate(false);
  std::string output4 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
  EXPECT_EQ(output4, expected_out_4);

}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {
  //Date temp_day = last_day - 10;
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(test_day.GetDate(), "2020-03-01") << "test day of class not setup properly";
  EXPECT_EQ(test_day2.GetUsDate() , "02-24-2020") << "test day2 of class not setup propely";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
  EXPECT_EQ(test_day3.DaysBetween(test_day4), 60) << "Days between is not calculated properly";
  //EXPECT_LT( temp_day , test_day5 ) << "Operator - is not calculated properly";
}

/*TEST_F(DateTest, GetDateTests) {
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetDate(), "2018-12-11") << "Last day of class not setup properly";
} */
/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
