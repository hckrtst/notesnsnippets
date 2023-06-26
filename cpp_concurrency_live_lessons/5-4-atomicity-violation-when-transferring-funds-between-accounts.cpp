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
        if (_accts[from].balance() >= sum) {
            _accts[from].deposit(-sum); // take money from one acct
            _accts[to].deposit(sum); // add to the other acct
        }
    }

    void assertPositive() const {
        if ((_accts[0].balance() < 0) || (_accts[1].balance() < 0)) {
            std::cerr << "negative!\n";
            throw std::runtime_error("Negative balance");
        }
    }

    void assertSolvent() const {
        if ((_accts[0].balance() + _accts[1].balance()) < _minBal) {
            std::cerr << "bailout pls\n";
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
        for (int i = 0; i < 50000; ++i) {
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

