#include "pe-vector.hpp"
#include <iostream>
#include <cstring>

using knk::Vector;

bool testConstructAndDestruct(const char** pname)
{
  *pname = __func__;
  knk::Vector< int > v;
  return true;
}

bool testDefaultVectorIsEmpty(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  return v.isEmpty();
}

bool testSizeOfEmptyVector(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  return !v.getSize();
}

bool testSizeOfNonEmptyVector(const char** pname)
{
  *pname = __func__;
  constexpr size_t size = 2ull;
  Vector< int > v(2ull, 10);
  return v.getSize() == size;
}

bool testCapacityOfEmptyVector(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  return v.getCapacity() == 0ull;
}

bool testCapacityOfVectorAfterConstruct(const char** pname)
{
  *pname = __func__;
  constexpr size_t size = 5ull;
  Vector< int > v(5ull, 10);
  return v.getCapacity() == size;
}

bool testPushBackOnEmptyVector(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  v.pushBack(2);
  return v.getSize() == 1ull && !v.isEmpty();
}

bool testPushBackOnNonEmptyVector(const char** pname)
{
  *pname = __func__;
  constexpr size_t size = 5ull;
  Vector< int > v(5ull, 2);
  v.pushBack(12);
  return v.getSize() == size + 1;
}

bool testPushBackRepeat(const char** pname)
{
  *pname = __func__;
  Vector< int > v(10ull, 12);
  const size_t size = v.getSize();
  constexpr int value = 17;
  constexpr size_t repeats = 5ull;
  v.pushBackRepeat(value, repeats);
  return v.getSize() == size + repeats && v[size] == value;
}

bool testPushFrontOnEmptyVector(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  constexpr int value = 2;
  v.pushFront(value);
  return v.getSize() == 1ull && v.at(0) == value;
}

bool testPushFrontOnNonEmptyVector(const char** pname)
{
  *pname = __func__;
  constexpr size_t size = 5ull;
  constexpr int value = 7;
  Vector< int > v(5ull, 2);
  v.pushFront(value);
  return v.getSize() == size + 1 && v.at(0) == value;
}

bool testPopBackOnEmptyVector(const char** pname)
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

bool testPopBackOnNonEmptyVector(const char** pname)
{
  *pname = __func__;
  constexpr size_t size = 5ull;
  Vector< int > v(5ull, 10);
  v.popBack();
  return v.getSize() == size - 1;
}

bool testElementCheckedAccess(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  v.pushBack(2);
  try
  {
    int& r = v.at(0);
    return r == 2;
  }
  catch(...)
  {
    return false;
  }
}

bool testElementCheckedOutOfBoundAccess(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  try
  {
    v.at(0);
    return false;
  }
  catch(const std::out_of_range &e)
  {
    const char* text = e.what();
    return !std::strcmp("id out of bound", text);
  }
  catch(...)
  {
    return false;
  }
}

bool testElementCheckedConstAccess(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  v.pushBack(2);
  const Vector< int >& rv = v;
  try
  {
    const int& r = rv.at(0);
    return r == 2;
  }
  catch(...)
  {
    return false;
  }
}

bool testElementCheckedOutOfBoundConstAccess(const char** pname)
{
  *pname = __func__;
  const Vector< int > v;
  try
  {
    v.at(0);
    return false;
  }
  catch(const std::out_of_range &e)
  {
    const char* text = e.what();
    return !std::strcmp("id out of bound", text);
  }
  catch(...)
  {
    return false;
  }
}

bool testBracketRead(const char** pname)
{
  *pname = __func__;
  Vector<int> v;
  v.pushBack(10);
  v.pushBack(20);
  v.pushBack(30);

  return v[0] == 10 && v[1] == 20 && v[2] == 30;
}

bool testBracketWrite(const char** pname)
{
  *pname = __func__;
  Vector<int> v(3, 0);

  v[0] = 100;
  v[1] = 200;
  v[2] = 300;

  return v[0] == 100 && v[1] == 200 && v[2] == 300;
}

bool testConstBracketRead(const char **pname)
{
  *pname = __func__;
  Vector<int> v;
  v.pushBack(42);
  v.pushBack(77);

  const Vector<int>& cv = v;
  return cv[0] == 42 && cv[1] == 77;
}

bool testCopyConstructor(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);

  Vector< int > yav = v;

  if(v.isEmpty() || yav.isEmpty())
  {
    throw std::logic_error("Vectors is expected to be non-empty");
  }

  bool isEqual = (yav.getSize() == v.getSize());

  for (size_t i = 0; isEqual && i < v.getSize(); ++i)
  {
    try
    {
      isEqual = v.at(i) == yav.at(i);
    }
    catch(...)
    {
      return false;
    }
  }
  return isEqual;
}

bool testMoveConstructor(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);

  const size_t originalSize = v.getSize();

  Vector< int > moved(std::move(v));

  if (moved.getSize() != originalSize)
  {
    return false;
  }
  for (size_t i = 0; i < originalSize; ++i)
  {
    try
    {
      if (moved.at(i) != static_cast< int >(i) + 1)
      {
        return false;
      }
    }
    catch(...)
    {
      return false;
    }
  }
  return true;
}

bool testCopyAssignment(const char** pname)
{
  *pname = __func__;
  Vector< int > v1;
  v1.pushBack(10);
  v1.pushBack(20);

  Vector< int > v2;
  v2.pushBack(99);

  v2 = v1;

  if (v2.getSize() != v1.getSize())
  {
    return false;
  }
  for (size_t i = 0; i < v1.getSize(); ++i)
  {
    try
    {
      if (v1.at(i) != v2.at(i))
      {
        return false;
      }
    }
    catch(...)
    {
      return false;
    }
  }
  return true;
}

bool testMoveAssignment(const char** pname)
{
  *pname = __func__;
  Vector< int > v1;
  v1.pushBack(100);
  v1.pushBack(200);

  Vector< int > v2;
  v2.pushBack(1);

  const size_t v1Size = v1.getSize();

  v2 = std::move(v1);

  if (v2.getSize() != v1Size)
  {
    return false;
  }
  try
  {
    if (v2.at(0) != 100 || v2.at(1) != 200)
    {
      return false;
    }
  }
  catch(...)
  {
    return false;
  }
  return true;
}

bool testSwap(const char** pname)
{
  *pname = __func__;
  Vector< int > v1;
  v1.pushBack(1);
  v1.pushBack(2);

  Vector< int > v2;
  v2.pushBack(10);
  v2.pushBack(20);
  v2.pushBack(30);

  v1.swap(v2);
  if (v1.getSize() != 3ull || v1[0] != 10 || v1[1] != 20 || v1[2] != 30) return false;
  if (v2.getSize() != 2ull || v2[0] != 1  || v2[1] != 2)  return false;

  return true;
}

bool testInsertSingle(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  v.pushBack(1);
  v.pushBack(3);
  try
  {
    v.insert(1, 2);
    return v.getSize() == 3 && v[1] == 2;
  }
  catch(...)
  {
    return false;
  }
}

bool testInsertSingleOutOfBound(const char** pname)
{
  *pname = __func__;
  Vector< int > v;
  v.pushBack(1);
  try
  {
    v.insert(2, 99);
    return false;
  }
  catch(const std::out_of_range &e)
  {
    const char* text = e.what();
    return !std::strcmp("id out of bound", text);
  }
  catch(...)
  {
    return false;
  }
}

bool testInsertRange(const char** pname)
{
  *pname = __func__;
  Vector< int > v1;
  v1.pushBack(1);
  v1.pushBack(4);
  Vector< int > v2;
  v2.pushBack(2);
  v2.pushBack(3);
  v2.pushBack(4);
  try
  {
    v1.insert(1, v2, 0, 2);
    return v1.getSize() == 4 && v1[0] == 1 && v1[1] == 2 && v1[2] == 3 && v1[3] == 4;
  }
  catch(...)
  {
    return false;
  }
}

bool testInsertRangeIdOutOfBound(const char** pname)
{
  *pname = __func__;
  Vector< int > v1;
  v1.pushBack(1);
  Vector< int > v2;
  v2.pushBack(2);
  try
  {
    v1.insert(2, v2, 0, 1);
    return false;
  }
  catch(const std::out_of_range &e)
  {
    const char* text = e.what();
    return !std::strcmp("id out of bound", text);
  }
  catch(...)
  {
    return false;
  }
}

bool testInsertRangeOutOfBound(const char** pname)
{
  *pname = __func__;
  Vector< int > v1;
  v1.pushBack(1);
  v1.pushBack(5);
  Vector< int > v2;
  v2.pushBack(2);
  v2.pushBack(3);
  v2.pushBack(4);
  try
  {
    v1.insert(2, v2, 1, v2.getSize() + 1);
    return false;
  }
  catch(const std::out_of_range &e)
  {
    const char* text = e.what();
    return !std::strcmp("range out of bound", text);
  }
  catch(...)
  {
    return false;
  }
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
    { testPushBackOnEmptyVector, "Size of empty vector after pushBack must be equal 1" },
    { testPushBackOnNonEmptyVector, "Size of non-empty vector after pushBack must increase" },
    { testPushBackRepeat, "Size of vector after pushBackRepeat must increase on repeats count and first of the new elements must be equal value"},
    { testPushFrontOnEmptyVector, "Size of empty vector after pushFront must be equal 1"},
    { testPushFrontOnNonEmptyVector, "First element of non-empty vector after pushFront must be equal value and size must increase"},
    { testPopBackOnEmptyVector, "PopBack on empty vector must throw exception" },
    { testPopBackOnNonEmptyVector, "Size of non-empty vector after popBack must decrease" },
    { testInsertSingle, "Insert of single element must place element at id" },
    { testInsertSingleOutOfBound, "Insert of single element must generate exception with specific text, if id out of bound" },
    { testInsertRange, "Insert of range must copy elements from source range" },
    { testInsertRangeIdOutOfBound, "Insert of range must generate exception with specific text, if id out of bound" },
    { testInsertRangeOutOfBound, "Insert of range must generate exception with specific text, if range out of bound" },
    { testElementCheckedAccess, "Inbound access must return lvalue reference or generate exception with specific text" },
    { testElementCheckedOutOfBoundAccess, "Out of bound access must generate exception with specific text" },
    { testElementCheckedConstAccess, "Same as inbound access, but const" },
    { testElementCheckedOutOfBoundConstAccess, "Same as out of bound, but const" },
    { testBracketRead, "Non-const operator[] must return correct values"},
    { testBracketWrite, "Non-const operator[] must return modifiable lvalue reference"},
    { testConstBracketRead, "Const operator[] must work on const vector reference"},
    { testCopyConstructor, "Copied vector must be equal to original" },
    { testMoveConstructor, "Moved constructor must take ownership of data"},
    { testCopyAssignment, "Copy assignment must takes vectors equal"},
    { testMoveAssignment, "Move assignment must transfer ownership"},
    { testSwap, "Swap must exchange contents of two vectors"}
  };

  constexpr size_t count = sizeof(tests) / sizeof(case_t);
  size_t failed = 0;
  for (size_t i = 0; i < count; ++i)
  {
    const char * testName = nullptr;
    bool r = false;
    try
    {
      r = tests[i].first(&testName);
    }
    catch(const std::logic_error& e)
    {
      std::cout << "[NOT RUN] " << testName << "\n";
      std::cout << "\t" << "Reason: " << e.what() << "\n";
      ++failed;
      continue;
    }
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
