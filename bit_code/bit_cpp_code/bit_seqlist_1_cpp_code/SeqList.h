typedef int SLDataType;//only need to change this line to change the type of the list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

typedef struct SeqList
{
    SLDataType *arr;
    int size;
    int capacity;
} SL;

//initialize the list
void SLInit(SL &s);
//delete the list
void SLDestroy(SL &s);

//special functions
void SLPrint(const SL &s);
void SLCheckCapacity(SL &s);
int SLFind(SL &ps, SLDataType x);//return value is the index

void SLPushback(SL &s, SLDataType x);
void SLPushfront(SL &s, SLDataType x);

void SLPopback(SL &s);
void SLPopfront(SL &s);

void SLInsert(SL &ps, int pos, SLDataType x);
void SLErase(SL &ps, int pos);