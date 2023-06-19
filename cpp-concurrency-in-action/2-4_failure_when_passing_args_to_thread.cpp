#include <iostream>
#include <thread>

using std::cout, std::endl, std::thread, std::string;

void fn(int i, std::string const &s) {
    cout <<"doing something with string " << s << endl;
}

int main() {
    // this will result in "terminate called without an active exception"
    // when calling thread with parameters, arguments are copied to local storage by the 
    // launching thread and then passed to callable objects (even if a reference is used)
    // the string literal here is passed an const char* and converted to string 
    // only in the context of the new thread
    // same error will happen if we create a new char buffer[1024] and pass that in... 
    thread t(fn, 1, "oops");
    return 0;    
}
