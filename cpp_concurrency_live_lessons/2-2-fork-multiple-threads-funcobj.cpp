#include <thread>
#include <iostream>
#include <vector>
#include <chrono>

using std::vector, std::cout, std::endl, std::thread;

class FunObj {
public:
    FunObj(int i) : _i(i) {}
    void operator()() {
        cout << "Hello from thread --> " << _i << endl;
    }
private:
    int _i;
};

vector<thread> spawn() {
    vector<thread> threads;
    for (int i=0; i <16; ++i) {
        threads.emplace_back(FunObj(i));
    }
    return threads;
}

int main() {
    auto threads = spawn();
    cout << "hello from, main\n";
    for (auto &t : threads)
        t.join();
}

