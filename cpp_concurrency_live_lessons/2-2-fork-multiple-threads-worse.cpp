#include <thread>
#include <iostream>
#include <vector>
#include <chrono>

using std::vector, std::cout, std::endl, std::thread;

vector<thread> spawn() {
    vector<thread> threads;
    for (int i=0; i <16; ++i) {
        threads.emplace_back([&]
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(10*i));
                    cout << "hello from thread \t\t " << i << endl;
                }
                );
    }
    return threads;
}

int main() {
    auto threads = spawn();
    cout << "hello from, main\n";
    for (auto &t : threads)
        t.join();
}

