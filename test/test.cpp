#include <iostream>
#include <sstream>

#include "test.hpp"

Test::Test(const std::string& name, bool (*func)()) 
   : mName(name),
     mState(TestState::INCOMPLETE),
     mTestFunc(func)
{}

void Test::runTest() {
   mState = TestState::RUNNING;

   if (mTestFunc) {
      mState =  mTestFunc() ? TestState::PASSED : TestState::FAILED;
   }
   else {
      mState = TestState::INVALID;
   }
}

TestSet::TestSet(const std::string& name)
   : mName(name)
{}

void TestSet::registerTest(Test test) {
   mTests.push_back(test);
}

void TestSet::runTests() {
   for (Test& test:mTests) {
      test.runTest();
   }
}

void TestSet::genReport() const{
   std::cout << genBanner();

   for (auto test:mTests) {
      std::cout << "\t" << test.mName << " -> ";
      switch (test.mState) {
      case TestState::INCOMPLETE:
         std::cout << "Incomplete!" << std::endl;
         break;
      case TestState::RUNNING:
         std::cout << "Running!" << std::endl;
         break;
      case TestState::PASSED:
         std::cout << "Passed!" << std::endl;
         break;
      case TestState::FAILED:
         std::cout << "Failed!" << std::endl;
         break;
      case TestState::INVALID:
         std::cout << "Invalid!" << std::endl;
         break;
      }
   }
}

std::string TestSet::genBanner() const {
   std::ostringstream os {""};

   os << "| " << mName << " |";

   std::string startString {" Test Set "};
   std::string endString {" Results "};
   std::string nameString { os.str() };
   size_t bannerTextLen {
      startString.length() + endString.length() + nameString.length()
   };

   os.str("");
   os.clear();

   size_t bannerWidth = 80;
   size_t padAmount = bannerWidth - bannerTextLen;
   size_t padHalf = padAmount >> 1;
   std::string startPad {""};
   std::string endPad {""};
   if (padHalf*2 == padAmount) {
      startPad = std::string(padHalf,'*');
      endPad = std::string(padHalf,'*');
   }
   else {
      startPad = std::string(padHalf,'*');
      endPad = std::string(padHalf+1,'*');
   }

   os << lgr.constructAnsiString(MAGENTA_FG_BRIGHT,BOLD) << startPad
      << startString << lgr.constructAnsiString(RED_FG_BRIGHT,ITALIC)
      << nameString  << lgr.mAnsiReset << lgr.constructAnsiString(MAGENTA_FG_BRIGHT,BOLD)
      << endString   << endPad << lgr.mAnsiReset << std::endl << std::endl;

   return os.str();
}

std::string TestSet::genResult() const {
   std::ostringstream os {""};

   return os.str();
}
