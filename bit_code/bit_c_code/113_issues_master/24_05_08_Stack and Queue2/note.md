<img src=D:\code\113-issues-master\113-issues-master\24年-05月08日--栈和队列\5-8.png/>

***Queue在此使用单链表实现，在右侧尾部入队，左侧头部出队***
## Queue.h
```c
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
```

## Queue.c
```c
#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);

		cur = next;
	}

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}


void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));//只创建一个节点，不需要单写一个BuyNode函数
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}

	newnode->next = NULL;
	newnode->val = x;

	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}

	pq->size++;
}


void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);

	/*QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;

	if (pq->phead == NULL)//! avoid ptail to become a dangling pointer(悬空指针)
		pq->ptail = NULL;*/

    //以下写法更清晰
	//不要忘记判断是否只有一个节点
	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}

	pq->size--;
}

//在类似取号的场景中，需要用到取队头和取队尾的操作
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->phead->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->val;
}


int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->size == 0;
}
```
# Leetcode题目：

## 第一题：225 用队列实现栈

### 思路：
- 使用两个Queue，永远保持一个Queue为空，另一个Queue存储元素。
- 每次`push`元素时，将元素`push`到非空的Queue中。
- 每次`pop`元素时，将非空的Queue中的元素依次`pop`并`push`到另一个Queue中，直到非空的Queue中只剩一个元素，将其`pop`出来即可。

### 注意：
- 在`myStackFree`中，`free`掉Stack会连带着`free`两个Queue。
- 但是Queue中每个node没有被`free`，依然需要使用Queue的工具函数进行`destroy`（这个要最先进行，否则无法获取Queue的地址了）。

## 第二题：循环队列

### 澄清：
- 这个循环队列不允许在满的情况下直接覆盖数据，即不允许在`tail == head`的情况下`push`数据，这样会导致`pop`出来的数据不是最先`push`的数据。因此产生了假溢出问题，有判断是否为满的需求。

### 实现细节：
1. **如何实现回绕？**
   - 使用`(tail/head + 1) % (数组大小)`来计算每次`push/pop`元素后`tail/head`移动到的位置。

2. **`head == tail`时，队列是空还是满？（假溢出问题）**
   - **方法一**：多设置一个变量`size`，当`size == 0`时，队列为空；当`size == capacity`时，队列满。
   - **方法二**：数组中空出一个位置不放置元素，使用`(tail + 1) % (数组大小)`来计算每次插入元素后`tail`移动到的位置，当这个值也就是`(tail + 1) % (数组大小) == head`时说明队列满了。若仍然`push`的话，`head == tail`会导致后续所有判断是否为满的函数失效。
     - 这需要创建Queue时使用`k + 1`进行`malloc`，同时在后续所有判断时都`% (k + 1)`（心法就是循环时永远模数组的真实总大小，而此时的总大小应当是`k + 1`）。

### 特殊求法：
```c
int myCircularQueueRear(MyCircularQueue* obj) {
    if (MyCircularQueueIsFull(obj))
        return -1;
    else
        return obj->a[(obj->tail - 1 + obj->k + 1) % (obj->k + 1)];
}
// tail不为0时，tail-1加k+1，再模k+1，结果其实就是tail-1
// tail为0时，tail-1加k+1，此时模k+1其实没有任何效果，结果就是k（最后一个元素的下标）
```

# Leetcode Problems

## Problem 1: Implement Stack using Queues (Leetcode 225)

### Approach:
- Use two Queues.
- Always keep one Queue empty and store elements in the other Queue.
- For each `push` operation, push the element into the non-empty Queue.
- For each `pop` operation, pop elements from the non-empty Queue and push them into the empty Queue until only one element is left in the non-empty Queue. Pop and return this element.

### Note:
- In `myStackFree`, freeing the Stack will also free the two Queues.
- However, each node in the Queue is not freed. You still need to use the Queue's utility function to destroy it (this should be done first, otherwise, you won't be able to get the Queue's address).

## Problem 2: Circular Queue

### Clarification:
- This circular queue does not allow overwriting data when full. That is, pushing data when `tail == head` is not allowed, as it would result in popping data that was not pushed first. This leads to the issue of false overflow, requiring a check for fullness.

### Implementation Details:
1. **How to Implement Wrap-Around?**
   - Use `(tail/head + 1) % (array size)` to calculate the position of `tail/head` after each `push/pop` operation.

2. **Is the Queue Empty or Full when `head == tail`? (False Overflow Issue)**
   - **Method 1**: Use an additional variable `size`. When `size == 0`, the queue is empty; when `size == capacity`, the queue is full.
   - **Method 2**: Leave one position in the array empty. Use `(tail + 1) % (array size)` to calculate the position of `tail` after each insertion. When this value equals `head`, the queue is full. If you still push, `head == tail` will cause all subsequent checks for fullness to fail.
     - This requires using `k + 1` for `malloc` when creating the Queue, and using `% (k + 1)` in all subsequent checks (the principle is to always modulo the actual total size of the array, which is `k + 1`).

### Special Calculation:
```c
int myCircularQueueRear(MyCircularQueue* obj) {
    if (MyCircularQueueIsFull(obj))
        return -1;
    else
        return obj->a[(obj->tail - 1 + obj->k + 1) % (obj->k + 1)];
}
// When tail is not 0, tail-1 plus k+1, then modulo k+1, the result is actually tail-1.
// When tail is 0, tail-1 plus k+1, modulo k+1 has no effect, the result is k (the index of the last element).