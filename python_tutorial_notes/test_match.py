def print_points(point):
    match point:
        case (0,y):
            print(f'The point is (0,{y})')
        case _:
            print('this is the default case')


print_points('xyz')
print_points((0,-5.789))