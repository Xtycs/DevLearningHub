#include"Stack.h"


void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	//! top指向栈顶元素的下一个位置, 也就是top永远指向下一个可用位置
	pst->top = 0;

	//! top指向栈顶元素,也就是说栈为空时top=-1，顶端元素在-1意思就是没有元素
	//pst->top = -1;

	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}


void STPush(ST* pst, STDataType x)
{
	assert(pst);

	// If the stack is full or empty, we need to expand the stack
	if (pst->top == pst->capacity)
	{
		int newcapacity = (pst->capacity == 0) ? 4 : pst->capacity * 2;
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

	pst->top--;// Point to the previous position
}


STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);// 不为空才能取栈顶元素

	return pst->a[pst->top - 1];//真正的栈顶元素下标是top-1，因为top指向的是下一个可用位置
}


bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}


int STSize(ST* pst)
{
	assert(pst);

	return pst->top;//top是下一个可用位置，由于下标从0开始算，所以top也就是元素个数
}