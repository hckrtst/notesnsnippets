#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <future>
#include <memory>
#include <filesystem>
#include <sstream>
#include <assert.h>

namespace fs = std::filesystem;
using std::future, std::cout, std::endl, std::vector, std::string, std::recursive_mutex;

class Account {
    // declared as mutable since balance() also calls this but we need
    // to have ability to explicity lock and unlock on this mutex
    // hence it needs to be mutable even in a const method
    mutable std::recursive_mutex _mutex;
    int _balance;
    public:
    
    Account() : _balance(0) {}
    void deposit(int sum) {
        std::lock_guard<std::recursive_mutex> lck(_mutex);
        _balance += sum;
    }
    int balance() const {
        std::lock_guard<std::recursive_mutex> lck(_mutex);
        return _balance;
    }
    
    recursive_mutex& getMutex() const {
        return _mutex;
    }

};

future<void> depositor(Account &acct, int sum) {
    return std::async([&](int sum) {
            acct.deposit(sum);
            },
            sum);
}

future<void> balancer(Account const & acct) {
    return std::async([&](){
            cout << "Balance: " << acct.balance() << endl;
            });
}

class Bank
{
    std::array<Account, 2>_accts;
    int _minBal;
    public:
    Bank(int minBal) : _minBal(minBal) {
        _accts[0].deposit(minBal);
    }

    void transfer(int from, int to, int sum) {
        std::lock(_accts[from].getMutex(), _accts[to].getMutex());
        // we use 'adopt_lock' to signify that the locak guard should
        // only unlock it at end of block, as it is already locked above
        std::lock_guard<recursive_mutex> lck1(_accts[from].getMutex(), std::adopt_lock);
        std::lock_guard<recursive_mutex> lck2(_accts[to].getMutex(), std::adopt_lock);

        // this operation is not atomic even though each separate call to balance() and deposit() use lock guard!!!
        if (_accts[from].balance() >= sum) {
            _accts[from].deposit(-sum); // take money from one acct
            _accts[to].deposit(sum); // add to the other acct
        }
    }

    void assertPositive() const {
        auto from{0}, to{1};
        std::lock(_accts[from].getMutex(), _accts[to].getMutex());
        // we use 'adopt_lock' to signify that the locak guard should
        // only unlock it at end of block, as it is already locked above
        std::lock_guard<recursive_mutex> lck1(_accts[from].getMutex(), std::adopt_lock);
        std::lock_guard<recursive_mutex> lck2(_accts[to].getMutex(), std::adopt_lock);


        if ((_accts[0].balance() < 0) || (_accts[1].balance() < 0)) {
            std::cerr << "negative!\n";
            throw std::runtime_error("Negative balance");
        }
    }

    void assertSolvent() const {
        // not covered in course, but we also need to protect these assert functions
        // otherwise we see random asserts!!!
        auto from{0}, to{1};
        std::lock(_accts[from].getMutex(), _accts[to].getMutex());
        // we use 'adopt_lock' to signify that the locak guard should
        // only unlock it at end of block, as it is already locked above
        std::lock_guard<recursive_mutex> lck1(_accts[from].getMutex(), std::adopt_lock);
        std::lock_guard<recursive_mutex> lck2(_accts[to].getMutex(), std::adopt_lock);

        auto total = _accts[0].balance() + _accts[1].balance();
        if (total < _minBal) {
            std::cerr << "bailout pls: total " << total << " < min bal of " << _minBal << std::endl;
            throw std::runtime_error("Oh no...need bailout");
        }
    }
};

future<void> trans(Bank & bank, int from, int to, int sum) {
    return std::async(std::launch::async, [&](int from, int to, int sum){
            bank.assertPositive();
            bank.transfer(from, to, sum);
            bank.assertSolvent();
            }, from, to, sum);

}
int main() {
    try {
        Bank bank(10);
        vector<future<void>> futs;
        // increasing too many futures can cause exceptions
        // possibly due to memory issues
        for (int i = 0; i < 2000; ++i) {
            futs.emplace_back(trans(bank, 0, 1, 10));
            futs.emplace_back(trans(bank, 1, 0, 10));
        }
        for (auto &fut : futs) {
            fut.get();
        }

    } catch(std::exception e)
    {
        cout << "exception --> " << e.what() << endl;
    }
}

