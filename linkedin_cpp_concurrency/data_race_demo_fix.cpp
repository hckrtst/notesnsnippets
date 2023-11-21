/**
 * Two shoppers adding items to a shared notepad
 */
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

unsigned int garlic_count = 0;
using std::cout, std::endl;
std::mutex glock;

void shopper() {    
    for (int i=0; i<10; i++) {
        cout << std::this_thread::get_id() << " thinking....\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        glock.lock();
        garlic_count++;
        glock.unlock();
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We should buy %u garlic.\n", garlic_count); // this will not print 2 mil if we loop for 1 million times
}