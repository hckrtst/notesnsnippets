#include "const_test.h"
#include <iostream>
// header didn't declare the input as const
// but we make it clear for impl that it is const even
// if by value so we cannot change it
int Math::square(const int n) const
{
  // n = 10; --> illegal since we declared const here
  return n * n;
}

int main()
{
  Math m;
  std::cout << m.square(12) << std::endl;
  return 0;
}