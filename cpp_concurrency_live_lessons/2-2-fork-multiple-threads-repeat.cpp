#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using std::vector, std::cout, std::endl, std::thread, std::string;

void repeat(string str, int n) {
    if (n > 0) {
        cout << str << endl;
        repeat(str, n-1);
    }
}

int main() {
    // if you don't pass in params correctly for repeat you will see a compile error
    thread t(repeat, "hello", 2);
    cout << "hello from, main\n";
    t.join();
}

