#include "utilities.h"

#include <stdlib.h>

int* range(int min, int max)//We need to make sure this doesn't break with negatives
{
    if(distance(max,min) == 0)
      return {0};//array of size 1 with zero as its only element
    int arr[distance(max, min)];
    int j = 0;
    for(int i = min ; i < max; i++ )
    {
      arr[j++]= i;

    }

    return arr;
}

int maxElement(int* arr)
{
    if(sizeArr(arr) <= 0)
    {
      printf("Invalid Array!\n" );
      return 0;//terrible error management
    }
    int max = arr[0];
    for(int i=0 ; i< sizeArr(arr); i++)
    {
      if(max < arr[i])
        max = arr[i];
    }

    return max;
}

long distance(int from, int to)
{
  return abs(to-from);
}

long arrayMult(int* arr, int sizeArr)
{
  if(sizeArr <= 0 && arrayLength(arr) <=0)
  {
    printf("Invalid array and size!");
    return 0;
  }

  if(arrayLength(arr) < sizeArr || (sizeArr<=0 && arrayLength(arr)>=0))
    sizeArr = arrayLength(arr);

  long mult = 1;

  for(int i=0; i < sizeArr; i++)
  {
      mult *= arr[i];
  }

  return mult;
}

long arraySum(int* arr, int sizeArr)
{
  if(sizeArr <= 0 )
    return 0;

  long sum = 0;

  for(int i=0; i< sizeArr; i++)
  {
    sum+= arr[i];
  }

  return sum;
}

int* reverseArray(int* arr)
{
  if(arrayLength(arr) <= 0)
    return {};

  int size = arrayLength(arr);
  int reverse[size];
  for(int i = size-1; i >= 0 ; i++)
  {
    reverse[i] = arr[i];
  }
  return reverse;
}

char* arrayToString(int* arr)
{
  if(arrayLength(arr) <= 0)
    return {NULL};

  int size = arrayLength(arr);//because null terminated
  char str[size+1];

  for(int i=0; i< size; i++)
  {
    str[i] = arr[i];
  }

  return str;
}

void printArray(int* arr)
{
    if(arrayLength(arr) < = 0)
    {
      printf("Array is Empty!\n");
    }
    int size = arrayLength(arr)-1;//we will not print the null character
    printf("Array(%d):{", &size);
    for(int i =0 ; i < size; i++)
    {
      printf("%s \t", &arr[i]);
    }

    printf("}\n\n");
}

unsigned int arrayLength(int* arr)
{
  unsigned int length = sizeof(arr) / sizeof(int);
  return length;
}

void copyData(int* from, int* to)
{
  int lim = minSize(from, to);//we make sure to not write garbage from one to the other

  for(int i =0; i < lim ; i++)
  {
    to[i] = from[i];
  }

}

int maxSize(int* a, int* b)
{
  if(sizeof(a) > sizeof(b))
    return sizeof(a);
  return sizeof(b);
}

int minSize(int* a, int* b)
{

    if(sizeof(a) < sizeof(b))
      return sizeof(a);
    return sizeof(b);

}

void shiftDataLeft(int* arr)
{
  int size = arrayLength(arr);
  for(int i = 0; i < size  -1;i++)
  {
    arr[i] = arr[i+1];
  }
  arr[size-1] = NULL;
}
