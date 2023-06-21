#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <future>

using std::vector, std::cout, std::endl, std::thread, std::string;

void func(std::promise<string> &&pr) {
    cout << "sending a string back to main thread\n";
    pr.set_value("Hello from thread");
}

int main() {
    std::promise<std::string> pr;
    std::future<std::string> fut = pr.get_future();
    std::thread th(func, std::move(pr));
    cout << "Main receiving....\n";
    cout << fut.get() << endl;
    th.join();
}

