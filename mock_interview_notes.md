/*


pNode->{Node}

queue contains data ot type Node*

int size() const
bool is_empty() const
bool is_full() const
bool push(int);
int front() const // exception if empty
void pop() // exception if empty

[   ]

remove(int) -> O(1)

intrnally
array [ capacity ]
2 3 4 5 1 2 3 4
      
test cases
1) create a queue
2) 

*/

// // create queue
// Queue que(capacity);

// // check size()
// assert que.size() == 0

// assert que.is_empty() == true
// assert que.is_full() == false

// assert que.front() == get_exception()
// assert que.pop() == get_exception()

// que.push(1)
// assert que.size() == 1


// que.push(2)
// que.push(3)
// que.push(4)
// assert que.size() == 4

// que.front() == 1

// empty()
// full() == false

// timeout: pop() all until empty()

struct ListNode
{
  ListNode() = delete;
  ListNode(int val):_next(nullptr), _val(val)
  {}
  ListNode* _next;
  int _val{};
};

class Queue
{
  int size() const;
  {
    return _size;
  }
  bool is_empty() const
  {
    return _size == 0;
  }
  bool is_full() const;
  bool push(int);
  int front() const; // exception if empty
  void pop()
  {} // exception if empty
  private:
    std::unique_ptr<unique_ptr<ListNode*>> _head;
    int _size{};
}; 

/*

interface -> memory leaks
pop
front
capacity may not matter upfront

network
drop tail- 

random early detection

stuck on array
linked list -> non-embedded case
class -> stuct : unnecessary

interface design vs implementation details


*/





12/13

#include <clocale>
#include <iostream>
using namespace std;

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const char* const& word : words) {
    cout << word;
  }
  return 0;
}


// foo(a) -> b
// .......work..... produce b


// a5 -> b5
// a1 -> b1
// a3 -> b3
// a4 -> b4

// cache expiration policy
// int get(int)
// void put(int, int)


// assumptions
// 1. key will exist in cache on get

/*

list
head
key2/val2  key/val
              
map

1 , it

*/

```cpp
class LRU
{
  public:
  LRU(int capacity):_cap(capacity)
  {

  }
  int get(int key)
  { // error check for not there
    return (*_map[key]).second);
  }
  
  void put(int key, int val)
  {
    if (_map.find(key) != _map.end())
    {
      // already in map
      _list.remove(_map[key]);  
    }else if (_list.size() == _cap)
    {
      // eviction
      int ekey = *(_list.back()).first;
      _list.pop_back();
      _map.erase(ekey);
    }
    _list.push_front(make_pair(key,val));
    _map[key] = _list.begin();  
  }

  private:
    const int _cap;
    list<pair<int,int>> _list;
    unordered_map<int, list<int>::iterator> _map;
};


```

// too cute with iterator
// too much detail on SLL vs DLL (save time)
// don't get hung up on the syntax



- remove year from college
-remove personal pronouns
- over use of successfully
- quantification of impact
 - too many uses of developed
 - too many collaborated
 - stronger words
 - debugging-> debugged




12/18

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.


*/


roman_to_decimal("") -> 0
roman_to_decimal("XXVII") -> 27
"IX" -> 19
"XIX" -> 29
I
II
XVII

XLI

/*

XXV
10+10




*/



int roman_to_decimal(std::string& num)
{
  unordered_map<char, int> num_map;
  // TODO fill map
  int i{num.length() - 1};
  int value = 0;
  while(i >= 0) // feddback: use for, readability
  {
    int digit = num_map[num[i]];
    if (digit >= value) {
      value += digit;
    }
    else
    {
      value -= digit;
    }
    i--;
  }
  return value;
}



1) took 30 mins --> get in 20 mins
  friendly -> 
  go faster
  don't write edge cases, but make assumptions and note
  met/google -> more focus on algorith

  should ask max size -> recursive ok, should ask question

2)  


#include <vector>
#include <queue>

using namespace std;


/*



*/
vector<int> get_right_view(Node* root)
{
  vector<int> nums;
  queue<pair<Node*, int>> que;
  int curr_level = -1;
  if (root) que.push({root, 0});
  while (que.size() > 0)
  {
    auto [front, level] = que.front();
    if (level > curr_level)
    {
      Node* back = (que.back()).first;
      nums.push_back(back->val);
      curr_level = level;
    }
    // make sure we pop after processing
    que.pop();
    if (front->left) que.push_back({front->left, level + 1});
    if (front->right) que.push_back({front->right, level + 1});
  }
  return nums;
}


// good diagram
// found a good edge condition

// diameter: don't say you don't know how to cal
// tuple -> pair micro decision

// if you get a hint, use it (don't second guess the interviewer)
// list better for dynamic lengths???





