#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <future>
#include <memory>

using std::vector, std::cout, std::endl, std::thread, std::string;

string func(bool flag) {
    if (flag) {
        cout << "worker returning\n";
        return "Message from worker";
    }
    // in the course he used std::exception here but that does not get recaught for me
    // this works
    throw std::runtime_error("bad bad thread");
}

int main() {
    std::future<std::string> fut = std::async(func, true);
    std::future<std::string> fut2 = std::async(func, false);
    cout << "Main receiving....\n";
    try {
        cout << fut.get() << endl;
        cout << fut2.get() << endl;
    }
    catch(const std::exception& e)
    {
        cout << " got exception: " << e.what() << endl;
    }
}

