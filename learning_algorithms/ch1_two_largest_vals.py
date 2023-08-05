def find_two_largest(A):
  first, second = A[:2]
  # we need to ensure these are correctly set to begin with
  # first must be larger than second
  if first < second:
    first, second = second, first
  
  for i in range(2, len(A)):
    if A[i] > first:
      first, second = A[i], first
    # if we never encounter a number larger than first then in the worst case we end up
    # doing both checks every iteration
    # so O(2N - 3) worst case
    # O(N - 1) best case
    # When array is in ascending order then first condition is always true - best case
    # When in descending order both conditions checked - worst case - O()
    elif A[i] > second: 
      second = A[i]
  return (first, second)  

ans = find_two_largest([4,-7,5,6,19, 0])
print(f'ans is {ans}')

