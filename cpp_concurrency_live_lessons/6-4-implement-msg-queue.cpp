#include <thread>
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <string>
#include <future>
#include <memory>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;
using std::future, std::cout, std::endl, std::vector, std::string;

template<typename T>
class MessageQueue {
    public:
        void send(T msg) {
            // always have a named variable for the lock_guard otherwise it is constructed
            // and destroyed right away!!! this will defeat the purpose of this call
            std::lock_guard<std::mutex> lck(_mtx);
            // explicity move to avoid a copy into vector
            _messages.push_back(std::move(msg));
            // notify client waiting
            _cond.notify_one();
        }
        
        T receive() {
            //this lock will be  released at the same time we enter wait --- atomically
            std::unique_lock<std::mutex> lck(_mtx);
            // handle spurious wakeups
            while (_messages.empty()) _cond.wait(lck);
            // we can also do _cond.wait(lck, [this]{ return !_messages.empty(); })
            // we have the locak again after this wait
            T name = std::move(_messages.back());
            _messages.pop_back();
            return name;
        }
        private:
        std::deque<T> _messages;
        mutable std::mutex _mtx;
        mutable std::condition_variable _cond;
};


int main() {
    MessageQueue<int> queue;
    std::future<void> fut = std::async([&queue]{ queue.send(44); });
    int i = queue.receive();
    cout << "Received: " << i << endl;
    fut.wait();
}

