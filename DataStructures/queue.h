#ifndef QUEUE_H
#DEFINE SIZE 10
#DEFINE EMPTY -1

typedef struct{
  int first;
  unsigned avail_space;
  int* list;

} queue;

queue* newQueue( unsigned cap);
void destroyQueue(struct queue* s);
void changeCapacity(struct queue* s, unsigned newCap);

int first(struct queue* s);
int size(struct queue* s);
booolean isFull(struct queue* s);
boolean isEmpty(struct queue* s);
void enqueue(struct queue* s, int data);
int dequeue(struct queue* s);

#endif
