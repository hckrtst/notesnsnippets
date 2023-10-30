#include <iostream>

int main() {
  int* ptr1 = nullptr;
  int*& ref1 = ptr1; // this is ok
  std::cout << "ref1 is " << ref1 << std::endl;
  int& ref2 = *ptr1; // this is allowed but illegal
  std::cout << "ref2 is " << ref2 << std::endl; // this seg faults when we try to use ref2

}