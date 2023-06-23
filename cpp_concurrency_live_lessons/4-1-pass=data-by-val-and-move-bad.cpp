#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <future>
#include <memory>


struct Counter {
    Counter(int k) : n(k) {}
    int n;
};

int main() {
    Counter *pCount = new Counter(10);
   
    std::cout << "before thread spanwed : pcount has " << pCount->n << std::endl; /// ---> oops! no telling what value this will print!!!!!
    /// caution....now we already have a ptr to the data
    std::unique_ptr<Counter> upC(pCount);
    // the new thread will 'own'
    // this data
    std::future<void> fut = std::async([](std::unique_ptr<Counter> p) {
            ++(p->n);
            }, std::move(upC));
    fut.wait();
    // so far no errors because no one else is modifying/reading it in main thread
    // but...
    // say someone adds line below
    std::cout << "after thread spawned: pcount has " << pCount->n << std::endl; /// ---> oops! no telling what value this will print!!!!!
}

