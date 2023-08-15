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