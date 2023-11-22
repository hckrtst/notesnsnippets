/**
 * Two hungry threads, anxiously waiting for their turn to take soup
 */
#include <thread>
#include <mutex>
#include <condition_variable>
int soup_servings = 50;
std::mutex slow_cooker_lid;
std::condition_variable soup_taken;


// this round robin approach


// learn about spurious wakeups
// https://devblogs.microsoft.com/oldnewthing/20180201-00/?p=97946
void hungry_person(int id, size_t num_guests) {
    int put_lid_back = 0;
    int soup_sips = 0;
    while (soup_servings > 0) {
        std::unique_lock<std::mutex> lid_lock(slow_cooker_lid); // pick up the slow cooker lid
        // we need a while due to spurious wakups
        // NOTE: careful modulo will eventually overflow for a very long running process!!!!!!
        // in this case we count down and check for 0 so it's ok
        while ((id != soup_servings % num_guests) && (soup_servings > 0)) { // not my turn
            //printf("%d: closing lid and waiting\n", id);
            put_lid_back++; // it's not your turn; put the lid back...
            soup_taken.wait(lid_lock);
        }
        // if we kept the lock since it is our turn
        if (soup_servings > 0) {
          soup_servings--;
          soup_sips++;
          printf("%d: taking some soup\n", id);
          lid_lock.unlock();
          soup_taken.notify_all(); // we need to notify all since there are many waiting threads
        }
        
    }
    printf("Person %d put the lid back %u times and got %d sips of soup \n", id, put_lid_back, soup_sips);
}

int main() {
    std::array<std::thread, 7> hungry_threads;
    for (int i=0; i<hungry_threads.size(); i++) {
        hungry_threads[i] = std::thread(hungry_person, i, hungry_threads.size());
    }
    for (auto& ht : hungry_threads) {
        ht.join();
    }
}