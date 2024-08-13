#include<stdio.h>
#include<stdlib.h>
//
//int main()
//{
//	// 原地扩容
//	// 异地扩容
//	int* p1 = (int*)malloc(8);
//	printf("%p\n", p1);
//
//	int* p2 = (int*)realloc(p1, 80);
//	printf("%p\n", p2);
//
//	free(p2);
//
//
//	int i = 0;
//	int ret1 = ++i;
//
//	int ret2 = i++;
//
//
//
//	return 0;
//}

#include"Stack.h"

//int main()
//{
//	ST s;
//	STInit(&s);
//	STPush(&s, 1);
//	STPush(&s, 2);
//	STPush(&s, 3);
//	STPush(&s, 4);
//
//	printf("%d\n", STTop(&s));
//	STPop(&s);
//	printf("%d\n", STTop(&s));
//	STPop(&s);
//	STPop(&s);
//	STPop(&s);
//	STPop(&s);
//
//	//printf("%d\n", STTop(&s));
//
//	STDestroy(&s);
//
//	return 0;
//}

//int main()
//{
//	// 入栈：1 2 3 4
//	// 出栈：4 3 2 1  /  2 4 3 1
//	ST s;
//	STInit(&s);
//	STPush(&s, 1);
//	STPush(&s, 2);
//
//	printf("%d ", STTop(&s));
//	STPop(&s);
//
//	STPush(&s, 3);
//	STPush(&s, 4);
//
//	while (!STEmpty(&s))
//	{
//		printf("%d ", STTop(&s));
//		STPop(&s);
//	}
//
//	STDestroy(&s);
//}

#include"Queue.h"

//int main()
//{
//	
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	printf("%d ", QueueFront(&q));
//	QueuePop(&q);
//
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//
//	while (!QueueEmpty(&q))
//	{
//		printf("%d ", QueueFront(&q));
//		QueuePop(&q);
//	}
//	printf("\n");
//
//	return 0;
//}

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

// 初始化和销毁
void STInit(ST* pst);
void STDestroy(ST* pst);

// 入栈  出栈
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

// 取栈顶数据
STDataType STTop(ST* pst);

// 判空
bool STEmpty(ST* pst);
// 获取数据个数
int STSize(ST* pst);

// 初始化和销毁
void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	// top指向栈顶数据的下一个位置
	pst->top = 0;

	// top指向栈顶数据
	//pst->top = -1;

	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

// 入栈  出栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);

	// 扩容
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	pst->top--;
}

// 20:08继续
// 取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}

// 判空
bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

// 获取数据个数
int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}


typedef struct {
	ST pushst;
	ST popst;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));

	STInit(&(obj->pushst));
	STInit(&(obj->popst));

	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&(obj->pushst), x);
}

int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek(obj);
	STPop(&(obj->popst));
	return front;
}

int myQueuePeek(MyQueue* obj) {
	if (STEmpty(&(obj->popst)))
	{
		// 倒数据
		while (!STEmpty(&(obj->pushst)))
		{
			int top = STTop(&(obj->pushst));
			STPush(&(obj->popst), top);
			STPop(&(obj->pushst));
		}
	}

	return STTop(&(obj->popst));
}

bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(&(obj->popst)) && STEmpty(&(obj->pushst));
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&(obj->popst));
	STDestroy(&(obj->pushst));
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

//int main()
//{
//	MyQueue* obj = myQueueCreate();
//	myQueuePush(obj, 1);
//	myQueuePush(obj, 2);
//
//	int front = myQueuePeek(obj);
//	int ret = myQueuePop(obj);
//	bool flag = myQueueEmpty(obj);
//
//
//	return 0;
//}

// 明确树的度是N
//#define N  4
//struct TreeNode
//{
//	int val;
//	struct TreeNode* subs[N];
//};

// 如果没有明确树的度
//struct TreeNode
//{
//	int val;
//	//SeqList subs; // 顺序表内部存struct TreeNode*
//	//vector<struct TreeNode*> subs;
//};

struct TreeNode
{
	int val;

	struct TreeNode* leftchild;
	struct TreeNode* rightBrother;
};

int main()
{


	return 0;
}