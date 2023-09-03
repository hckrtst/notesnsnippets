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


# to not share mylist across calls set default to None
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

# working with mylists
mylist = []
mylist.append(2)
print(1, mylist)
mylist.append([2,4,5])
print(2, mylist)
mylist.extend([7, 8, 9])
print(3, mylist)
mylist.insert(0, 2.456)
print(4, mylist)
mylist.pop()
print(5, mylist)
mylist.pop(1) # pop from an index
print(6, mylist)
mylist.remove([2,4,5]) # remove specific element
print(7, mylist)
mylist.insert(1, 100)
mylist.insert(4, 100)
print(8, mylist)
mylist.remove(100) # removes first 100
print(9, mylist)
try:
    mylist.remove(1000)
except ValueError:
    print(10, '1000 not found')
mylist.append(100)
mylist.append(100)
print(11, f"100 appears {mylist.count(100)} times" )
mylist.sort()
print(12, f"sorted mylist looks like this:", mylist)

mylist.append('harry potter')

mylist.insert(0, 1090000)
mylist.insert(1, -555)

print("before sorting: ", mylist)
try:
    mylist.sort()
except:
    print(13, "now the mylist cannot be sorted because we cannot compare diff data types")
    print(14, "but mylist is partially sorted! ", mylist)

# Using mylists as stacks is efficient
stack = [1,2,5]
stack.append(8)
stack.pop()

# Using mylists as queues is not efficient as poppoing elements from front requires
# moving all the other elements
# Use deque for this

from collections import deque
queue = deque(['horus', 'porus', 'zorus'])
print("before pop: queue is ", queue)
print(15, f"Pop from queue, returns {queue.popleft()}, now the queue has {queue}")

# mylist comprehensions
squares = []

# lets see three ways of doing this
# 1.
for x in range(10):
    squares.append(x)


# 2.
squares = list(map(lambda x: x**2, range(10)))

# 3
squares = [x**2 for x in range(10)] # more concise than the other 2 options

# mylist comprehensions can have conditions as well as loops
# NOTE: the smallest list below dictates the tuples created
print(16, [(x, y) for x in [1,2,3] for y in [4,5] if x != y])

# flatten a list using list comp
vec = [[1,2,3], [5,6,7], [7,8,9]]

step = 16
def say(*args):
    global step
    step += 1
    print(step, *args)

say(vec)
say([elem for mylist in vec for elem in mylist])

# tuple packing
tup = 1, 2, 3, 'hurricane'

say(tup)

x, y, *points = 1, 5, 4, 5, 6, 7, 8

say(f"x = {x}, y = {y}, points = {points}")

# set is an unordered collection - NOTE ---> unordered
aset = set('thisissomethingsimple')
say(f"set has elems: {aset}")
setA = set('abcdef')
setB = set('defghijk')
say(f"setA = {setA} and setB = {setB}")
say(f"in A but not in B = {setA - setB}")
say(f"A union B = {setA | setB}")
say(f"A intersection B = {setA & setB}")
say(f"letters in A or B but not in both i.e. XOR = {setA ^ setB}")

# dictionaries
tel = {'jack': 4098, 'sape': 4139}

say(tel.keys())
say(tel.values())

# dict comprehensions
d = {x: x**3 for x in range(10)}
say(f"dict = {d}")

# zip can help traverese multiple collections simultaneously
cities = ['Toronto', 'New York', 'Mumbai']
countries = ['Canada', 'United States', 'India']

for city,country in zip(cities, countries):
    print(f"{city} is in {country}")

# comparisons can be chained
B = 8
C = 100

print(f"Condition C > 10 >= B is {C > 10 >= B} ")

# match
def print_city(zipcode):
    match zipcode:
        case 92101|92111|92121:
            return "San Diego"
        case 90210:
            return "Beverly Hills"
        case _:
            return "unknown"


say(f"The zipcode 92121 is in {print_city(92121)}")

