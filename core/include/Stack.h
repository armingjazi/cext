#pragma once

namespace all {
template<typename T>
class Stack {
 public:
  explicit Stack(size_t size)
      : data_(new T[size]),
        size_(size),
        used_(0) {};
  Stack(const Stack &stack)
      : data_(new_copy(stack.data_, stack.size_, stack.size_)),
        size_(stack.size_),
        used_(stack.used_) {};
  Stack &operator=(const Stack &stack) {
    if (&stack == this)
      return *this;
    T* new_data = new_copy(stack.data_, stack.size_, stack.size_);
    delete[] data_;
    data_ = new_data;
    size_ = stack.size_;
    used_ = stack.used_;
    return *this;
  }
  ~Stack() {
    delete[] data_;
  };
  void push(const T &d) {
    if (used_ == size_) {
      T* new_data = new_copy(data_, size_, size_ * 2);
      delete[] data_;
      data_ = new_data;
      size_ = size_ * 2;
    }
    data_[used_] = d;
    ++used_;
  }

  const T& top() const {
    if (used_ == 0)
      throw std::runtime_error("empty stack");

    return data_[used_ - 1];
  }

  void pop() {
    if (used_ == 0)
      throw std::runtime_error("empty stack");

    --used_;
  }

  size_t count() {
    return used_;
  }

 private:
  T *data_;
  size_t size_;
  size_t used_;

  T *new_copy(const T *src, size_t srcSize, size_t destSize) {
    T *dest = new T[destSize];
    for (int i = 0; i < srcSize; ++i)
      dest[i] = src[i];
    return dest;
  }
};
}