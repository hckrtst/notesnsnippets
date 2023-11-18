#pragma once

#include <exception>
#include <iostream>
#include <array>
#include <memory>


using std::cout, std::endl, std::array;

class StackException : public std::exception {
  const char *msg;
  StackException() = delete;
public:
  explicit StackException(const char *s) : msg(s) { }
  const char *what() const noexcept { return msg; }
};

template <typename T>
class Stack {
  static const int _defaultSize = 10;
  static const int _maxSize = 1000;
  int _size{}, _top{-1};
  std::unique_ptr<array<T, _defaultSize>> _p_data;

  bool _is_full() {
    return (_top == (_maxSize - 1));
  }

  public:
  explicit Stack(int s = _defaultSize) : _size(s) {
    if ((s < 1) || (s > _maxSize)) {
      throw StackException("invalid stack size");
    }
    _p_data = std::make_unique<array<T, this->_size>>(); 
  }

  void push(const T &item) {
    if _is_full() throw StackException("stack is full");
    if (_size - 1 == _top) {
      // grow capacity
      _size = std::min((2 * _size), _maxSize);
      auto data = new std::array<T,this->_size>();
      // copy existing elems to new array
      for (int i = 0; i < _p_data->size(); i++) {
        (*data)[i] = (*_p_data.get())[i];    
      } 
      cout << "new size: " << _size << endl;
      _p_data.reset(data);
    }
    (*_p_data.get())[++_top] = item;
  }

  T& pop() {
    if (isEmpty()) throw StackException("already empty");
    return *(_p_data.get())[_top--];  
  }

  bool isEmpty() {
    return (_top < 0);
  }

  void print() {
    if (isEmpty()) {
      cout << "empty\n";
    }


    for (int i = 0 ; i <= _top; i++) {
      cout << *(_p_data.get())[i] << ", ";    
    } 
    cout << '\n';
  }

};