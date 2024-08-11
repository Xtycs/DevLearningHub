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