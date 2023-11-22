/**
 * Two shoppers adding garlic and potatoes to a shared notepad
 */
#include <thread>
#include <mutex>

unsigned int garlic_count = 0;
unsigned int potato_count = 0;
std::mutex pencil;


void add_potato() {
    pencil.lock();
    potato_count++;
    pencil.unlock();
}

// see this for debugging tips
// https://stackoverflow.com/questions/3483094/is-it-possible-to-determine-the-thread-holding-a-mutex
/*
(gdb) thread apply all bt

Thread 3 (Thread 0x7ffff7297700 (LWP 3141) "a.out"):
#0  __lll_lock_wait (futex=futex@entry=0x5555555580e0 <pencil>, private=0) at lowlevellock.c:52
#1  0x00007ffff7fa7843 in __GI___pthread_mutex_lock (mutex=0x5555555580e0 <pencil>) at ../nptl/pthread_mutex_lock.c:80
#2  0x000055555555538b in __gthread_mutex_lock (__mutex=0x5555555580e0 <pencil>) at /usr/include/x86_64-linux-gnu/c++/10/bits/gthr-default.h:749
#3  0x0000555555555462 in std::mutex::lock (this=0x5555555580e0 <pencil>) at /usr/include/c++/10/bits/std_mutex.h:100
#4  0x0000555555555242 in add_garlic () at recursive_mutex_demo.cpp:19
#5  0x000055555555528e in shopper () at recursive_mutex_demo.cpp:30
#6  0x0000555555555a83 in std::__invoke_impl<void, void (*)()> (__f=@0x55555556b008: 0x555555555271 <shopper()>) at /usr/include/c++/10/bits/invoke.h:60
#7  0x0000555555555a2d in std::__invoke<void (*)()> (__fn=@0x55555556b008: 0x555555555271 <shopper()>) at /usr/include/c++/10/bits/invoke.h:95
#8  0x00005555555559da in std::thread::_Invoker<std::tuple<void (*)()> >::_M_invoke<0ul> (this=0x55555556b008) at /usr/include/c++/10/thread:264
#9  0x00005555555559ae in std::thread::_Invoker<std::tuple<void (*)()> >::operator() (this=0x55555556b008) at /usr/include/c++/10/thread:271
#10 0x0000555555555992 in std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)()> > >::_M_run (this=0x55555556b000) at /usr/include/c++/10/thread:215
#11 0x00007ffff7e9eed0 in ?? () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
#12 0x00007ffff7fa4ea7 in start_thread (arg=<optimized out>) at pthread_create.c:477
#13 0x00007ffff7cdda2f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95

Thread 2 (Thread 0x7ffff7a98700 (LWP 3140) "a.out"):
#0  __lll_lock_wait (futex=futex@entry=0x5555555580e0 <pencil>, private=0) at lowlevellock.c:52
#1  0x00007ffff7fa7843 in __GI___pthread_mutex_lock (mutex=0x5555555580e0 <pencil>) at ../nptl/pthread_mutex_lock.c:80
#2  0x000055555555538b in __gthread_mutex_lock (__mutex=0x5555555580e0 <pencil>) at /usr/include/x86_64-linux-gnu/c++/10/bits/gthr-default.h:749
#3  0x0000555555555462 in std::mutex::lock (this=0x5555555580e0 <pencil>) at /usr/include/c++/10/bits/std_mutex.h:100
#4  0x0000555555555214 in add_potato () at recursive_mutex_demo.cpp:13
#5  0x0000555555555262 in add_garlic () at recursive_mutex_demo.cpp:22
#6  0x000055555555528e in shopper () at recursive_mutex_demo.cpp:30
#7  0x0000555555555a83 in std::__invoke_impl<void, void (*)()> (__f=@0x55555556aeb8: 0x555555555271 <shopper()>) at /usr/include/c++/10/bits/invoke.h:60
#8  0x0000555555555a2d in std::__invoke<void (*)()> (__fn=@0x55555556aeb8: 0x555555555271 <shopper()>) at /usr/include/c++/10/bits/invoke.h:95
#9  0x00005555555559da in std::thread::_Invoker<std::tuple<void (*)()> >::_M_invoke<0ul> (this=0x55555556aeb8) at /usr/include/c++/10/thread:264
#10 0x00005555555559ae in std::thread::_Invoker<std::tuple<void (*)()> >::operator() (this=0x55555556aeb8) at /usr/include/c++/10/thread:271
#11 0x0000555555555992 in std::thread::_State_impl<std::thread::_Invoker<std::tuple<void (*)()> > >::_M_run (this=0x55555556aeb0) at /usr/include/c++/10/thread:215
#12 0x00007ffff7e9eed0 in ?? () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
#13 0x00007ffff7fa4ea7 in start_thread (arg=<optimized out>) at pthread_create.c:477
#14 0x00007ffff7cdda2f in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:95

Thread 1 (Thread 0x7ffff7a99740 (LWP 3136) "a.out"):
#0  __pthread_clockjoin_ex (threadid=140737348470528, thread_return=0x0, clockid=<optimized out>, abstime=<optimized out>, block=<optimized out>) at pthread_join_common.c:145
#1  0x00007ffff7e9f0e3 in std::thread::join() () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6
#2  0x00005555555552d7 in main () at recursive_mutex_demo.cpp:38


(gdb) t 2
[Switching to thread 2 (Thread 0x7ffff7a98700 (LWP 3140))]
#0  __lll_lock_wait (futex=futex@entry=0x5555555580e0 <pencil>, private=0) at lowlevellock.c:52
52      lowlevellock.c: No such file or directory.
(gdb) f 1
#1  0x00007ffff7fa7843 in __GI___pthread_mutex_lock (mutex=0x5555555580e0 <pencil>) at ../nptl/pthread_mutex_lock.c:80
80      ../nptl/pthread_mutex_lock.c: No such file or directory.
(gdb) p mutex.__data
$4 = {__lock = 2, __count = 0, __owner = 3140, __nusers = 1, __kind = 0, __spins = 0, __elision = 0, __list = {__prev = 0x0, __next = 0x0}}



the fact that two threads are waiting in 
*/
void add_garlic() {
    pencil.lock();
    garlic_count++;
    printf("also add potato to go with the garlic\n");
    add_potato();
    pencil.unlock();
}



void shopper() {
    for (int i=0; i<10000; i++) {
        add_garlic();
        add_potato();
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper);
    barron.join();
    olivia.join();
    printf("We should buy %u garlic.\n", garlic_count);
    printf("We should buy %u potatoes.\n", potato_count);
}