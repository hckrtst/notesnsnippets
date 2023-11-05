#include <stdio.h>
#include <string.h>

int main() {
  char *upped = strdup("strtok,is,tricky,!!!");
  char *start = strtok(upped, ",");
  do {
    printf("%s\n", start);
  } while((start = strtok(NULL, ",")));


  {
    char *upped = strdup("strtok,is,,,,very;;;tricky,!!!");
  char *start = strtok(upped, ",;");
  do {
    printf("%s\n", start);
  } while((start = strtok(NULL, ",;")));

  printf("upped = %s\n", upped);
  }

  return 0;
}