#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <future>
#include <memory>

using std::vector, std::cout, std::endl, std::thread, std::string;

void func(std::promise<string> &&pr) {
    cout << "throwing exception\n";
    try {
        // in the course he used std::exception here but that does not get recaught for me
        // this works
        throw std::runtime_error("bad bad thread");
    }
    catch(...) {
        cout << "here\n";
        pr.set_exception(std::current_exception());
    }
}

int main() {
    std::promise<std::string> pr;
    std::future<std::string> fut = pr.get_future();
    std::thread th(func, std::move(pr));
    cout << "Main receiving....\n";
    try {
        cout << fut.get() << endl;
    }
    catch(const std::exception& e)
    {
        cout << " got exception: " << e.what() << endl;
    }
    th.join();
}

