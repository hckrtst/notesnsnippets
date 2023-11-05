#include <stdio.h>

void func(char num_str[])
{
  printf("In func: size of num_str is %d\n", sizeof(num_str));
}


int main() {
  char num_str[] = "12345";
  printf("size of num_str is %d\n", sizeof(num_str));
  func(num_str);
}