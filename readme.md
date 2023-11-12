<!-- vscode-markdown-toc -->
* 1. [Architectural](#Architectural)
	* 1.1. [pub sub](#pubsub)
* 2. [Database](#Database)
* 3. [CI/CD topics](#CICDtopics)
* 4. [Infra tools (terraform etc)](#Infratoolsterraformetc)
	* 4.1. [strace](#strace)
	* 4.2. [tcpdump](#tcpdump)
	* 4.3. [gdb](#gdb)
* 5. [Communications](#Communications)
	* 5.1. [Cellular topics](#Cellulartopics)
		* 5.1.1. [Protcols](#Protcols)
	* 5.2. [TCP/IP review](#TCPIPreview)
* 6. [C traps and pitfalls](#Ctrapsandpitfalls)
* 7. [CPP Libraries](#CPPLibraries)
	* 7.1. [Boost](#Boost)
	* 7.2. [pybind11](#pybind11)
* 8. [CPP topic reviews](#CPPtopicreviews)
	* 8.1. [Arrays](#Arrays)
	* 8.2. [General best practice](#Generalbestpractice)
* 9. [Debugging](#Debugging)
* 10. [Algorithms](#Algorithms)
	* 10.1. [markov chains](#markovchains)
	* 10.2. [Edit distance](#Editdistance)
		* 10.2.1. [resources](#resources)
	* 10.3. [Compression and encoding](#Compressionandencoding)
		* 10.3.1. [resources](#resources-1)
* 11. [Data structures](#Datastructures)
	* 11.1. [ringer buffers](#ringerbuffers)
	* 11.2. [hash tables](#hashtables)
	* 11.3. [markov chains](#markovchains-1)
	* 11.4. [huffman trees](#huffmantrees)
	* 11.5. [tries](#tries)
* 12. [Gayle's tips](#Gaylestips)
	* 12.1. [Seven steps to problem solving](#Sevenstepstoproblemsolving)
		* 12.1.1. [1. Listen carefully to the problem - listen to clues.](#Listencarefullytotheproblem-listentoclues.)
		* 12.1.2. [2. Draw an example](#Drawanexample)
		* 12.1.3. [3. Brute force](#Bruteforce)
		* 12.1.4. [4. Optimize](#Optimize)
		* 12.1.5. [5. Walk through your algorithm](#Walkthroughyouralgorithm)
		* 12.1.6. [6. Code](#Code)
		* 12.1.7. [7. Verification](#Verification)
		* 12.1.8. [Finally](#Finally)
	* 12.2. [Example](#Example)
	* 12.3. [Optimizing with BUD](#OptimizingwithBUD)
	* 12.4. [Optimizing with space and time](#Optimizingwithspaceandtime)
	* 12.5. [best conceivable runtime](#bestconceivableruntime)
	* 12.6. [Optimizing wth DIY](#OptimizingwthDIY)
	* 12.7. [Tips for coding](#Tipsforcoding)
	* 12.8. [verifications](#verifications)
	* 12.9. [communications](#communications)
	* 12.10. [Tips by topics](#Tipsbytopics)
		* 12.10.1. [string](#string)
		* 12.10.2. [bitset](#bitset)
		* 12.10.3. [arrays](#arrays)
		* 12.10.4. [vector](#vector)
		* 12.10.5. [deque](#deque)
		* 12.10.6. [stack](#stack)
		* 12.10.7. [strings](#strings)
* 13. [real-time systems](#real-timesystems)
* 14. [Coding interviews resources](#Codinginterviewsresources)
* 15. [General behavioral questions](#Generalbehavioralquestions)
* 16. [Systems design topics](#Systemsdesigntopics)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Architectural'></a>Architectural

###  1.1. <a name='pubsub'></a>pub sub
tbd

##  2. <a name='Database'></a>Database
tbd

##  3. <a name='CICDtopics'></a>CI/CD topics
tbd

see this course https://www.freecodecamp.org/news/devops-with-gitlab-ci-course/


##  4. <a name='Infratoolsterraformetc'></a>Infra tools (terraform etc)
tbd

###  4.1. <a name='strace'></a>strace

###  4.2. <a name='tcpdump'></a>tcpdump

###  4.3. <a name='gdb'></a>gdb


##  5. <a name='Communications'></a>Communications
###  5.1. <a name='Cellulartopics'></a>Cellular topics
tbd

####  5.1.1. <a name='Protcols'></a>Protcols

###  5.2. <a name='TCPIPreview'></a>TCP/IP review
tbd

##  6. <a name='Ctrapsandpitfalls'></a>C traps and pitfalls
tbd


##  7. <a name='CPPLibraries'></a>CPP Libraries

###  7.1. <a name='Boost'></a>Boost
tbd

###  7.2. <a name='pybind11'></a>pybind11
tbd

##  8. <a name='CPPtopicreviews'></a>CPP topic reviews

###  8.1. <a name='Arrays'></a>Arrays

* `std::array` closer to standard C array
  * stored in object
  * does not decay to pointer like standard C array when passed to function since the descriptor includes size info

* THis course is excellent https://courses.mshah.io/courses/take/cpp-programming-language/texts/43118039-c-video-series-introduction-modern-cpp-series


###  8.2. <a name='Generalbestpractice'></a>General best practice

* Use signed instead of unsigned in most cases
see https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/


##  9. <a name='Debugging'></a>Debugging

* sometimes we need to disable exceptions for performance reasons. g++ turns throws into abort in that case.
see [this link](https://stackoverflow.com/questions/7249378/disabling-c-exceptions-how-can-i-make-any-std-throw-immediately-terminate)

see https://eli.thegreenplace.net/tag/debuggers

##  10. <a name='Algorithms'></a>Algorithms

###  10.1. <a name='markovchains'></a>markov chains

###  10.2. <a name='Editdistance'></a>Edit distance

* TODO prefix edit distance algo important for fuzzy search

* TODO A related topic is q-gram index

####  10.2.1. <a name='resources'></a>resources

* [YT: Information retrieval course](https://youtu.be/I39Rhegg8Xg?list=PLfgMNKpBVg4V8GtMB7eUrTyvITri8WF7i&t=1856)
* https://github.com/Martinsos/edlib



###  10.3. <a name='Compressionandencoding'></a>Compression and encoding

####  10.3.1. <a name='resources-1'></a>resources

* [Google dev videos: compressor head](https://www.youtube.com/playlist?list=PLOU2XLYxmsIJGErt5rrCqaSGTMyyqNt2H)
* [Information retrieval course - compression lecture](https://www.youtube.com/playlist?list=PLfgMNKpBVg4V8GtMB7eUrTyvITri8WF7i)

##  11. <a name='Datastructures'></a>Data structures

###  11.1. <a name='ringerbuffers'></a>ringer buffers
tbd
* how to make them threadsafe
* how to make them lock free

###  11.2. <a name='hashtables'></a>hash tables
tbd

###  11.3. <a name='markovchains-1'></a>markov chains

###  11.4. <a name='huffmantrees'></a>huffman trees

###  11.5. <a name='tries'></a>tries


* lock free?
* threadsafe?


##  12. <a name='Gaylestips'></a>Gayle's tips

1. Make sure you identify the terms when evaluating big O, not just using a generic n term.
2. only keep the non-constant dominant terms (as long as they are for the same quantity)

```
O(d + n^2) -> O(d + n^2)
O(2^a + a^2) --> O(2^a)
```

###  12.1. <a name='Sevenstepstoproblemsolving'></a>Seven steps to problem solving

####  12.1.1. <a name='Listencarefullytotheproblem-listentoclues.'></a>1. Listen carefully to the problem - listen to clues. 

For example,

> Given two arrays that are sorted and distinct, find the number of elements in common

So the fact that they are "sorted" and "distinct" are useful clues. If your solution does not exploit this feature then
it's likely not optimal for this usecase. The brute-force approach will probably not use this information, but keep it visible and
consider it for the optimal approach which you will code.

####  12.1.2. <a name='Drawanexample'></a>2. Draw an example

Use inputs and outputs to further understand the behavior. 

Here is one possibility

```
[1,3,5,7]
[2,3,4,6]
```

But the problem is that this is a special case and you need to think of more general cases. The arrays may be different lengths
or not have any common elements, have negtive numbers etc.

####  12.1.3. <a name='Bruteforce'></a>3. Brute force

It will be slow and obvious and that is fine. But it will help you think about a starting point. Don't code this one unless asked,
but use it to explore the next step of making it optimal byt identifying the time and space complexities so you know where
you need to focus to devise a solution you can code. The brute force method may not be correct, but figure out how to correct it
after you have something.

####  12.1.4. <a name='Optimize'></a>4. Optimize

A good chunk of time will be spent on this step. **Optimize before you write code**. But, if the interviewer wants you to code the brute-force first then go ahead and do that before this step. Make sure you state the time and space complexities clearly.

####  12.1.5. <a name='Walkthroughyouralgorithm'></a>5. Walk through your algorithm

Before you start coding, walk through the algorithm with your interviewer. **Don't jump into coding with just a basic idea**!!!😥
Even if you're interviewer agrees you can start coding, think! Do you have a good idea of the algorithm?
If not then walk through it more carefully before committing. Because backing out half-way may not be the best look.

Make sure you know what the data structures are, how they change. If there are indices involved then make sure you know how they
are updated using examples.

####  12.1.6. <a name='Code'></a>6. Code

Use the language you're most comfortable with.

> My additional tips: make sure you are familiar with all the commonly used standard lib features,
> data structures and gotchas. While perfect syntax is not a hard requirement, fumbling around
> with syntax can be a huge distraction and may end being a negative

####  12.1.7. <a name='Verification'></a>7. Verification

Check the runtimes and make sure they agree with your earlier assessment. Walk through the code with examples you came up with.
Even if you have the option of testing the code, walk through them manually first. This step will help to catch any bugs you
may have in the code.

####  12.1.8. <a name='Finally'></a>Finally

Once this is done, walk through the code again and explain it. Consider it a code review session where you want to make sure the
reviewer is satisfied and will be ready to approve your code. Answer any questions they have.
This shows attention to details and that you care about code quality.


###  12.2. <a name='Example'></a>Example

For the given problem, let's see the bruteforce approach

```
a1 = [1,3,6,10,18]
a2 = [4,6]
res = [6]


a1 = [-10, -8, 0, 3, 5]
a2 = [0, 3, 5]
res = [0,3,5]

output is an array


```
nested for loop
iterate each element
i 0
j 0 1 2 ...
i 1
j 0 1 2....

brute force would be time: O(n1*n2) where array 1 is n1 and array 2 is n2
space: O(1) since no recursion or extra mem allocations

We know the arrays are sorted and has no dups

Ok so if we used a hash set to store the elements of one array we can do O(1) lookups for that array.
But that incurs the penalty of extra memory.

Since the array is sorted, they probably want to you to try a binary search to cut the look up time down from linear to
logarithmic.




###  12.3. <a name='OptimizingwithBUD'></a>Optimizing with BUD

BUD = Bottlenecks, Unnecessary work, Duplicated work


###  12.4. <a name='Optimizingwithspaceandtime'></a>Optimizing with space and time

* hash tables, pre-computation, tries
* think about doing some upfront work such as sorting, storing data in table etc.

###  12.5. <a name='bestconceivableruntime'></a>best conceivable runtime

Given the nature of the problem, what is the runtime that you cannot beat

Example

> given an array, find all pairs that sum to median value

You cannot do better than O(n) where n is size of array since you must access every element at least once

###  12.6. <a name='OptimizingwthDIY'></a>Optimizing wth DIY
tbd

###  12.7. <a name='Tipsforcoding'></a>Tips for coding

* Don't write loose code, write small functions
* When filling in the func impls, try a priority-based breadth first approach, work on the most useful functions first and then fill in the rest ( you need to maximize your signals to the interviewer)
* ignore things that don't show good signals but check with your interviewer first
  * So pretend you have a max/min function or such uitility and focus on the parts of the impl that matters. Fill those in the interviewer wants you to.

> My notes: Keep the code simple, don't try to be clever (no lambdas or other less common features), the goal is not to show off cleverness.
> The easier the code is for the interviewer to follow, the better. It alse reduces chances of errors.


###  12.8. <a name='verifications'></a>verifications

* original example is not a good testcase, it can be large and time consuming to run through
* This is not about doing test cases yet, it's just a conceptual verification
* Look for hotspots in your code where it might be easy to make errors
  * array access
  * recursion
  * pointer dereferencing
  * example: say you have a function `x = process(a,b)`.
    This is not too hot for errors (except missing to check return value.s)
    But if you have `x = process(left, right + left/2 + 1)`. This is a minefield! You have math operations, moving indices,
    parameters when calling recursion, base case of recursion etc.
* This process should be fast, like a spot-check and not exhaustive. That can be time consuming and may send the wrong signal (maybe he is not confident...?)
* Use smaller test cases and edge cases (null, empty etc.)
* Use bigger testcases if you have more time
* common mistake is to just re-verify the algorithm instead of actually testing the code
  * actually test your code, take values and plug them in and run through the scenario using these inputs on the actual code
    like a debugger would
  * but don't just blindly walk through the code...think about whether the values you are seeing are the right values
* If you find a bug, look for the right fix, not just a quick sloppy fix. Understand the root cause and don't just put a bandage on
* When all is done, go through the code one more time and see what other improvements can be done.
* The goal is not just to have a working solution. It's about finding people who value the quality of their work and are willing to solve hard problems. Show that you are that person.

###  12.9. <a name='communications'></a>communications

* Drive the conversation
  * Don't make your interviewer ask you to improve algorithm, code etc.
  * Be the one to look for improvements (self-driving)

* Show your thought process
  * ask questions
    * is the data sorted? is the tree balanced? can I modify the array...etc

* propose an initial solution but also think about its issues
  * use examples to show your thought process
  * But don't use code to describe your thought process

* be honest about mistakes
* tell interviewer if you've seen the question before
* be positive and keep trying, don't give up when things get hard
* start of interview is a good time to ask questions, but you can also ask questions down the road

* Big part of comms is listening. Listen to your interviewer well.
* Take the suggestions offered, they are trying to point something out to you

* IMPORTANT: if you hear an interviewer make the same point more than once, it's a BIG hint you missed something important
* if interviewer leads you down a path, make sure you follow through and continue one, they are nudging you in the right direction
* DOn't get flustered, some problems are hard. It's ok to make mistakes and struggle.
  * the goal is see how you handle the problem solving
* The code doesn't need to be perfect the first time around...BUT GO BACK AND MAKE IT BETTER (style, bug fixes, efficiency, etc)

###  12.10. <a name='Tipsbytopics'></a>Tips by topics

####  12.10.1. <a name='string'></a>string

* 

####  12.10.2. <a name='bitset'></a>bitset

see [this link too](https://en.cppreference.com/w/cpp/utility/bitset)

####  12.10.3. <a name='arrays'></a>arrays
* typically arrays fixed size
* dynamically resizable arrays allows you to add more data
  * internally this maintains a fixed size array
  * when adding new element exceeds current capacity we grow the existing array
  * but if we double the capacity when we need more space then O(n) work done every 1/n times. so this is O(1) amortized time (on average), so append is still considered O(1) time
  * see [resizable_array.cpp](./cpp_prep_notes/resizable_array.cpp)
  * some tips about arrays
    * `at()` can be used with `std::array` and `std::vector` which also does bounds checking and throws exception if out of bounds. this can be useful for public apis. while exceptions are a zero const abstraction (i.e. you don't pay for what you use) it may not be suitable for all use cases and sometimes we need to disable exception handling (esp for real-time systems).
    * `std::array` is stored in object and is fixed while `std::vector` is dynamic
    * beware of boundary conditions (off by one  errors)
    * use `matrix[row][col]` as opposed to `matrix[y][x]` since that is more intuitive
    * be comfortable with index math
      * example: if we want to do multiple rotations to an array. we can do copying of elements or we can wrap the array in a class
      which updates the indexes internally using an index map... (see https://leetcode.com/problems/rotate-array/)
    * be aware of whether you need to preserve the array or need a copy   
  ##### making array
    * test empty, 1/2 element arrays carefully

  
  ```cpp
  #include <array>
  #include <iostream>
  using namespace std;

  int main() {
      array<int,10> arr1{0};
      for (auto e: arr1) {
          cout << e << endl;
      }
      return 0;
  }
  ```
* front(), back(), data() to directly access backing data
* std::partition can be applied to array and vector for partitioning in place and getting iterator to the second partition.

####  12.10.4. <a name='vector'></a>vector
* compared to deque, list and forward_list a vector is efficient at accessing elements and efficient for adding/remove from tail. amortized O(1) since resizes can occur periodically.
* vectors use more space than static arrays because more memory allocated to handle future growth
* extra memory can be returned back with `shrink_to_fit()`

* vector end() is past the last element
![](https://upload.cppreference.com/mwiki/images/1/1b/range-begin-end.svg)


example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    std::vector<int> v1;
    cout << "theoretical max " << v1.max_size() << endl;
    std::vector<int> nums {1, 3, 5, 7};
    std::cout << "nums contains " << nums.size() << " elements.\n"; // 4
    cout << "current capacity " << nums.capacity() << endl; // 4
    nums.push_back(1);
    cout << "current capacity " << nums.capacity() << endl; // 8 since we double capacity
    std::vector<char> v2;
    cout << "current capacity of v2 " << v2.capacity() << endl; // 0
    v2.reserve(10);
    cout << "after reserve: current capacity of v2 " << v2.capacity() << endl; // 10
    cout << "nums front is " << nums.front() << endl; // 1 - same as *nums.begin()
    cout << "nums back is " << nums.back() <<endl; // 7
    cout << "middle value is " << *(nums.begin() + nums.size()/2) << endl; // 5
    // --- iterations
    std::for_each(nums.begin(), nums.end(), [](int e) { cout << e << ", "; });
    cout << endl;
    for (auto e: nums) { cout << e << ", "; }
    cout << endl;
    cout << "sum of nums " << std::accumulate(nums.begin(), nums.end(), 0) << endl;
}
```
* vector<bool> is a specialized bitset. see [](./cpp_prep_notes/test_vector_bool.cpp)
If size of bitset is known at compile time then use `std::bitset`.


####  12.10.5. <a name='deque'></a>deque

* efficient add and remove from both ends of a queue

####  12.10.6. <a name='stack'></a>stack
* LIFO (mention this with stack and explain)
* can be useful when doing a reverse
* YOu can implement a linked list as a stack

####  12.10.7. <a name='strings'></a>strings

* string is a template for basic_string<char>
* since c++17 we also have a string view which gets us a read-only version
* strings can be hashed
* `substr()` creates a new string. `string_view` from C++17 more efficient as it does not make a copy.

see [](./cpp_prep_notes/test_string.cpp)


##  13. <a name='real-timesystems'></a>real-time systems
[](./real-time-embedded-systems/readme.md)

##  14. <a name='Codinginterviewsresources'></a>Coding interviews resources
* https://leetcodethehardway.com/
* https://neetcode.io


##  15. <a name='Generalbehavioralquestions'></a>General behavioral questions
tbd

##  16. <a name='Systemsdesigntopics'></a>Systems design topics
tbd











