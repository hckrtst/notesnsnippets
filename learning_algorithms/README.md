# Problem Solving

## Find two largest value in list

see example

## Analysis

1. How much extra storage?
2. How fewer lines of code?
3. Does algorithm mutate input data?
4. Does algorithm perform well independent of the given input

## Some more ways to do this problem using more python solutions

```py

# O(n) space
# O(nlogn) due to use of the sorting algorithm
def sorting_two(A):
  return tuple(sorted(A, reverse=True)[:2])

# O(n) space
# O(n) time
def double_two(A):
  first = max(A)
  copy = list(A)
  copy.remove(first)
  return (first, max(copy))

# mutates the list to get second max value
def mutable_two(A):
  # pythonic hack to apply max to the items of the list
  # and return the index of that item
  index = max(range(len(A)), key=A.__getitem__)
  first = A[index]
  del A[index]
  second = max(A)
  A.insert(index, first)
  return (first, second)
```

## Tournament algorithm

```
Given [3,1,4,1,5,9,2,6]
round 1
compare 3,1 -> 3 wins
compare 4,1 -> 4 wins
cmp 5,9 -> 9 wins
cmp 2,6 -> 6 wins

round2
cmp 3,4 -> 4 wins
cmp 9,6 -> 9 wins

round3
cmp 4,9 -> 9 wins


```

But how do we get the second-largest value?

That value lost to the largest value in one of the rounds. Not necessarily the last round...see why?

### Complexity


