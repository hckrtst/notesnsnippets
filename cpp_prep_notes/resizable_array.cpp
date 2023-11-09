#include <iostream>
#include <cassert>
#include <memory>
#include <array>

class Resizable_int_array {
  public:
  // construct
  Resizable_int_array()
  {
    _data = std::make_unique<int[]>(_size);
    for (unsigned int i = 0; i < _size; i++) {
      (_data.get())[i] = i;
    }

    for (unsigned int i = 0; i < _size; i++) {
      std::cout << "printed " << (_data.get())[i] << std::endl;
    }
  }
  // implement copy, move
  // insert an element at a pos
  // remove element from a pos
  // clear
  // push_back
  // pop_back
  // get size
  // print
  private:
  std::unique_ptr<int[]> _data;
  unsigned int _size{10};
};


// TODO do a template based implementation

int main() {

  Resizable_int_array arr;
  return 0;
}

