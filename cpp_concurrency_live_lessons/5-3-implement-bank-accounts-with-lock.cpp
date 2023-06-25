#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <future>
#include <memory>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;
using std::future, std::cout, std::endl, std::vector, std::string;

class Account {
    // declared as mutable since balance() also calls this but we need
    // to have ability to explicity lock and unlock on this mutex
    // hence it needs to be mutable even in a const method
    mutable std::mutex _mutex;
    int _balance;
    public:
    
    Account() : _balance(0) {}
    void deposit(int sum) {
        std::lock_guard<std::mutex> lck(_mutex);
        _balance += sum;
    }
    int balance() const {
        std::lock_guard<std::mutex> lck(_mutex);
        return _balance;
    }
};

int main() {
}

