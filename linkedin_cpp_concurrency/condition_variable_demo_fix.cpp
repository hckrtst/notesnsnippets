/**
 * Two hungry threads, anxiously waiting for their turn to take soup
 */
#include <thread>
#include <mutex>
#include <condition_variable>
int soup_servings = 10;
std::mutex slow_cooker_lid;
std::condition_variable soup_taken;


// learn about spurious wakeups
// https://devblogs.microsoft.com/oldnewthing/20180201-00/?p=97946
void hungry_person(int id) {
    int put_lid_back = 0;
    while (soup_servings > 0) {
        std::unique_lock<std::mutex> lid_lock(slow_cooker_lid); // pick up the slow cooker lid
        // we need a while due to spurious wakups
        while ((id != soup_servings % 2) && (soup_servings > 0)) { // not my turn
            printf("%d: closing lid and waiting\n", id);
            put_lid_back++; // it's not your turn; put the lid back...
            soup_taken.wait(lid_lock);
        }
        // if we kept the lock since it is our turn
        if (soup_servings > 0) {
          soup_servings--;
          printf("%d: taking some soup\n", id);
          lid_lock.unlock();
          soup_taken.notify_one();
        }
        
    }
    printf("Person %d put the lid back %u times.\n", id, put_lid_back);
}

int main() {
    std::thread hungry_threads[2];
    for (int i=0; i<2; i++) {
        hungry_threads[i] = std::thread(hungry_person, i);
    }
    for (auto& ht : hungry_threads) {
        ht.join();
    }
}