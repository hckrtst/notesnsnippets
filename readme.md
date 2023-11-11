# Architectural

## pub sub
tbd

# Database
tbd

# CI/CD topics
tbd

# Infra tools (terraform etc)
tbd

# Communications
## Cellular topics
tbd

### Protcols

## TCP/IP review
tbd

# C traps and pitfalls
tbd

# Algorithms
tbd

# CPP Libraries

## Boost
tbd

## pybind11
tbd

# CPP topic reviews

## Arrays

* `std::array` closer to standard C array
  * stored in object
  * does not decay to pointer like standard C array when passed to function since the descriptor includes size info

## General best practice

* Use signed instead of unsigned in most cases
see https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/


# Debugging

tbd

see https://eli.thegreenplace.net/tag/debuggers

# Algorithms

## Edit distance

* TODO prefix edit distance algo important for fuzzy search

* TODO A related topic is q-gram index

### resources

* [YT: Information retrieval course](https://youtu.be/I39Rhegg8Xg?list=PLfgMNKpBVg4V8GtMB7eUrTyvITri8WF7i&t=1856)
* https://github.com/Martinsos/edlib



## Compression and encoding

### resources

* [Google dev videos: compressor head](https://www.youtube.com/playlist?list=PLOU2XLYxmsIJGErt5rrCqaSGTMyyqNt2H)
* [Information retrieval course - compression lecture](https://www.youtube.com/playlist?list=PLfgMNKpBVg4V8GtMB7eUrTyvITri8WF7i)

# Gayle's tips

1. Make sure you identify the terms when evaluating big O, not just using a generic n term.
2. only keep the non-constant dominant terms (as long as they are for the same quantity)

```
O(d + n^2) -> O(d + n^2)
O(2^a + a^2) --> O(2^a)
```

## Seven steps to problem solving

### 1. Listen carefully to the problem - listen to clues. 

For example,

> Given two arrays that are sorted and distinct, find the number of elements in common

So the fact that they are "sorted" and "distinct" are useful clues. If your solution does not exploit this feature then
it's likely not optimal for this usecase. The brute-force approach will probably not use this information, but keep it visible and
consider it for the optimal approach which you will code.

### 2. Draw an example

Use inputs and outputs to further understand the behavior. 

Here is one possibility

```
[1,3,5,7]
[2,3,4,6]
```

But the problem is that this is a special case and you need to think of more general cases. The arrays may be different lengths
or not have any common elements, have negtive numbers etc.

### 3. Brute force

It will be slow and obvious and that is fine. But it will help you think about a starting point. Don't code this one unless asked,
but use it to explore the next step of making it optimal byt identifying the time and space complexities so you know where
you need to focus to devise a solution you can code. The brute force method may not be correct, but figure out how to correct it
after you have something.

### 4. Optimize

A good chunk of time will be spent on this step. **Optimize before you write code**. But, if the interviewer wants you to code the brute-force first then go ahead and do that before this step. Make sure you state the time and space complexities clearly.

### 5. Walk through your algorithm

Before you start coding, walk through the algorithm with your interviewer. **Don't jump into coding with just a basic idea**!!!😥
Even if you're interviewer agrees you can start coding, think! Do you have a good idea of the algorithm?
If not then walk through it more carefully before committing. Because backing out half-way may not be the best look.

Make sure you know what the data structures are, how they change. If there are indices involved then make sure you know how they
are updated using examples.

### 6. Code

Use the language you're most comfortable with.

> My additional tips: make sure you are familiar with all the commonly used standard lib features,
> data structures and gotchas. While perfect syntax is not a hard requirement, fumbling around
> with syntax can be a huge distraction and may end being a negative

### 7. Verification

Check the runtimes and make sure they agree with your earlier assessment. Walk through the code with examples you came up with.
Even if you have the option of testing the code, walk through them manually first. This step will help to catch any bugs you
may have in the code.

### Finally

Once this is done, walk through the code again and explain it. Consider it a code review session where you want to make sure the
reviewer is satisfied and will be ready to approve your code. Answer any questions they have.
This shows attention to details and that you care about code quality.


## Example

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




## Optimizing with BUD

BUD = Bottlenecks, Unnecessary work, Duplicated work


## Optimizing with space and time

* hash tables, pre-computation, tries
* think about doing some upfront work such as sorting, storing data in table etc.

## best conceivable runtime

Given the nature of the problem, what is the runtime that you cannot beat

Example

> given an array, find all pairs that sum to median value

You cannot do better than O(n) where n is size of array since you must access every element at least once

## Optimizing wth DIY
tbd

## Tips for coding

* Don't write loose code, write small functions
* When filling in the func impls, try a priority-based breadth first approach, work on the most useful functions first and then fill in the rest ( you need to maximize your signals to the interviewer)
* ignore things that don't show good signals but check with your interviewer first
  * So pretend you have a max/min function or such uitility and focus on the parts of the impl that matters. Fill those in the interviewer wants you to.

> My notes: Keep the code simple, don't try to be clever (no lambdas or other less common features), the goal is not to show off cleverness.
> The easier the code is for the interviewer to follow, the better. It alse reduces chances of errors.


## verifications

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

## communications

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

## Tips by topics

### arrays
* typically arrays fixed size
* dynamically resizable arrays allows you to add more data
  * internally this maintains a fixed size array
  * when adding new element exceeds current capacity we grow the existing array
  * but if we double the capacity when we need more space then O(n) work done every 1/n times. so this is O(1) amortized time (on average), so append is still considered O(1) time
  * see [resizable_array.cpp](./cpp_prep_notes/resizable_array.cpp)
  * some tips about arrays
    * `at()` can be used with `std::array` and `std::vector` which also does bounds checking and throws exception if out of bounds. this can be useful for public apis. while exceptions are a zero const abstraction (i.e. you don't pay for what you use) it may not be suitable for all use cases and sometimes we need to disable exception handling (esp for real-time systems).
    * `std::array` is stored in object and is fixed while `std::vector` is dynamic

  ### making array
  
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


### stack
* LIFO (mention this with stack and explain)
* can be useful when doing a reverse
* YOu can implement a linked list as a stack


















