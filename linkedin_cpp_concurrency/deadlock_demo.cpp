/**
 * Two philosophers, thinking and eating sushi
 */
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        // since we have two separate locks
        // if we pick them in the opposite order then
        // the two threads end up waiting on each other forever
        first_chopstick.lock();
        printf("%d picked up first chostick\n", std::this_thread::get_id());
        second_chopstick.lock();
        printf("%d picked up second chostick\n", std::this_thread::get_id());
        if (sushi_count) {
            sushi_count--;
        }
        second_chopstick.unlock();
        first_chopstick.unlock();
    }
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    barron.join();
    olivia.join();
    printf("The philosophers are done eating.\n");
}