#include <thread>
#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl, std::thread;

int main() {
    vector<thread> threads;
    for (int i=0; i <16; ++i) {
        threads.emplace_back([]
                {
                    cout << "hello from thread \n";
                }
                );
    }
    cout << "hello from, main\n";
    for (auto &t : threads)
        t.join();
}

