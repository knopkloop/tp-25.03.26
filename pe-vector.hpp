#ifndef PE_VECTOR_HPP
#define PE_VECTOR_HPP
#include <cstddef>

namespace knk
{
  template < class T >
  class Vector
  {
  public:
    ~Vector();
    Vector();
    explicit Vector(size_t size);
    Vector(size_t size, const T& value);

    Vector(const Vector< T >& rhs) = delete;
    Vector< T >& operator=(const Vector< T >& rhs) = delete;

    bool isEmpty() const noexcept;
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;

    void pushBack(const T& rhs);
    void popBack();

  private:
    T* data_;
    size_t size_, capacity_;
  };
}

template< class T >
knk::Vector< T >::~Vector()
{
  delete[] data_;
}

template< class T >
knk::Vector< T >::Vector():
  data_(nullptr),
  size_(0),
  capacity_(0)
{}

template< class T>
knk::Vector< T >::Vector(size_t size):
  data_(size ? new T[size] : nullptr),
  size_(size),
  capacity_(size)
{}

template< class T >
knk::Vector< T >::Vector(size_t size, const T& value):
  Vector(size)
{
  for (size_t i = 0; i < size; ++i)
  {
    data_[i] = value;
  }
}

template< class T >
bool knk::Vector< T >::isEmpty() const noexcept
{
  return !size_;
}

template< class T >
size_t knk::Vector< T >::getSize() const noexcept
{
  return size_;
}

template< class T >
size_t knk::Vector< T >::getCapacity() const noexcept
{
  return capacity_;
}

#endif
