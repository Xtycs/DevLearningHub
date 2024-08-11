#pragma once

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//队尾插入
void QueuePush(Queue* pq, QDataType x);
//队头删除
void QueuePop(Queue* pq);


QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

//! 链表的头指针和尾指针需要被修改，所以需要二级指针
//void QueuePush(QNode** pphead, QNode** pptail, QDataType x);
//void QueuePop(QNode** pphead, QNode** pptail);