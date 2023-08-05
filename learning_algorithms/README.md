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

```mermaid
  graph TD;
      A-->B;
      A-->C;
      B-->D;
      C-->D;
```
