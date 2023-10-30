#include <iostream>
#include <future>

void print_loop(int start, int end)
{
  std::cout << "hello";
  for (int i = start; i < end; i++)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main()
{
  std::future<void> asyncFunc = std::async(&print_loop, 1, 1000);
  
  //asyncFunc.get();

  std::cout << "bye \n"; 
}