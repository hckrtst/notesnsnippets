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
        1. use one or two examples 


Welcome to your interviewing.io interview.

Once you and your partner have joined, a voice call will start automatically.

Use the language dropdown near the top right to select the language you would like to use.

You can run code by hitting the 'Run' button near the top left.

Enjoy your interview!


win condition is: you call the cards and collect the nums, if your can get a card from a stack, until total number <= 21
if total number is greater 21, such 22, you lost the game


[1,2,3,4,5,6,7,8,10,11,12,13] * 4 = 52 cards, 
you need to calculate the probability that you can win the game
if the total number is greater than 17, you stop to call a new card: return way to win the game + 0
if the total number is within 11 and 17, can you can pick a card? : pick  / not pick, return way to win the game +1
if the total number is equal to less than 10, you always call a new card: keep calling a new card

[1,2,3,4,5,6,7,8,10,11,12,13] -> 1,
  [1,2,3,4,5,6,7,8,10,11,12,13] -> 1, 
    [1,2,3,4,5,6,7,8,10,11,12,13] -> 1


  (A) recursion
  (B) binary search
  (C) DFS

  1st round: [1,2,3,4,5,6,7,8,10,11,12,13], you get: 1, total: 1, 
   2nd round: [1,2,3,4,5,6,7,8,10,11,12,13], you get: 2, total: 3,
    3rd round: [1,2,3,4,5,6,7,8,10,11,12,13], you get: 13, total: 16 -> 2nd policy: : probability: ? 

  base case = when you need to halt the algo: 
      if (card>= 17) halt
      


input: [1,2,3,4,5,6,7,8,9,10,11,12,13] 

count how many ways you can win the game
