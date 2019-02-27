#ifndef STACK_H
#DEFINE SIZE 10
#DEFINE EMPTY -1
#include "utilities.h"

typedef struct{
  int top;
  unsigned capacity;
  int* list;

} stack;

stack* newStack( unsigned cap);
void destroyStack(struct stack* s);
void changeCapacity(struct stack* s, unsigned newCap);

int top(struct stack* s);
int size(struct stack* s);
booolean isFull(struct stack* s);
boolean isEmpty(struct stack* s);
void push(struct stack* s,int data);
int pop(struct stack* s);

#endif
