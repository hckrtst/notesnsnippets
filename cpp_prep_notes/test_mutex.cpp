#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

int num = 0; // protect with mutex
std::mutex num_mutex;


void slow_inc(int id)
{
  num_mutex.lock();
  ++num;
  std::cout << "id: " << id << " num = " << num << '\n';
  num_mutex.unlock();
  std::this_thread::sleep_for(std::chrono::milliseconds(123));
}

int main()
{
  std::thread t1{slow_inc, 0};
  std::thread t2{slow_inc, 10};
  std::thread t3{slow_inc, 20};
  
  // need to manually join these
  t1.join();
  t2.join();
  t3.join();
}