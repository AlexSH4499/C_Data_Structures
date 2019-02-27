#include "./utilities.h"
#inlcude  <stdlib.h>
#include <stdio.h>



void testReverse()
{
  int* arr = (int *)malloc(sizeof(int ) * 10);
  arr = range(5,15);
  printArray(arr);
  int* reverse = (int *)malloc(sizeof(int) *10);
  reverse = reverseArray(arr);
  printArray(reverse);
}

int main()
{
  testReverse();
  return 0;
}
