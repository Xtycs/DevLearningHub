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
