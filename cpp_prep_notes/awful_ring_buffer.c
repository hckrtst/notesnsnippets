#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* buf[16];
// namespace rb{
//   void write(void )
// };
// void write()
int main()
{
  //char* p = buf;
  void* something = malloc(10);
  char* mystr = something; // we cannot do this in C++
  strcpy(mystr, "testing...");
  printf("%s\n", mystr);

  int ar[] = {1,3,5,7, 11};
  printf("This is for real %d\n", 2[ar]); ///wha.....??????
  return 0;  
}