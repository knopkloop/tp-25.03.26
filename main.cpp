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
  constexpr size_t size = 2ull;
  Vector< int > v(2ull, 10);
  return v.getSize() == size;
}

bool testCapacityOfEmptyVector(const char ** pname)
{
  *pname = __func__;
  Vector< int > v;
  return v.getCapacity() == 0ull;
}

bool testCapacityOfVectorAfterConstruct(const char ** pname)
{
  *pname = __func__;
  constexpr size_t size = 5ull;
  Vector< int > v(5ull, 10);
  return v.getCapacity() == size;
}

bool testPushBackOnEmptyVector(const char ** pname)
{
  *pname = __func__;
  Vector< int > v;
  v.pushBack(2);
  return v.getSize() == 1ull && !v.isEmpty();
}

bool testPushBackOnNonEmptyVector(const char ** pname)
{
  *pname = __func__;
  constexpr size_t size = 5ull;
  Vector< int > v(5ull, 2);
  v.pushBack(12);
  return v.getSize() == size + 1;
}

bool testPopBackOnEmptyVector(const char ** pname)
{
  *pname = __func__;
  Vector< int > v;
  try
  {
    v.popBack();
  }
  catch(const std::out_of_range &)
  {
    return true;
  }
  return false;
}

bool testPopBackOnNonEmptyVector(const char ** pname)
{
  *pname = __func__;
  constexpr size_t size = 5ull;
  Vector< int > v(5ull, 10);
  v.popBack();
  return v.getSize() == size - 1;
}

int main()
{
  using test_t = bool(*)(const char **);
  using case_t = std::pair< test_t, const char * >;
  case_t tests[] = {
    { testConstructAndDestruct, "Vector must be default constructable" },
    { testDefaultVectorIsEmpty, "Default constructed vector must be empty" },
    { testSizeOfEmptyVector, "Size of empty vector must be zero" },
    { testSizeOfNonEmptyVector, "Size of non-empty vector must be positive" },
    { testCapacityOfEmptyVector, "Empty vector capacity must be zero" },
    { testCapacityOfVectorAfterConstruct, "Capacity after construction must equal size" },
    { testPushBackOnEmptyVector, "Size of empty vector after pushBack must be 1" },
    { testPushBackOnNonEmptyVector, "Size of non-empty vector after pushBack must increase" },
    { testPopBackOnEmptyVector, "PopBack on empty vector must throw exception" },
    { testPopBackOnNonEmptyVector, "Size of non-empty vector after popBack must decrease" }
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
