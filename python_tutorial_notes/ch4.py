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
