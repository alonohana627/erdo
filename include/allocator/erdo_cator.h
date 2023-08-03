#ifndef ERDO_ALLOCATOR_H
#define ERDO_ALLOCATOR_H

#include <cstddef>
#include <iostream>
#include <limits>
#include <memory>
#include <vcruntime_new.h>

namespace erdo {


// Very basic Allocator in C++.
template <typename T> class ErdoCator {
public:
  using value_type = T;

  ErdoCator() noexcept = default;

  template <class U> ErdoCator(const ErdoCator<U> &) noexcept {}

  T *allocate(std::size_t n) {
    if (n > std::numeric_limits<std::size_t>::max() / sizeof(T)) {
      throw std::bad_alloc();
    }

    if (auto p = static_cast<T *>(::operator new(n * sizeof(T)))) {
      return p;
    }

    throw std::bad_alloc();
  }

  void deallocate(T *p, std::size_t n) noexcept {
    ::operator delete(p);
  }

  // C++20 changes: add template constructors and propagation methods
  using propagate_on_container_copy_assignment = std::true_type;
  using propagate_on_container_move_assignment = std::true_type;
  using propagate_on_container_swap = std::true_type;

  template <typename U> struct rebind {
    using other = ErdoCator<U>;
  };
};

template <typename T> class ErdoCator;

template <typename T, typename U>
bool operator==(const ErdoCator<T> &, const ErdoCator<U> &) noexcept {
  return true;
}

template <typename T, typename U>
bool operator!=(const ErdoCator<T> &a, const ErdoCator<U> &b) noexcept {
  return !(a == b);
}

} // namespace erdo

namespace std {
template <typename T> struct allocator_traits<erdo::ErdoCator<T>> {
  using allocator_type = erdo::ErdoCator<T>;
  using value_type = T;
  using pointer = T *;
  using const_pointer = const T *;
  using void_pointer = void *;
  using const_void_pointer = const void *;
  using difference_type = std::ptrdiff_t;
  using size_type = std::size_t;
  using propagate_on_container_copy_assignment = std::true_type;
  using propagate_on_container_move_assignment = std::true_type;
  using propagate_on_container_swap = std::true_type;
  
  template <typename U> using rebind_alloc = erdo::ErdoCator<U>;

  static pointer allocate(allocator_type &alloc, std::size_t n) {
    return alloc.allocate(n);
  }

  static void deallocate(allocator_type &alloc, pointer p, std::size_t n) {
    alloc.deallocate(p, n);
  }

  static size_type max_size(const allocator_type &alloc) noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  }

  template <typename U, typename... Args>
  static void construct(allocator_type &alloc, U *p, Args &&...args) {
    ::new (static_cast<void *>(p)) U(std::forward<Args>(args)...);
  }
  
  static allocator_type select_on_container_copy_construction(const allocator_type& a) {
    return a; // Simply return the original allocator.
  }
};

} // namespace std

#endif