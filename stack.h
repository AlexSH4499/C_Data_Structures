#IF_N_DEF STACK_H
#DEFINE SIZE 10
#DEFINE EMPTY -1

typedef struct{
  int top;
  unsigned capacity;
  int* list;

} stack;

stack* newStack( unsigned cap);
int top(struct stack* s);
void changeCapacity(struct stack* s, unsigned newCap);
booolean isFull(struct stack* s);
boolean isEmpty(struct stack* s);
int size(struct stack* s);
void push(struct stack* s,int data);
int pop(struct stack* s);
void destroyStack(struct stack* s);

int maxSize(int* a, int* b);
int minSize(int* a, int* b);
void copyData(int* from, int* to);
#ENDIF
