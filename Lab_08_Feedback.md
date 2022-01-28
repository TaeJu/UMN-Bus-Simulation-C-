### Fuller Feedback for Lab 08

Run on February 25, 09:48:02 AM.


#### System Files and Lab Directory Structure

+ Pass: Check that directory "googletest" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab08_google_tests" exists.

+ Pass: Make directory "Lab08_Testing".

+ Pass: Change into directory "Lab08_Testing".


#### Essential Files Exist

+ Pass: Check that file "../labs/lab08_google_tests/date_unittest.cc" exists.


### Testing correct implementation

+ Pass: Copy directory "Lab08 files.".



+ Pass: Copy directory "Files for correct version".



+ Pass: Change into directory "correct".

+ Pass: Check that make compiles.



+ Pass: Check that file "date_unittest" exists.

+ Pass: Get all google tests.
    3 tests found.




#### Results

+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTests.



+ Pass: Check that a GoogleTest test passes.
    passes the test: DateTest.PrintDateTestsWithoutNewline.



+ Fail: Check that a GoogleTest test passes.
    fails the test: DateTest.DaysBetweenTests.
<pre>
[ RUN      ] DateTest.DaysBetweenTests
./date_unittest.cc:115: Failure
      Expected: test_day2.GetUsDate()
      Which is: "02-25-2020"
To be equal to: "02-24-2020"
test day2 of class not setup propely</pre>



+ Fail: 66.67% of the tests passed, but the target is 100%.


### Testing Mutants


#### Testing Mutant 1 for failure

+ Pass: At least one test failed for Mutant 1


#### Testing Mutant 2 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Days between calculation seems to be much larger than it should be.


#### Testing Mutant 3 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Dates from GetDate are missing a character


#### Testing Mutant 4 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Today's date month off by one


#### Testing Mutant 5 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - 1/1/2016 to 3/1/2016 is 60 days, but this version returns 59


#### Testing Mutant 6 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - Dates from GetUsDate are not in the right format (same as GetDate?)


#### Testing Mutant 7 for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - operator-: Probably a copy paste error


#### Testing Mutant 8 for failure

+ Pass: At least one test failed for Mutant 8


#### Testing Mutant 9 for failure

+ Pass: At least one test failed for Mutant 9

