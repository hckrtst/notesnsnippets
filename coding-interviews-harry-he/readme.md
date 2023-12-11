## interview process
- when describing project on interview or resume, be concise about project background and give detailed info on own tasks,actions ,contributions

- be honest when describing technical skills

- write clean, complete and robust code
  - readability is first standard of code quality (reasonable names, good spacing etc)
  - second standard is completeness
    - checking boundary conditions is critical
    - as an exampe consider the problem of writing a function to convert string to integer and a naive solution below
    ```cpp
    int str_to_int(char* s) {
      int num = 0;
      while (*s != 0) {
        num = num * 10 + *s - '0';
        ++s;
      }
      return num;
    }
    ```
    - this code misses many conditions and the author will fail the interview
      - no error handling, no boundary checking, no null checks
        - what about negative numbers, non-numeric chars, overflow 
    - another example, how to get the kth node from the tail of a list
      - say you write the following code
      ```cpp
      Node* find_kth_to_tail(Node* head, unsigned int k)
      {
        if (head == nullptr) return nullptr; // good but is this enough?
        Node* ahead = head;
        Node* behind = nullptr;
        /*
        k = 2
        1 -> 2 -> 3 -> 4 -> 5
                  a                     
        
        */
        for (int i = 0; i < k - 1; ++i) // what if k exceeds the length of list, what if k  is 0
        {
          ahead = ahead->next;
        }

        behind = head;
        while (ahead->next) {
          ahead = ahead->next;
          behind = behind->next;
        }
        return behind;
      }
      ```

      > First, don't write the code until you have fleshed out the test cases
      > then when inputs have been considered then you also need to think of optimality
      > of potential solution before writing the code
      > Always test the code with common inputs (in a test area on screen/board not executing it) and edge cases 
      > before calling it done and asking interviewer to check it 

      - clear thinking is important, how to have this:
        1. use one or two **examples** to uncover hidden rules
        2. **figures** are helpful to visualize
        3. may help to **divide** a problem into subproblems
          - many recursive, DP problems use this approach
          
### time and efficiency

- consider example of calculating fibonacci numbers
  - f(n) = f(n-1) + f(n-2) --> this has exponential time complexity: each step we double the number of function calls
  - but if we calculate this iteratively then the complexity reduces to O(n)
    - in this case we can do f(1), then f(2), f(3), f(4) .... and so on
- master the pros and cons of each data structure and use the most effective one
- be proficient in common algorithms: search and sort. if data sorted then binary search can cut time to O(logn) from O(n).
  ideas in quicksort can be used in other areas which need partitionng.

## data structures

- Q: given an array with n numbers, ranges from 0 - n-2. One number is duplicated, how can you find it in better than O(nlogn) time without sorting.

<details>
<summary> hint </summary>
- only one number is duplicate
- can you use some math?  
</details>

<details>
<summary> solution </summary>

so if we have [0,1,2,3,4,4,5] without duplicate we can have [0,1,2,3,4,5,6]
0 + 1 + 2 + 3 -> 6
(4*3) / 2 -> 6

so if we do (0+1+2+3+4+4+5) - (0+1+2+3+4+5) = 4

this will work even if last one is duplicated (0+1+2+3+4+5+5) - (0+1+2+3+4+5) = 5 and since adding is commutative order of elements does not matter

```cpp
// guaranteed to only have one duplicate
int get_dup(std::vector<int>& nums)
{
  int len = nums.size();

  int sum1 = 0;
  for (int i = 0; i < len; i++)
  {
    if (nums[i] < 0 || num[i] > len - 2) abort();
    sum1 += nums[i];
  }
  int sum2 = ((len - 1) * (len - 2)) >> 1; // which an unreadable way to say { N * (N -2) / 2 } where N = len - 1
  return sum1 - sum2;
}
```

testcases:
1. normal case
2. input is [0, 0]
3. some nums are out of range (0, n-2]

</details>

- Q: array contains nums from 0 to n-1. some nums are dups, not clear which ones or how many times they are repeated. find one of the duplicated nums in the array. example given [2,3,1,0,2,5,3] the answer should be 2 or 3.


<details>
<summary>hints</summary>

</details>


<details>
<summary></summary>
</details>


<details>
<summary></summary>
</details>