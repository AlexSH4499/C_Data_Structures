#include <stdio.h>
#include "stack.h"


/*Creates a new stack instance with default size*/
stack* newStack( unsigned cap){
  struck stack* s =  (struct stack *)malloc(sizeof(struct stack));
  s->capacity = cap;
  s->list = (int*)malloc(sizeof(int) * cap);
  s->top = EMPTY;//This will let us know stack is empty
  return s;
}

int top(struct stack* s)
{
  if(isEmpty(s))
  {
    printf("Error: stack is empty\n\n");
    return EMPTY;
  }
  return  s->list[s->top];
}

void changeCapacity(struct stack* s, unsigned newCap)
{
  int* newArray = (int *) malloc(sizeof(int) * newCap);

  if(!isEmpty(s))
  {
    //Transfer all data to new array
    copyData(s->list, newArray);
  }

  free(s->list);//We might have a memory problem here, im not too practiced
  s->list = newArray;

}

booolean isFull(struct stack* s)
{return s->top == s->capacity-1;}

boolean isEmpty(struct stack* s)
{  return s->top == EMPTY;}

int size(struct stack* s)
{return s->capacity;}

void push(struct stack* s,int data)
{
  if(isFull(s))
  {
      //We got a problem, we have to reallocate
      changeCapacity(s, s->capacity * 2);
  }
  s->list[s->capacity + 1] = data;
  s->top++;
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

void copyData(int* from, int* to)
{
  int lim = minSize(from, to);//we make sure to not write garbage from one to the other

  for(int i =0; i < lim ; i++)
  {
    to[i] = from[i];
  }

}

int pop(struct stack* s)
{
  int result = s->list[s->top];
  s->list[s->top]= NULL;
  //Move pointer forward by one
  s->top--;
  // We dont modify the size, what do
  return result;
}

void destroyStack(struct stack* s)
{
  s->capacity =NULL;
  s->top = NULL;
  free(s->list);
  free(s);
}
