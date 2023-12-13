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







