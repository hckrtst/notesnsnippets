/**
 * Two shoppers adding items to a shared notepad
 */
#include <thread>

unsigned int garlic_count = 0;

void shopper() {
    for (int i=0; i<1000000; i++) {
        garlic_count++;
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We should buy %u garlic.\n", garlic_count); // this will not print 2 mil
}