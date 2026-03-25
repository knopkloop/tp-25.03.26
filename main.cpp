#include "pe-vector.hpp"
#include <iostream>

using knk::Vector;

bool testConstructAndDestruct(const char ** pname)
{
  *pname = __func__;
  knk::Vector< int > v;
  return true;
}

bool testDefaultVectorIsEmpty(const char ** pname)
{
  *pname = __func__;
  Vector< int > v;
  return v.isEmpty();
}

bool testSizeOfEmptyVector(const char ** pname)
{
  *pname = __func__;
  Vector< int > v;
  return !v.getSize();
}

bool testSizeOfNonEmptyVector(const char ** pname)
{
  *pname = __func__;
  return false;
}

int main()
{
  using test_t = bool(*)(const char **);
  using case_t = std::pair< test_t, const char * >;
  case_t tests[] = {
    {testConstructAndDestruct, "Vector must be default constructable"},
    {testDefaultVectorIsEmpty, "Default constructed vector must be empty"},
    {testSizeOfEmptyVector, "Size of empty vector must be zero"},
    {testSizeOfNonEmptyVector, "Size of non-empty vector must be positive"}
  };

  constexpr size_t count = sizeof(tests) / sizeof(case_t);
  size_t failed = 0;
  for (size_t i = 0; i < count; ++i)
  {
    const char * testName = nullptr;
    bool r = tests[i].first(&testName);
    if (!r)
    {
      ++failed;
      std::cout << "[FAIL] " << testName << "\n";
      std::cout << "\t" << tests[i].second << "\n";
    }
  }
  std::cout << "Summary: " << (count - failed) << " passed" << "\n";
  std::cout << "\t" << " " << count << " total" << "\n";
}
