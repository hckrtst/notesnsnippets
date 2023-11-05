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
  return 0;  
}