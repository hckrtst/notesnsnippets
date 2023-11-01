#include <iostream>
using std::cout, std::endl;

int main()
{
  int arr[] = {1,3,7,9,11};
  auto* ptr = arr;
  void*ptr2 = arr;
  char* ptr3 = (char*)arr;

  // if you declare ptr as void* you cannot do any of these
//   pointers.cpp:9:31: error: ‘void*’ is not a pointer-to-object type
//     9 |   cout << "value at 0 is " << *ptr << endl;
//       |                               ^~~~
// pointers.cpp:10:7: warning: pointer of type ‘void *’ used in arithmetic [-Wpointer-arith]
//    10 |   ptr += 1;
//       |   ~~~~^~~~
// pointers.cpp:11:31: error: ‘void*’ is not a pointer-to-object type
//    11 |   cout << "next value is " << *ptr << endl;
  cout << "value at 0 is " << *ptr << endl;
  ptr += 1;
  cout << "next value is " << *ptr << endl;

  cout << " now using char* " << endl;
  cout << "at 0 " << *(ptr3) << endl;
  cout << "at 1 " << *(ptr3+1) << endl;
  cout << "at 2 " << *(ptr3+2) << endl;
  cout << "at 4 " << *(ptr3+4) << endl;

  return 0; 

}