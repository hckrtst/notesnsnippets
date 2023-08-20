def print_points(point):
    match point:
        case (0,y):
            print(f'The point is (0,{y})')
        case _:
            print('this is the default case')


print_points('xyz')
print_points((0,-5.789))

# loops

# Create a sample collection
users = {'Hans': 'active', 'Éléonore': 'inactive', '景太郎': 'active'}

# Strategy:  Iterate over a copy
for user, status in users.copy().items():
    if status == 'inactive':
        del users[user]

print(users)

# else with for loops
for i in range(5):
    print(f"i = {i} ")
else:
    print('got else in "for"')

for i in range(5):
    print(f"i = {i} ")
    if (i == 4): break
else:
    print('this "else" not printed')


# continue
for num in range(2, 15):
    if num % 2 == 0:
        print(f'{num} is even')
        continue
    print(f'{num} is odd')

# functions
#

def fib(n):
    fib_nums = []
    a, b = 0, 1
    while(a < n):
        fib_nums.append(a)
        a, b = b, a+b
    return fib_nums
N = 2000
print(f'fib({N}) = ', fib(N))

# default parmater behavior

def func1(val, L=[]):
    L.append(val)
    print(L)

func1(3)
func1(4.5)
func1('kitty')
# the temporary will continue to be used for each subsequent call

# Here, X is a primitive so it is not shared across calls 
def accumulate(n, X=1):
    X *= n
    print(f"accumumated {X}")

accumulate(3)
accumulate(4)
accumulate(10)
    

# to not share list across calls set default to None
def func2(val, L=None):
    if not L:
        L = []
    L.append(val)
    print(L)

func2(3)
func2(4.5)
func2('kitty')    

# optional variable and keyword arguments
def cheese_shop(kind, *args, **kwargs):
    print("-- Do you have any ", kind, "?")
    print("-- I'm sorry, we're all out of", kind)
    for arg in args:
        print(arg)
    print("-"*40)
    for kw in kwargs:
        print(kw, ":", kwargs[kw])

cheese_shop("Limburger", "It's very runny, sir.",
           "It's really very, VERY runny, sir.",
           "...very runny indeed...",
           shopkeeper="Michael Palin",
           client="John Cleese",
           sketch="Cheese Shop Sketch")

# As guidance:

#     Use positional-only if you want the name of the parameters to not be available to the user.
#     This is useful when parameter names have no real meaning, if you want to enforce the order of 
#     the arguments when the function is called or if you need to take some positional parameters and arbitrary keywords.

#     Use keyword-only when names have meaning and the function definition is more understandable by being explicit 
# with names or you want to prevent users relying on the position of the argument being passed.

#     For an API, use positional-only to prevent breaking API changes if the parameter’s name is modified in the future.

# working with lists
list = []
list.append(2)
print(1, list)
list.append([2,4,5])
print(2, list)
list.extend([7, 8, 9])
print(3, list)
list.insert(0, 2.456)
print(4, list)
list.pop()
print(5, list)
list.pop(1) # pop from an index
print(6, list)
list.remove([2,4,5]) # remove specific element
print(7, list)
list.insert(1, 100)
list.insert(4, 100)
print(8, list)
list.remove(100) # removes first 100
print(9, list)
try:
    list.remove(1000)
except ValueError:
    print(10, '1000 not found')
list.append(100)
list.append(100)
print(11, f"100 appears {list.count(100)} times" )
list.sort()
print(12, f"sorted list looks like this:", list)

list.append('harry potter')

list.insert(0, 1090000)
list.insert(1, -555)

print("before sorting: ", list)
try:
    list.sort()
except:
    print(13, "now the list cannot be sorted because we cannot compare diff data types")
    print(14, "but list is partially sorted! ", list)

# Using lists as stacks is efficient
stack = [1,2,5]
stack.append(8)
stack.pop()

# Using lists as queues is not efficient as poppoing elements from front requires
# moving all the other elements
# Use deque for this

from collections import deque
queue = deque(['horus', 'porus', 'zorus'])
print("before pop: queue is ", queue)
print(15, f"Pop from queue, returns {queue.popleft()}, now the queue has {queue}")

# list comprehensions
squares = []

# lets see three ways of doing this
# 1.
for x in range(10):
    squares.append(x)

# 2.
squares = list(map(lambda x: x**2, range(10)))

# 3
squares = [x**2 for x in range(10)] # more concise than the other 2 options
