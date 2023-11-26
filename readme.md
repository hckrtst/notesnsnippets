<!-- vscode-markdown-toc -->
* 1. [Linux/OS](#LinuxOS)
* 2. [Architectural](#Architectural)
	* 2.1. [pub sub](#pubsub)
* 3. [Endian-ness](#Endian-ness)
* 4. [Database](#Database)
* 5. [CI/CD topics](#CICDtopics)
	* 5.1. [gitlab CI/CD](#gitlabCICD)
* 6. [Infra tools (terraform etc)](#Infratoolsterraformetc)
	* 6.1. [strace](#strace)
	* 6.2. [tcpdump](#tcpdump)
	* 6.3. [gdb](#gdb)
* 7. [Communications](#Communications)
	* 7.1. [Cellular topics](#Cellulartopics)
		* 7.1.1. [Protocols](#Protocols)
		* 7.1.2. [scheduling](#scheduling)
	* 7.2. [TCP/IP review](#TCPIPreview)
* 8. [C traps and pitfalls](#Ctrapsandpitfalls)
	* 8.1. [pointer cheat sheet](#pointercheatsheet)
* 9. [CPP Libraries](#CPPLibraries)
	* 9.1. [Boost](#Boost)
	* 9.2. [pybind11](#pybind11)
	* 9.3. [STL](#STL)
* 10. [CPP topic reviews](#CPPtopicreviews)
	* 10.1. [Arrays](#Arrays)
	* 10.2. [General best practice](#Generalbestpractice)
* 11. [Debugging](#Debugging)
* 12. [Algorithms](#Algorithms)
	* 12.1. [markov chains](#markovchains)
	* 12.2. [Edit distance](#Editdistance)
		* 12.2.1. [resources](#resources)
	* 12.3. [Compression and encoding](#Compressionandencoding)
		* 12.3.1. [resources](#resources-1)
* 13. [Data structures](#Datastructures)
	* 13.1. [ringer buffers](#ringerbuffers)
	* 13.2. [hash tables](#hashtables)
	* 13.3. [markov chains](#markovchains-1)
	* 13.4. [huffman trees](#huffmantrees)
	* 13.5. [tries](#tries)
* 14. [Gayle's tips](#Gaylestips)
	* 14.1. [Seven steps to problem solving](#Sevenstepstoproblemsolving)
		* 14.1.1. [1. Listen carefully to the problem - listen to clues.](#Listencarefullytotheproblem-listentoclues.)
		* 14.1.2. [2. Draw an example](#Drawanexample)
		* 14.1.3. [3. Brute force](#Bruteforce)
		* 14.1.4. [4. Optimize](#Optimize)
		* 14.1.5. [5. Walk through your algorithm](#Walkthroughyouralgorithm)
		* 14.1.6. [6. Code](#Code)
		* 14.1.7. [7. Verification](#Verification)
		* 14.1.8. [Finally](#Finally)
	* 14.2. [Example](#Example)
	* 14.3. [Optimizing with BUD](#OptimizingwithBUD)
	* 14.4. [Optimizing with space and time](#Optimizingwithspaceandtime)
	* 14.5. [best conceivable runtime](#bestconceivableruntime)
	* 14.6. [Optimizing wth DIY](#OptimizingwthDIY)
	* 14.7. [Tips for coding](#Tipsforcoding)
	* 14.8. [verifications](#verifications)
	* 14.9. [communications](#communications)
	* 14.10. [Tips by topics](#Tipsbytopics)
		* 14.10.1. [string](#string)
		* 14.10.2. [bitset](#bitset)
		* 14.10.3. [arrays](#arrays)
		* 14.10.4. [vector](#vector)
		* 14.10.5. [deque](#deque)
		* 14.10.6. [stack](#stack)
		* 14.10.7. [strings](#strings)
		* 14.10.8. [maps](#maps)
		* 14.10.9. [sets](#sets)
		* 14.10.10. [binary search](#binarysearch)
		* 14.10.11. [sorting](#sorting)
		* 14.10.12. [recursion](#recursion)
		* 14.10.13. [stacks](#stacks)
		* 14.10.14. [queues](#queues)
		* 14.10.15. [trees](#trees)
		* 14.10.16. [heaps](#heaps)
		* 14.10.17. [graphs](#graphs)
		* 14.10.18. [greedy algorithms](#greedyalgorithms)
		* 14.10.19. [math](#math)
* 15. [real-time systems](#real-timesystems)
* 16. [General behavioral questions](#Generalbehavioralquestions)
* 17. [Systems design topics](#Systemsdesigntopics)
* 18. [Design patterns](#Designpatterns)
* 19. [scheduling algorithms](#schedulingalgorithms)
* 20. [Concurrency](#Concurrency)
* 21. [OpenMP](#OpenMP)
* 22. [semaphores](#semaphores)
	* 22.1. [sempahores with multiple processes in Linux](#sempahoreswithmultipleprocessesinLinux)
* 23. [monitors](#monitors)
* 24. [Deadlock](#Deadlock)
	* 24.1. [dining philosopher's problem](#diningphilosophersproblem)
	* 24.2. [resources](#resources-1)
* 25. [General interview prep resources](#Generalinterviewprepresources)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='LinuxOS'></a>Linux/OS

* process vs. thread

* segmentation fault

* ELF format


##  2. <a name='Architectural'></a>Architectural

###  2.1. <a name='pubsub'></a>pub sub
tbd

##  3. <a name='Endian-ness'></a>Endian-ness

![endian](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5d/32bit-Endianess.svg/600px-32bit-Endianess.svg.png)

* little end in first -> LSB first. x86, ARM, RISC-V uses this.
* big end in first -> MSB first. Network order. data transmitted/received from MSB onwards.
  * this is the more natural way to store it as we read it from left to right
with C you can test with
```C
union {
  uint8_t u8; uint16_t u16; uint32_t u32; uint64_t u64;
} u = { .u64 = 0x4A };

puts(u.u8 == u.u16 && u.u8 == u.u32 && u.u8 == u.u64 ? "true" : "false");

```

For little endian, data is stored as 00 00 00 4A so it will return true.

Another way which should work with cpp is at [test_endianness.cpp](./cpp_prep_notes/test_endianness.cpp)

##  4. <a name='Database'></a>Database
tbd

##  5. <a name='CICDtopics'></a>CI/CD topics
tbd
todo jenkins

* [FCC: jenkins devops](https://youtu.be/f4idgaq2VqA?si=lBI-YvmNfnpt_3pf)
###  5.1. <a name='gitlabCICD'></a>gitlab CI/CD

see this course https://www.freecodecamp.org/news/devops-with-gitlab-ci-course/


##  6. <a name='Infratoolsterraformetc'></a>Infra tools (terraform etc)
tbd

###  6.1. <a name='strace'></a>strace

###  6.2. <a name='tcpdump'></a>tcpdump

###  6.3. <a name='gdb'></a>gdb


##  7. <a name='Communications'></a>Communications
###  7.1. <a name='Cellulartopics'></a>Cellular topics

* [5G service based architecture overview](https://medium.com/5g-nr/5g-service-based-architecture-sba-47900b0ded0a)
* [telecom forum](https://www.telecomhall.net/)

* [YT: LTE feature-based intro](https://www.youtube.com/playlist?list=PLgQvzsPaZX_bimBc5Wu4m6-cVD4bZDav9)
* [YT: 5G interview topics](https://www.youtube.com/playlist?list=PL4OXTttOk9WiLsz4fR62lpPcT3Wx3l5OP)
* [Evolution of RAN](https://www.lumenci.com/research-articles/evolution-of-ran-the-road-from-1g-to-5g)



####  7.1.1. <a name='Protocols'></a>Protocols

* [YT: 5G registration](https://youtu.be/dTA0ZyHBWtc?si=zJ7BtEwBXMaBoXis)
* [YT: 5G pdu establishment](https://youtu.be/EqDpcnIX4Og?si=XgiJhw0tlRF6hCS1)

todo SCTP GTP

* https://www.3gpp.org/technologies/5g-system-overview
* https://www.3gpp.org/dynareport?code=38-series.htm

* [spec: NR and NG-RAN architecture rel 17](https://www.etsi.org/deliver/etsi_ts/138300_138399/138300/17.06.00_60/ts_138300v170600p.pdf)
* [spec: NG RAN arch](https://www.etsi.org/deliver/etsi_ts/138400_138499/138401/17.06.00_60/ts_138401v170600p.pdf)
* [5G spec mindmap](https://wirelessbrew.com/5gnr/3ggp-specs.html)
####  7.1.2. <a name='scheduling'></a>scheduling

* scheduling is process of allocating resources
* overall scheduling process in NR similar to LTE but NR has finer granularity in terms of time domain schediling in PHY

* in LTE we have pre-defined frame definitions as seen [here](https://www.sharetechnote.com/html/FrameStructure_DL.html#Overview_TDD)

![lte frame defns](https://www.sharetechnote.com/image/36_211_TDD_DL_FrameStructure.png)

* IN NR we have a more flexible approach and we can define the pattern using RRC params

* [resource allocation](https://www.sharetechnote.com/html/5G/5G_ResourceAllocation.html) and some dtails about K1, K2, N1 etc
  - k0 = time delay of num slots between DCI and PDSCH
    - if DCI and PDSCH in same slot then k0 is 0
  - depending on difference in [subcarrier spacing](https://rfmw.em.keysight.com/wireless/helpfiles/89600B/WebHelp/Subsystems/wlan-ofdm/Content/ofdm_basicprinciplesoverview.htm) of PDCCH and PDSCH we use the following formula
  - ![](https://www.sharetechnote.com/html/5G/image/NR_ResourceAllocation_TimeDomain_PDSCH_01.png)
  - k1 -> num slots between PDSCH and HARQ ACK/NACK (for retx)
  - k2 -> num of slots between PDCCH/DCI and PUSCH
  - N1 -> min time duration for decoding PDCCH to be ready for receiving PDSCH. based on UE capability.
  - NU -> min time for decoding PDCCH for UE to be ready for PUSCH. also depends on UE capability.


##### DCI
* DCI needed for
  - info to allocate physical resources for DL Data (PDSCH)
  - info to schedule UL Data (PUSCH)
  - info to adjust uplink power (PUSCH, PUCCH)
* once DCI constructed, it goes through channel coding

* TBD - CCE index calculation per [this link](https://www.sharetechnote.com/html/Handbook_LTE_CCE_Index.html)
* also read more about PDCCH [here](https://www.sharetechnote.com/html/5G/5G_PDCCH.html)
##### dynamic scheduling

* every PDSCH scheduled via [DCI](https://www.sharetechnote.com/html/5G/5G_DCI.html)
  * downlink control information (DCI) is used for scheduling UL and DL resources
  * DCI carried in PDCCH
  

##### sps scheduling

* semi persistent sched
tbd

* see [here](https://www.sharetechnote.com/html/5G/5G_Scheduling_Dynamic.html)
* read about [UCI here](https://www.sharetechnote.com/html/5G/5G_UCI.html) 

###  7.2. <a name='TCPIPreview'></a>Networking

see [TCP/IP notes](./tcp-ip/readme.md)


* [YT: Networking course videos - U of W](https://youtu.be/xKNPTYtTnAo?si=iKYFrtkcqH_mtAcA)

##  8. <a name='Ctrapsandpitfalls'></a>C traps and pitfalls

* `static`

* `volatile`

* `extern`

* mem allocations
  - malloc. no initalization.
  - calloc. zeroes out allocated memory with 0 for numeric and NUL for char buffer.
  - realloc. allocates new buffer or extends existing buffer (if you specify the old buffer address as arg and return value). contents of old buffer copied to new. realloc does not initialize storage.
  - after calling free() always set pointer to NULL!

###  8.1. <a name='pointercheatsheet'></a>pointer cheat sheet

[here](./mastering-c-pointers/Pointer%20Reference.pdf)

* see [this](./mastering-c-pointers/04_03-weekdays1.c) and [this](./mastering-c-pointers/04_03-weekdays2.c) for some
commentary on how the local are stored differently in the object file.
Compiler optimization levels may further have an impact(?)

* [C struct packing](http://www.catb.org/esr/structure-packing/)

* C standard lib functions to know
TBD

* [Why it's better to use strlcpy (via memcpy -- see comment in thread) instead of strcpy](https://stackoverflow.com/questions/1258550/why-should-you-use-strncpy-instead-of-strcpy)
  * also see [this](https://en.wikipedia.org/wiki/C_string_handling#Replacements)

* on Linux strlcpy is implemented in libbsd-dev which needs to be installed

* see [this file](./mastering-c-pointers/03_07-challenge1_attempt.c). Need to build with `-lbsd` option.


##  9. <a name='CPPLibraries'></a>CPP Libraries

###  9.1. <a name='Boost'></a>Boost
tbd

###  9.2. <a name='pybind11'></a>pybind11
tbd
todo some notes

###  9.3. <a name='STL'></a>STL

[notes here](./linkedin-cpp-stl/readme.md)


##  10. <a name='CPPtopicreviews'></a>CPP topic reviews

* `explicit` keyword

* `std::atomic`

* `extern C`

* class design

* structs vs classes

* OOP patterns

* also see [cpp templates and stl notes](./cpp-templates-and-stl/readme.md)

* also see [udefined behavior in C/C++](https://blog.regehr.org/archives/213)

* In C++ the modulo behaves differently than python

```cpp
cout << (-2 % 5) << endl; // -2
```

```python
>>> -2 % 5
3
```

###  10.1. <a name='Arrays'></a>Arrays

* `std::array` closer to standard C array
  * stored in object
  * does not decay to pointer like standard C array when passed to function since the descriptor includes size info

* THis course is excellent https://courses.mshah.io/courses/take/cpp-programming-language/texts/43118039-c-video-series-introduction-modern-cpp-series

* BEWARE [std::array size can only be specified at compile time, not dynamically, see this link](https://stackoverflow.com/questions/16711697/is-there-any-use-for-unique-ptr-with-array) 


###  10.2. <a name='Generalbestpractice'></a>General best practice

* Use signed instead of unsigned in most cases
see https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/


##  11. <a name='Debugging'></a>Debugging

* sometimes we need to disable exceptions for performance reasons. g++ turns throws into abort in that case.
see [this link](https://stackoverflow.com/questions/7249378/disabling-c-exceptions-how-can-i-make-any-std-throw-immediately-terminate)

see https://eli.thegreenplace.net/tag/debuggers

* HOW do core dumps work

##  12. <a name='Algorithms'></a>Algorithms

###  12.1. <a name='markovchains'></a>markov chains

###  12.2. <a name='Editdistance'></a>Edit distance

* TODO prefix edit distance algo important for fuzzy search

* TODO A related topic is q-gram index

####  12.2.1. <a name='resources'></a>resources

* [YT: Information retrieval course](https://youtu.be/I39Rhegg8Xg?list=PLfgMNKpBVg4V8GtMB7eUrTyvITri8WF7i&t=1856)
* https://github.com/Martinsos/edlib



###  12.3. <a name='Compressionandencoding'></a>Compression and encoding

####  12.3.1. <a name='resources-1'></a>resources

* [Google dev videos: compressor head](https://www.youtube.com/playlist?list=PLOU2XLYxmsIJGErt5rrCqaSGTMyyqNt2H)
* [Information retrieval course - compression lecture](https://www.youtube.com/playlist?list=PLfgMNKpBVg4V8GtMB7eUrTyvITri8WF7i)

##  13. <a name='Datastructures'></a>Data structures

###  13.1. <a name='ringerbuffers'></a>ringer buffers



* how to make them threadsafe
* how to make them lock free

* [A ringbuffer in C](https://csresources.github.io/SystemProgrammingWiki/SystemProgramming/Synchronization,-Part-8:-Ring-Buffer-Example/)
* [Lock free ring buffer and log](https://youtu.be/uqSeuGQhnf0?si=z9AejRLdany6VV6L)
Don't use modulo though, see the first link 

###  13.2. <a name='hashtables'></a>hash tables

* see [internals of hash tables](https://youtu.be/6D9mRll58Kg?si=AQMPV_q8mGib2Uyt)
* [how java implements concurrent hashmap](https://youtu.be/_A0Wty5Aeis?si=K-KSiYD5uTAgoFv-)

###  13.3. <a name='markovchains-1'></a>markov chains

###  13.4. <a name='huffmantrees'></a>huffman trees

see https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/Huffman.html

###  13.5. <a name='tries'></a>tries

* [YT: making a Trie](https://youtu.be/3CbFFVHQrk4?si=SevmQI7UvPaHdfYB) 

* lock free?
* threadsafe?


##  14. <a name='Gaylestips'></a>Gayle's tips

1. Make sure you identify the terms when evaluating big O, not just using a generic n term.
2. only keep the non-constant dominant terms (as long as they are for the same quantity)

```
O(d + n^2) -> O(d + n^2)
O(2^a + a^2) --> O(2^a)
```

###  14.1. <a name='Sevenstepstoproblemsolving'></a>Seven steps to problem solving

####  14.1.1. <a name='Listencarefullytotheproblem-listentoclues.'></a>1. Listen carefully to the problem - listen to clues. 

For example,

> Given two arrays that are sorted and distinct, find the number of elements in common

So the fact that they are "sorted" and "distinct" are useful clues. If your solution does not exploit this feature then
it's likely not optimal for this usecase. The brute-force approach will probably not use this information, but keep it visible and
consider it for the optimal approach which you will code.

####  14.1.2. <a name='Drawanexample'></a>2. Draw an example

Use inputs and outputs to further understand the behavior. 

Here is one possibility

```
[1,3,5,7]
[2,3,4,6]
```

But the problem is that this is a special case and you need to think of more general cases. The arrays may be different lengths
or not have any common elements, have negtive numbers etc.

####  14.1.3. <a name='Bruteforce'></a>3. Brute force

It will be slow and obvious and that is fine. But it will help you think about a starting point. Don't code this one unless asked,
but use it to explore the next step of making it optimal byt identifying the time and space complexities so you know where
you need to focus to devise a solution you can code. The brute force method may not be correct, but figure out how to correct it
after you have something.

####  14.1.4. <a name='Optimize'></a>4. Optimize

A good chunk of time will be spent on this step. **Optimize before you write code**. But, if the interviewer wants you to code the brute-force first then go ahead and do that before this step. Make sure you state the time and space complexities clearly.

####  14.1.5. <a name='Walkthroughyouralgorithm'></a>5. Walk through your algorithm

Before you start coding, walk through the algorithm with your interviewer. **Don't jump into coding with just a basic idea**!!!😥
Even if you're interviewer agrees you can start coding, think! Do you have a good idea of the algorithm?
If not then walk through it more carefully before committing. Because backing out half-way may not be the best look.

Make sure you know what the data structures are, how they change. If there are indices involved then make sure you know how they
are updated using examples.

####  14.1.6. <a name='Code'></a>6. Code

Use the language you're most comfortable with.

> My additional tips: make sure you are familiar with all the commonly used standard lib features,
> data structures and gotchas. While perfect syntax is not a hard requirement, fumbling around
> with syntax can be a huge distraction and may end being a negative

####  14.1.7. <a name='Verification'></a>7. Verification

Check the runtimes and make sure they agree with your earlier assessment. Walk through the code with examples you came up with.
Even if you have the option of testing the code, walk through them manually first. This step will help to catch any bugs you
may have in the code.

####  14.1.8. <a name='Finally'></a>Finally

Once this is done, walk through the code again and explain it. Consider it a code review session where you want to make sure the
reviewer is satisfied and will be ready to approve your code. Answer any questions they have.
This shows attention to details and that you care about code quality.


###  14.2. <a name='Example'></a>Example

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




###  14.3. <a name='OptimizingwithBUD'></a>Optimizing with BUD

BUD = Bottlenecks, Unnecessary work, Duplicated work


###  14.4. <a name='Optimizingwithspaceandtime'></a>Optimizing with space and time

* hash tables, pre-computation, tries
* think about doing some upfront work such as sorting, storing data in table etc.

###  14.5. <a name='bestconceivableruntime'></a>best conceivable runtime

Given the nature of the problem, what is the runtime that you cannot beat

Example

> given an array, find all pairs that sum to median value

You cannot do better than O(n) where n is size of array since you must access every element at least once

###  14.6. <a name='OptimizingwthDIY'></a>Optimizing wth DIY
tbd

###  14.7. <a name='Tipsforcoding'></a>Tips for coding

* Don't write loose code, write small functions
* When filling in the func impls, try a priority-based breadth first approach, work on the most useful functions first and then fill in the rest ( you need to maximize your signals to the interviewer)
* ignore things that don't show good signals but check with your interviewer first
  * So pretend you have a max/min function or such uitility and focus on the parts of the impl that matters. Fill those in the interviewer wants you to.

> My notes: Keep the code simple, don't try to be clever (no lambdas or other less common features), the goal is not to show off cleverness.
> The easier the code is for the interviewer to follow, the better. It alse reduces chances of errors.


###  14.8. <a name='verifications'></a>verifications

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

###  14.9. <a name='communications'></a>communications

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

###  14.10. <a name='Tipsbytopics'></a>Tips by topics

####  14.10.1. <a name='string'></a>string

* 

####  14.10.2. <a name='bitset'></a>bitset

see [this link too](https://en.cppreference.com/w/cpp/utility/bitset)

####  14.10.3. <a name='arrays'></a>arrays
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

####  14.10.4. <a name='vector'></a>vector
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


####  14.10.5. <a name='deque'></a>deque

* efficient add and remove from both ends of a queue

####  14.10.6. <a name='stack'></a>stack
* LIFO (mention this with stack and explain)
* can be useful when doing a reverse
* YOu can implement a linked list as a stack

####  14.10.7. <a name='strings'></a>strings

* string is a template for basic_string<char>
* since c++17 we also have a string view which gets us a read-only version
* strings can be hashed
* `substr()` creates a new string. `string_view` from C++17 more efficient as it does not make a copy.

see [cpp_prep_notes/test_string.cpp](./cpp_prep_notes/test_string.cpp)

* a reason NOT to use `stringstream`, see [this link](https://lemire.me/blog/2023/10/19/for-processing-strings-streams-in-c-can-be-slow/)

* more useful links
  * https://lemire.me/blog/2023/10/23/appending-to-an-stdstring-character-by-character-how-does-the-capacity-grow/

####  14.10.8. <a name='maps'></a>maps
* maps show up when you have a lot of lookups, frequency counting,etc 
* unordered_map usually a hash map
  * collisions

* see [computing a hash code for a string](https://youtu.be/jtMwp0FqEcg?si=1vrLrJIh6da5LQiu)

* sometimes a hashmap is an overkill and a simple array/bitset as a frequency table is sufficient

####  14.10.9. <a name='sets'></a>sets

####  14.10.10. <a name='binarysearch'></a>binary search
* when you have ordered items and are looking for something
* sometimes it may be less obvious...say when you are computing square root of an integer

####  14.10.11. <a name='sorting'></a>sorting


##### merge sort

tbd

##### quick sort

radix sort

bucket sort

tbd

tbd: example of using custom comparater


####  14.10.12. <a name='recursion'></a>recursion

* be careful, it takes time and space complexity
* depth of tree is 
* usually runtime is O(num_branches_at_each_level ^ depth), space complexity is O(log N) => O(N) where N is num of nodes
  * think of why it can be O(N)
* think about how to break down problem into subproblems
* how to idenitify this can be recursive?
  * choices at step
  * need to generate permutations of something
  * words with "superlatives": longest, shortest, biggest, all etc
  * can you divide and conquer by splitting into parts? then it can be recursive
  * TIP: tell your interviewer if you think its recursive. all recursive can be done iteratively. but should they be?
    * sometimes its ok, binary search can be clean iteratively. But other times it become more complicated.
  * be aware of the penalty of recursion in time and space
  * draw out a call tree and then see how big the tree is
* follow the idea of "trust and merge", split into parts and the subproblems take care of their parts and then you merge
* think of "damage and repair" cases. sometimes you visit nodes and then need to unvisit them.
* be careful with empty, 1/2 element cases
* make sure base case is simple...a more complex base case may be indication of an incorrect solution

####  14.10.13. <a name='stacks'></a>stacks

* FILO
* C++ has a stack class which can be used
* APIs are `push` `pop` `top` `size` `empty`
* identifying
  * anything that can benefit from LIFO
  * reversing steps, going backwards

####  14.10.14. <a name='queues'></a>queues
* FIFO
* 

####  14.10.15. <a name='trees'></a>trees
* inorder, pre-order, post-oreder traversals
* if balanced O(log N) for insert/find else it can be O(N) in worst case
* tree balacing
  * AVL trees
  * red black trees

##### tries
* useful for such things as word search problem


####  14.10.16. <a name='heaps'></a>heaps
* heaps implemente with priority queues
* when inserting, put new value in the next open spot and bubble up (depending on min-heap or max-heap)
* same with deletion (i.e pop operation)
* push/pop is then O(log n)
* since heaps are a complete binary tree they can be represented with a simple array

* here how you get left and right

```
left = 2*i + 1
right = 2*i + 2
```

##### priority_queue


####  14.10.17. <a name='graphs'></a>graphs

####  14.10.18. <a name='greedyalgorithms'></a>greedy algorithms


####  14.10.19. <a name='math'></a>math

* modulo of negative number can be negative

```cpp
    cout << "(-10 % 3) = " << (-10 % 3) << endl; // -1
    cout << "(10 % -3) = " << (10 % -3) << endl; // 1
```

##  15. <a name='real-timesystems'></a>real-time systems
[real-time-embedded-systems/readme.md](./real-time-embedded-systems/readme.md)


##  16. <a name='Generalbehavioralquestions'></a>General behavioral questions
tbd

##  17. <a name='Systemsdesigntopics'></a>Systems design topics
tbd

##  18. <a name='Designpatterns'></a>Design patterns

[notes](./design-patterns/readme.md)

##  19. <a name='schedulingalgorithms'></a>scheduling algorithms

### Fair queuing (in the context of IP networks)
* key for QoS

* Notes from [Fair queuing](https://www.youtube.com/watch?v=ISZVJjXa3G8)


* https://arxiv.org/ftp/arxiv/papers/1307/1307.4165.pdf
* https://www.aleksandrhovhannisyan.com/blog/operating-system-scheduling-algorithms/
* https://en.wikipedia.org/wiki/Maximum_throughput_scheduling
* https://en.wikipedia.org/wiki/Round-robin_scheduling
* https://en.wikipedia.org/wiki/Weighted_fair_queueing
* https://en.wikipedia.org/wiki/Proportional-fair_scheduling




##  20. <a name='Concurrency'></a>Concurrency

##  21. <a name='OpenMP'></a>OpenMP

* see [notes](./intro-to-openmp/readme.md)

* synchronization is expensive and too much of it will kill performance
* fundamental model used in OMP is fork-join model

##  22. <a name='semaphores'></a>semaphores

* a semaphore is a counter
* a mutex is a special case of a semaphore which indicates a binary choice (either you have the lock or not - count is 0 or 1)
* semaphore used to control access to a critical section


* see https://austingwalters.com/multithreading-semaphores/

###  22.1. <a name='sempahoreswithmultipleprocessesinLinux'></a>sempahores with multiple processes in Linux

tbd

* see https://blog.superpat.com/semaphores-on-linux-sem_init-vs-sem_open

##  23. <a name='monitors'></a>monitors

* see [this implementation](https://stackoverflow.com/questions/12647217/making-a-c-class-a-monitor-in-the-concurrent-sense)
* see [also this](https://stackoverflow.com/questions/57857403/c-monitor-class-wrapper-using-condition-variables?rq=3)
##  24. <a name='Deadlock'></a>Deadlock

* There are the following necessary and sufficient conditions for a deadlock



1. mutual exclusion - resource cannot be shared.
2. circular wait - cycle in [resource allocation graph](https://csresources.github.io/SystemProgrammingWiki/SystemProgramming/Deadlock,-Part-1:-Resource-Allocation-Graph/).
3. hold and wait - a process acquires incomplete set of resources and then waits to get the rest.
4. no pre-emption - once a process acquires a resource it will not voluntarily give it up and the OS will not take it away after some timeout.

* These are called Coffman conditions

###  24.1. <a name='diningphilosophersproblem'></a>dining philosopher's problem

###  24.2. <a name='resources-1'></a>resources
* see [test_mutex.cpp](./cpp_prep_notes/test_mutex.cpp)
* https://austingwalters.com/multithreading-producer-consumer-problem/
* https://austingwalters.com/multithreading-dining-philosophers-problem/

##  25. <a name='Generalinterviewprepresources'></a>General interview prep resources

* https://huyenchip.com/ml-interviews-book/contents/2.3.1-behavioral-questions.html
* https://platformalgorithmsdatastructures.kingofinterviews.com/docs/intro
* https://www.structy.net/problem-index
* https://www.khanacademy.org/computing
* https://github.com/adnanaziz/EPIJudge
* https://neetcode.io/
* https://leetcodethehardway.com/
* https://interviewing.io/guides/hiring-process
* https://github.com/donnemartin/system-design-primer




