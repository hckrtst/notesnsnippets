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
struct Holder {
    Holder(int n) : c(new Counter(n)) 
    {

    }
    Counter *c;
};

int main() {
    const Holder h(10);
    std::future<void> fut = std::async([](Holder const & h) {
            ++(h.c->n); // this is legit even though h is const
            }, std::ref(h) /* explicit reference */);
    std::cout << h.c->n << std::endl;
    fut.wait();

    std::cout << h.c->n << std::endl;
}

