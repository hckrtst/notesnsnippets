#include <stdio.h>

void func(char num_str[])
{
  printf("In func: size of num_str is %d\n", sizeof(num_str));
}


int main() {
  char num_str[] = "12345";
  printf("size of num_str is %d\n", sizeof(num_str));
  func(num_str);

  char* ptr = num_str;
  printf("size of ptr is %d, and size of *ptr is %d, size of &ptr is %d\n", sizeof(ptr), sizeof(&ptr));
  char **ptr_ptr = &ptr;
  printf("size of Ptr_ptr is %d\n", sizeof(ptr_ptr));

}