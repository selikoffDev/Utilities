#include <iostream>

#include "test.hpp"

Test::Test(const std::string& name, bool (*func)()) 
   : mName(name),
     mTestFunc(func),
     mState(TestState::INCOMPLETE)
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
   std::cout << \
"**************** Test Set | " << mName << " | Results **************************"\
      << std::endl << std::endl;

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
