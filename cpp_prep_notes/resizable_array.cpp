#include <iostream>
#include <cassert>
#include <memory>
#include <array>
#include <sstream>

class Resizable_int_array {
  public:
  // construct
  Resizable_int_array()
  {
    _data = std::make_unique<int[]>(_size);
    for (unsigned int i = 0; i < _size; i++) {
      (_data.get())[i] = i;
    }

    
  }
  
  std::string to_str() {
    std::stringstream st;
    for (unsigned int i = 0; i < _size; i++) {
      st << (_data.get())[i] << ", ";
    }
    return st.str();
  }

  void resize(unsigned int n) {
    if (n < _size) {
      std::cerr << "Invalid\n";
      return;
    }
    if (n == _size) return;

    int *new_data = new int[n];
    for (unsigned int i = 0; i < _size; i++) {
      new_data[i] = _data[i];
    }

    for (unsigned int i = _size; i < n; i++) {
      new_data[i] = 0;
    }

    _data.reset(new_data);
    _size = n;

  }
  // implement copy, move
  // insert an element at a pos
  // remove element from a pos
  // clear
  // push_back
  // pop_back
  // get size
  // print
  // resize

  private:
  std::unique_ptr<int[]> _data;
  unsigned int _size{10};
};


// TODO do a template based implementation

int main() {

  Resizable_int_array arr;
  std::cout << arr.to_str() << std::endl;
  arr.resize(23);
  std::cout << arr.to_str() << std::endl;
  return 0;
}

