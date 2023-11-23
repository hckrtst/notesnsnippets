## basics
* SMP (symmetric multi processing) - each block of memory has roughly the same cost
  * last true SMP was cray
  * new cache arch dicatates that new CPUs are not truly SMP - keep in mind the cache hierarchy
* NUMA (Non uninform mem access) - diff mem regions have diff costs. concept of near and far memory.
* with threads the program is fargmented as follows
![Alt text](image.png)

## example 1

* use SPMD
* Notes to self
  - thnk about a specific example and work through it step by step before diving into
  the implementation
  - how many threads is too many? can you allocate an array of that size on the stack?
  - how can you make an incremental improvement first, don't try to optimize everything in one step...you will fail if you do that
  



## resources
* [YT: Intel OpenMP series](https://www.youtube.com/playlist?list=PLLX-Q6B8xqZ8n8bwjGdzBJ25X2utwnoEG)