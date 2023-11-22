/**
 * Too many philosophers, thinking and eating sushi
 */
#include <thread>
#include <mutex>

int sushi_count = 5000;

// WIP - maybe need cond vars
void philosopher(std::mutex &chopsticks, int i) {
    int consumed = 0;
    // let's try to give each thread a fair chance to eat and limit
    // them all to a fixed amount each cycle.
    static const int max_serving_size = 17;
    int next_available = 0;


      
      while(sushi_count > 0) {
        {
          
          std::scoped_lock lock(chopsticks);
          sushi_count--;

        }
        
      }
 
    }
    printf("%d consumed %d sushi\n", i, consumed);
    
}

int main() {
    std::mutex chopsticks;
    std::array<std::thread, 150> philosophers;
    for (size_t i=0; i<philosophers.size(); i++) {
        philosophers[i] = std::thread(philosopher,std::ref(chopsticks), i);
    }
    for (size_t i=0; i<philosophers.size(); i++) {
        philosophers[i].join();
    }
    printf("The philosophers are done eating.\n");
}