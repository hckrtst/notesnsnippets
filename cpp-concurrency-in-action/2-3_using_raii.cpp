#include <iostream>
#include <thread>

using std::cout, std::endl, std::thread;

class thread_guard {
    std::thread& _t;
public:
    explicit thread_guard(std::thread& t):
        _t(t)
    {}

    ~thread_guard() {
        if (_t.joinable()) {
            _t.join();
        }
        cout << "destroying thread object\n";
    }

    // we need to explivitly delete copy ctor and copy assignment
    // this will also prevent instantiatian via default ctor?
    thread_guard(const thread_guard&) = delete;
    thread_guard& operator=(const thread_guard&) = delete;


};

struct fn {
    int &_i;
    fn(int &i):_i(i) {}
    void operator()() {
        for (int i = 0; i < 20; i++) {
            cout << "doing something...\n";
        }
    }
};

int main() {
    int local_state = 1;
    fn runner(local_state);
    thread t1(runner);
    thread_guard g(t1);
    return 0;    
}
