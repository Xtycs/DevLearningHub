#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

// 初始化栈，销毁栈
void STInit(ST* pst);
void STDestroy(ST* pst);

// 入栈，出栈
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);

// 获取栈顶元素
STDataType STTop(ST* pst);

// 判断栈是否为空
bool STEmpty(ST* pst);
// 获取数据元素
int STSize(ST* pst);
