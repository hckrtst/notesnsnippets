/**
 * Two philosophers, thinking and eating sushi
 */
#include <thread>
#include <mutex>

int sushi_count = 50;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        // since we have two separate locks
        // if we pick them in the opposite order then
        // the two threads end up waiting on each other forever
        std::scoped_lock lock(first_chopstick, second_chopstick); // must create variable
        // locks are now atomically held
        printf("%u picked up first chostick\n", std::this_thread::get_id());
        printf("%u picked up second chostick\n", std::this_thread::get_id());
        if (sushi_count) {
            sushi_count--;
        }
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