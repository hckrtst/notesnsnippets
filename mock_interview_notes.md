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









