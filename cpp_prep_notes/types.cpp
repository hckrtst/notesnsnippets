#include <iostream>

int main() {
  int x = 1234567891919191919; // trigger overflow warning
  std::cout << x << std::endl;
  std::cout << sizeof(x) << std::endl;
}

/*
double has more precision than float

https://stackoverflow.com/questions/2386772/what-is-the-difference-between-float-and-double

https://drdobbs.com/floating-point-summation/184403224

https://en.wikipedia.org/wiki/Kahan_summation_algorithm

*/