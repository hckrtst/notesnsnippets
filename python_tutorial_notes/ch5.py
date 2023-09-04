# using lists as stack
stack = [2,5,6,8]
stack.append(20)
print(stack)
print(f"popped {stack.pop()}")
print(f"top of stack = {stack[-1]}")

# while lists can be used as queues, this is less efficient as
# deleting from the front of a list is a O(n) operation
# all elements have to be shifted by one
# so use deque instead

from collections import deque

queue = deque(['eric', 'jim', 'kim'])
queue.append('himesh')
print(queue)
print(f" queue pop = {queue.popleft()}")




