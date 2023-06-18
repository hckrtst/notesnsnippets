* Ch2 - managing threads
** Using RAII to wait for a thread to complete
- copy ctor and copy assignment deleted to ensure that copies cannot be created which might outlive the scope of the thread it is joining.
- if you don't need for thread to finish, you can detach it

** running threads in background
- detached threads --> daemon threads, ownership passed to C++ runtime
- detach breaks association of thread with std::thread object and ensures `terminate()` will not be called when `std::thread` destroyed`
- you can only detach thread for which `joinable()` returns true

*** when to detach thread
- background tasks like monitoring filessystem, clearing out unused cache, optmizing data structures etc

