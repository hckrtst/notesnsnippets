#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <future>
#include <memory>
#include <filesystem>

namespace fs = std::filesystem;
using std::future, std::cout, std::endl, std::vector, std::string;

std::vector<std::string> listDir(std::filesystem::path const & dir) {
    std::vector<std::string> files;
    for(std::filesystem::directory_iterator it(dir); it != fs::directory_iterator(); ++it ) {
        if (fs::is_regular_file(it->status())) {
            files.push_back(it->path().filename());
        }
    }
    return files;
}

vector<string> listDirsConcurrent(vector<fs::path> const & paths) {
    vector<future<vector<string>>> futs;
    for (auto const &pth: paths) {
        cout << pth << endl;
        futs.emplace_back(std::async(listDir, std::ref(pth)));
    }
    vector<string> allFiles;
    for (auto & fut: futs) {
        auto files = fut.get();
        std::move(files.begin(), files.end(), back_inserter(allFiles));
    }
    return allFiles;


}

int main() {

    // serial
    auto files = listDir(fs::path(".."));

    for (auto &f: files) {
        std::cout << f << ", ";
    }
    std::cout << std::endl;

    cout << "-----------------------\n";
    for (auto &f : listDirsConcurrent({fs::path(".."), fs::path("."), fs::path("/home/tintin")})) {
        cout << f << endl;
    }
}

