#ifndef UTILITIES_H

int* range(int min, int max);
long distance(int from , int to);
unsigned int arrayLength(int* arr);

long arraySum(int* arr, int sizeArr);
long arrayMult(int* arr, int sizeArr);

int* reverseArray(int* arr);
unsigned int arrayLength(int* arr);
char* arrayToString(int* arr);
void copyData(int* from, int* to);
void printArray(int* arr);
void shiftDataLeft(int* arr);

int maxElement(int* arr);
int maxSize(int* a, int* b);
int minSize(int* a, int* b);
#endif
