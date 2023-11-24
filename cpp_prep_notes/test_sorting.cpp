#include <iostream>
#include <vector>
using namespace std;

/*
1 2 6 9 0 9

*/
void selection_sort(vector<int> &nums)
{
  for (std::size_t i = 0; i < nums.size(); i++)
  {
    // NOTE: in the initial version I declared a var called smallest
    // and set it to nums[i] and used it to compare below in the if condition
    // BUT!!!!!!! I never updated it and that caused incorrect result
    // lesson: always be careful with variables and make sure to work through an
    // example to validate your theory....
    // I added the the variable to make it clearer that the nums[i] was the current smallest value
    // but I also need to ensure this the case where it's added complexity and caused incorrect result
    for (size_t j = i+1; j < nums.size(); j++)
    {
      if (nums[j] < nums[i]) { swap(nums[i], nums[j]); }
    }
  } 
}

/*

1, 5, 10, 2, 80
                   
    g         
       k         
*/

void _qsort(vector<int>& nums, int start, int end)
{
  // base condition
  if (start >= end) 
  {
    return;
  }
  // 1, 2, 10, 14, 8, 7
  //               i
  //       g
  //                  k      
  int pivot = nums[end];
  int g{start},k{start};

  // in first iteration I accidentally caused a seg fault which was triggerd by a stack overflow
//   #0  0x0000555555555876 in std::swap<int> (__a=<error reading variable: Cannot access memory at address 0x7fffff7feff8>,
//     __b=<error reading variable: Cannot access memory at address 0x7fffff7feff0>) at /usr/include/c++/10/bits/move.h:189
// #1  0x0000555555555387 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:52
// #2  0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #3  0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #4  0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #5  0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #6  0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #7  0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #8  0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #9  0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #10 0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #11 0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
// #12 0x0000555555555421 in _qsort (nums=std::vector of length 11, capacity 11 = {...}, start=6, end=7) at test_sorting.cpp:61
  // we can see that the start and end get's stuck in the current example
  // this happens if we start the loop at i = 0 accidentally (be careful....don't type without thinking >:(
  for (int i = start; i < end; i++)
  {
    if (nums[i] <= pivot)
    {
      swap(nums[g], nums[i]);
      g++;
      k++;
    } else 
    {
      k++;
    }
  }
  if (nums[g] > nums[end]) swap(nums[g], nums[end]);
  _qsort(nums, start, g - 1);
  _qsort(nums, g+1, end);
} 

void quick_sort(vector<int> & nums)
{
  _qsort(nums, 0, nums.size() - 1);
}

int main()
{
   vector<int> nums = {1, 100, 5, 3, 2, 8, 76, 21, -8, 0, 0};
  cout << "selection sort\n---------------\n";
  selection_sort(nums);

  for (auto e : nums) {
    cout << e << ",";
  }
  cout << endl;

  nums = {1, 100, 5, 3, 2, 8, 76, 21, -8, 0, 0};
  cout << "quick sort\n---------------\n";
  quick_sort(nums);

  for (auto e : nums) {
    cout << e << ",";
  }
  cout << endl;


}