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

class FileMonitor {
    public:
        void push_back(string file) {
            std::lock_guard<std::mutex> lck(_mtx);
            // explicity move to avoid a copy into vector
            _allFiles.push_back(std::move(file));
        }
        void print() {
            std::lock_guard<std::mutex> lck(_mtx);
            std::ostringstream oss;
            for (auto& f: _allFiles) {
                oss << f  << ", ";
            }
            oss << endl;
            cout << "all files : " << oss.str() << endl;
        }
    private:
        vector<string> _allFiles;
        std::mutex _mtx;
};

void listDir(string path, FileMonitor & fileSink) {
    for (fs::directory_iterator it(path); it != fs::directory_iterator(); ++it) {
        if (fs::is_regular_file(it->status())) {
            fileSink.push_back(it->path().filename());
        }    
    }
}

void listDirs(vector<fs::path> paths, FileMonitor & fileSink) {
    vector<future<void>> futures;

    for (auto &path: paths) {
        cout << path << endl;
        futures.emplace_back(std::async(listDir, path, std::ref(fileSink)));
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

    FileMonitor fileSink;
    listDirs(paths, fileSink);
    fileSink.print();
}

