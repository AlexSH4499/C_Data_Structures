#include "queue.h"

queue* newQueue( unsigned cap)
{
  if( cap <= 0)
    cap = SIZE;
  struct queue* q = (struct queue *)malloc(sizeof(struct queue));
  q->list = (int *)malloc(sizeof(int)*cap);
  q->avail_space = cap;
  q->first = 0;
  return q;
}

void destroyQueue(struct queue* q)
{
  q->avail_space  = NULL;
  q->first = NULL;
  free(q->list);
  free(q);
}

void changeCapacity(struct queue* q, unsigned newCap)
{
  int newArr* = (int *)malloc(sizeof(int)*newCap);
  copyData(q->list, newArr);
  free(q->list);
  q->list = newArr;
}

int first(struct queue* q)
{
  return q->list[q->first];
}

int size(struct queue* q)
{
  return q->avail_space;
}

booolean isFull(struct queue* q)
{
    return size(q) == arrayLength(q->list);
}

boolean isEmpty(struct queue* q)
{
  return size(q) == 0;
}

void enqueue(struct queue* q, int data)
{
  if(isFull(q))
  {
    changeCapacity(q,arrayLength(q->list)* 2);
  }
  q->list[q->avail_space++] = data;
}

int dequeue(struct queue* q)
{
  if(isEmpty(q))
  {
    printf("Error: Queue is empty!\n");
    return 0;
  }
  int result = q->list[q->first];

  shiftDataLeft(q->list);
  q->avail_space--;
  return result;
}
