#ifndef PE_ITERATORS
#define PE_ITERATORS

#include <cstddef>

namespace knk
{
  template< class T >
  class Vector;

  template< class T >
  class VCIter;

  template< class T >
  class VIter
  {
  public:
    VIter(Vector< T >&vec, size_t id) noexcept;
    ~VIter() = default;

    T& operator*() const noexcept;
    T* operator->() const noexcept;
    T& operator[](size_t k) const noexcept;

    VIter& operator++() noexcept;
    VIter operator++(int) noexcept;
    VIter& operator--() noexcept;
    VIter operator--(int) noexcept;

    VIter& operator+=(int n) noexcept;
    VIter& operator-=(int n) noexcept;
    VIter operator+(int n) const noexcept;
    VIter operator-(int n) const noexcept;
    int operator-(const VIter& other) const noexcept;

    bool operator==(const VIter& other) const noexcept;
    bool operator!=(const VIter& other) const noexcept;
    bool operator<(const VIter& other) const noexcept;
    bool operator>(const VIter& other) const noexcept;
    bool operator<=(const VIter& other) const noexcept;
    bool operator>=(const VIter& other) const noexcept;

  private:
    friend class VCIter< T >;
    T* ptr_;
  };

  template< class T >
  class VCIter
  {
  public:
    VCIter(const Vector< T >&vec, size_t id) noexcept;
    VCIter(const VIter< T >& other) noexcept;
    ~VCIter() = default;

    const T& operator*() const noexcept;
    const T* operator->() const noexcept;
    const T& operator[](size_t k) const noexcept;

    VCIter& operator++() noexcept;
    VCIter operator++(int) noexcept;
    VCIter& operator--() noexcept;
    VCIter operator--(int) noexcept;

    VCIter& operator+=(int n) noexcept;
    VCIter& operator-=(int n) noexcept;
    VCIter operator+(int n) const noexcept;
    VCIter operator-(int n) const noexcept;
    int operator-(const VCIter& other) const noexcept;

    bool operator==(const VCIter& other) const noexcept;
    bool operator!=(const VCIter& other) const noexcept;
    bool operator<(const VCIter& other) const noexcept;
    bool operator>(const VCIter& other) const noexcept;
    bool operator<=(const VCIter& other) const noexcept;
    bool operator>=(const VCIter& other) const noexcept;

  private:
    const T* ptr_;
  };
}

template< class T >
knk::VIter< T >::VIter(Vector< T >& vec, size_t id) noexcept:
  ptr_(&vec[id])
{
}

template< class T >
T& knk::VIter< T >::operator*() const noexcept
{
  return *ptr_;
}

template< class T >
T* knk::VIter< T >::operator->() const noexcept
{
  return ptr_;
}

template< class T >
T& knk::VIter< T >::operator[](size_t k) const noexcept
{
  return ptr_[k];
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator++() noexcept
{
  ++ptr_;
  return *this;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator++(int) noexcept
{
  VIter< T > tmp = *this;
  ++ptr_;
  return tmp;
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator--() noexcept
{
  --ptr_;
  return *this;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator--(int) noexcept
{
  VIter< T > tmp = *this;
  --ptr_;
  return tmp;
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator+=(int n) noexcept
{
  ptr_ += n;
  return *this;
}

template< class T >
knk::VIter< T >& knk::VIter< T >::operator-=(int n) noexcept
{
  ptr_ -= n;
  return *this;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator+(int n) const noexcept
{
  VIter< T > tmp = *this;
  tmp += n;
  return tmp;
}

template< class T >
knk::VIter< T > knk::VIter< T >::operator-(int n) const noexcept
{
  VIter< T > tmp = *this;
  tmp -= n;
  return tmp;
}

template< class T >
int knk::VIter< T >::operator-(const VIter< T >& other) const noexcept
{
  return static_cast< int >(ptr_ - other.ptr_);
}

template< class T >
bool knk::VIter< T >::operator==(const VIter< T >& other) const noexcept
{
  return ptr_ == other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator!=(const VIter< T >& other) const noexcept
{
  return ptr_ != other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator<(const VIter< T >& other) const noexcept
{
  return ptr_ < other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator>(const VIter< T >& other) const noexcept
{
  return ptr_ > other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator<=(const VIter< T >& other) const noexcept
{
  return ptr_ <= other.ptr_;
}

template< class T >
bool knk::VIter< T >::operator>=(const VIter< T >& other) const noexcept
{
  return ptr_ >= other.ptr_;
}

template< class T >
knk::VCIter< T >::VCIter(const Vector< T >& vec, size_t id) noexcept:
  ptr_(&vec[id])
{
}

template< class T >
knk::VCIter< T >::VCIter(const VIter< T >& other) noexcept:
  ptr_(other.ptr_)
{
}

template< class T >
const T& knk::VCIter< T >::operator*() const noexcept
{
  return *ptr_;
}

template< class T >
const T* knk::VCIter< T >::operator->() const noexcept
{
  return ptr_;
}

template< class T >
const T& knk::VCIter< T >::operator[](size_t k) const noexcept
{
  return ptr_[k];
}

template< class T >
knk::VCIter< T >& knk::VCIter< T >::operator++() noexcept
{
  ++ptr_;
  return *this;
}

template< class T >
knk::VCIter< T > knk::VCIter< T >::operator++(int) noexcept
{
  VCIter< T > tmp = *this;
  ++ptr_;
  return tmp;
}

template< class T >
knk::VCIter< T >& knk::VCIter< T >::operator--() noexcept
{
  --ptr_;
  return *this;
}

template< class T >
knk::VCIter< T > knk::VCIter< T >::operator--(int) noexcept
{
  VCIter< T > tmp = *this;
  --ptr_;
  return tmp;
}

template< class T >
knk::VCIter< T >& knk::VCIter< T >::operator+=(int n) noexcept
{
  ptr_ += n;
  return *this;
}

template< class T >
knk::VCIter< T >& knk::VCIter< T >::operator-=(int n) noexcept
{
  ptr_ -= n;
  return *this;
}

template< class T >
knk::VCIter< T > knk::VCIter< T >::operator+(int n) const noexcept
{
  VCIter< T > tmp = *this;
  tmp += n;
  return tmp;
}

template< class T >
knk::VCIter< T > knk::VCIter< T >::operator-(int n) const noexcept
{
  VCIter< T > tmp = *this;
  tmp -= n;
  return tmp;
}

template< class T >
int knk::VCIter< T >::operator-(const VCIter< T >& other) const noexcept
{
  return static_cast< int >(ptr_ - other.ptr_);
}

template< class T >
bool knk::VCIter< T >::operator==(const VCIter< T >& other) const noexcept
{
  return ptr_ == other.ptr_;
}

template< class T >
bool knk::VCIter< T >::operator!=(const VCIter< T >& other) const noexcept
{
  return ptr_ != other.ptr_;
}

template< class T >
bool knk::VCIter< T >::operator<(const VCIter< T >& other) const noexcept
{
  return ptr_ < other.ptr_;
}

template< class T >
bool knk::VCIter< T >::operator>(const VCIter< T >& other) const noexcept
{
  return ptr_ > other.ptr_;
}

template< class T >
bool knk::VCIter< T >::operator<=(const VCIter< T >& other) const noexcept
{
  return ptr_ <= other.ptr_;
}

template< class T >
bool knk::VCIter< T >::operator>=(const VCIter< T >& other) const noexcept
{
  return ptr_ >= other.ptr_;
}

#endif
