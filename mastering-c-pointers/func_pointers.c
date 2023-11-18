#include <stdio.h>



int sum_int(int a, int b) 
{
  return (a + b);
}

float sum_float(float a, float b)
{
  return (a+b);
}

//void do_operation(char type, void *a, void *b, void (*func)(void*, void *))
void do_operation(char type, void *a, void *b, void *func)
{

  // func ptr that adds two ints and returns an int
  int (*int_adder_fp)(int a, int b);  

  float (*float_adder_fp)(float a, float b);
  
  if (type == 'i')
  {
    int_adder_fp = func;
    printf("sum = %d \n", int_adder_fp(*(int*)a, *(int*)b)); 
  } else if (type == 'f')
  {
    float_adder_fp = func;
    printf("float sum = %.4f \n", float_adder_fp(*(float*)a, *(float*)b)); 
  }

}

int main()
{
  int a, b;
  a = 10;
  b = 11;
  do_operation('i', &a, &b, &sum_int);
  
  float c,d;
  c = 1.4;
  d = 10.0;
  do_operation('f', &c, &d, &sum_float); // try sum_int, still runs but produces bad output

  // this works but is dangerous because this bypasses a lot of the type checking
  

}