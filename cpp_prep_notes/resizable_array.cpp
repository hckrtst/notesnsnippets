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

    //_leaky = std::make_unique<int>(10);
    
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
  // We make sure to resize if running out of space
  // pop_back
  // get size
  // print
  // resize

  private:
  std::unique_ptr<int[]> _data;
  std::unique_ptr<int> _leaky{new int[10]}; // This is to demonstrate leaks
  /*
  valgrind output:
  ==32405== Mismatched free() / delete / delete []
==32405==    at 0x483A08B: operator delete(void*, unsigned long) (vg_replace_malloc.c:593)
==32405==    by 0x109B95: std::default_delete<int>::operator()(int*) const (unique_ptr.h:85)
==32405==    by 0x10988F: std::unique_ptr<int, std::default_delete<int> >::~unique_ptr() (unique_ptr.h:361)
==32405==    by 0x1096CB: Resizable_int_array::~Resizable_int_array() (resizable_array.cpp:7)
==32405==    by 0x1092E9: main (resizable_array.cpp:71)
==32405==  Address 0x4d68c80 is 0 bytes inside a block of size 40 alloc'd
==32405==    at 0x483950F: operator new[](unsigned long) (vg_replace_malloc.c:431)
==32405==    by 0x109418: Resizable_int_array::Resizable_int_array() (resizable_array.cpp:11)
==32405==    by 0x109239: main (resizable_array.cpp:71)
==32405==
==32405==
==32405== HEAP SUMMARY:
==32405==     in use at exit: 0 bytes in 0 blocks
==32405==   total heap usage: 9 allocs, 9 frees, 75,027 bytes allocated
==32405==
==32405== All heap blocks were freed -- no leaks are possible
==32405==
==32405== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
==32405==
==32405== 1 errors in context 1 of 1:
==32405== Mismatched free() / delete / delete []
==32405==    at 0x483A08B: operator delete(void*, unsigned long) (vg_replace_malloc.c:593)
==32405==    by 0x109B95: std::default_delete<int>::operator()(int*) const (unique_ptr.h:85)
==32405==    by 0x10988F: std::unique_ptr<int, std::default_delete<int> >::~unique_ptr() (unique_ptr.h:361)
==32405==    by 0x1096CB: Resizable_int_array::~Resizable_int_array() (resizable_array.cpp:7)
==32405==    by 0x1092E9: main (resizable_array.cpp:71)
  
  */
  unsigned int _size{10};
};


// TODO do a template based implementation


// also see https://www.cppstories.com/2021/smartptr-array/
int main() {

  Resizable_int_array arr;
  std::cout << arr.to_str() << std::endl;
  arr.resize(23);
  std::cout << arr.to_str() << std::endl;
  return 0;
}

