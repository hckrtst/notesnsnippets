/**
 * Exceptionally polite philosophers, thinking and eating sushi
 */
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick, const char* name) {
    while (sushi_count > 0) {
        first_chopstick.lock();
        if (!second_chopstick.try_lock()) {
            first_chopstick.unlock();
            printf("%s: please go on....\n", name);
            std::this_thread::yield();
            continue;
        }
        if (sushi_count) {
            sushi_count--;
        }
        second_chopstick.unlock();
        first_chopstick.unlock();
    }
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b), "barron");
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a), "olivia");
    std::thread s(philosopher, std::ref(chopstick_a), std::ref(chopstick_b), "s");
    std::thread n(philosopher, std::ref(chopstick_b), std::ref(chopstick_a), "n");
    std::thread bill(philosopher, std::ref(chopstick_b), std::ref(chopstick_a), "bill");
    std::thread jill(philosopher, std::ref(chopstick_a), std::ref(chopstick_b), "jill");
    barron.join();
    olivia.join();
    s.join();
    n.join();
    bill.join();
    jill.join();
    printf("The philosophers are done eating.\n");
}