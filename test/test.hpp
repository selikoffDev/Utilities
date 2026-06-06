#ifndef TEST_HPP
#define TEST_HPP

#include "logging/logger.hpp"

#include <string>
#include <vector>

enum TestState {
   INCOMPLETE,
   RUNNING,
   PASSED,
   FAILED,
   INVALID
};

struct Test {

   Test(const std::string& name, bool (*func)());

   void runTest();

   std::string mName;
   TestState mState;
   bool (*mTestFunc)();
   
};

struct TestSet {
   TestSet(const std::string& name);

   void registerTest(Test test);
   void runTests();

   void genReport() const;
   std::string genBanner() const;
   std::string genResult(const Test& tst) const;

   Logger lgr;
   std::string mName;
   std::vector<Test> mTests;
   size_t mMaxTestNameSize {0};
};
#endif
