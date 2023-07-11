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
class FileMonitor {
    public:
        void push_back(T file) {
            // always have a named variable for the lock_guard otherwise it is constructed
            // and destroyed right away!!! this will defeat the purpose of this call
            std::lock_guard<std::mutex> lck(_mtx);
            // explicity move to avoid a copy into vector
            _allFiles.push_back(std::move(file));
            // notify client waiting
            _cond.notify_one();
        }
        /* no need for this
        bool hasData() const {
            std::lock_guard<std::mutex> lck(_mtx);
            return !_allFiles.empty();
        } */

        T pop_back() {
            //this lock will be  released at the same time we enter wait --- atomically
            std::unique_lock<std::mutex> lck(_mtx);
            // handle spurious wakeups
            while (_allFiles.empty()) _cond.wait(lck);
            // we can also do _cond.wait(lck, [this]{ return !_allFiles.empty(); })
            // we have the locak again after this wait
            T name = std::move(_allFiles.back());
            _allFiles.pop_back();
            return name;
        }
        private:
        std::deque<T> _allFiles;
        mutable std::mutex _mtx;
        mutable std::condition_variable _cond;
};

void listDir(string path, FileMonitor<string> & fileSink) {
    for (fs::directory_iterator it(path); it != fs::directory_iterator(); ++it) {
        if (fs::is_regular_file(it->status())) {
            fileSink.push_back(it->path().filename());
        }    
    }
}

void listDirs(vector<fs::path> paths, FileMonitor<string> & fileSink) {
    vector<future<void>> futures;

    for (auto &path: paths) {
        cout << path << endl;
        futures.emplace_back(std::async(listDir, path, std::ref(fileSink)));
    }

    for(;;) {
        //if (fileSink.hasData()) {
            string name = fileSink.pop_back();
            cout << "File : " << name << endl;
        //}
    }
    for (auto& fut : futures) {
        fut.wait();
    }
}

int main() {
    vector<fs::path> paths;
    for (fs::directory_iterator it("/home/tintin/workspace"); it != fs::directory_iterator(); ++it) {
        if (fs::is_directory(it->status())) {
            paths.push_back(it->path());
        }
    }

    FileMonitor<string> fileSink;
    listDirs(paths, fileSink);
}

