#include <array>
#include <iostream>
#include <numeric>

int main()
{
  std::array<double, 8> arr;
  std::iota(arr.begin(), arr.end(), 10.456);

  for (auto e: arr) {
    std::cout << e << ", ";
  }
  std::cout << std::endl;
}