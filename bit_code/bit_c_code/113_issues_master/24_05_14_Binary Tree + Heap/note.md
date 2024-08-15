<img src = ./5-14.png/>

### Heap.h
```c
#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void Swap(HPDataType* p1, HPDataType* p2);
void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, int n, int parent);

void HPInit(HP* php);
void HPDestroy(HP* php);
void HPPush(HP* php, HPDataType x);
void HPPop(HP* php);
HPDataType HPTop(HP* php);
bool HPEmpty(HP* php);
```

### Heap.c
```c
#include"Heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	// 初始条件
	// 中间过程
	// 结束条件
	int parent = (child - 1) / 2;
	//while (parent >= 0) 这个凑巧也可行，但是由于除法取整问题parent实际上只能变为0
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		php->a = tmp;
		php->capacity = newcapacity;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

//                              n是size， parent是0
void AdjustDown(HPDataType* a, int n, int parent)
{
	// 先假设左孩子小,与最小的child交换才能满足minHeap的性质
	int child = parent * 2 + 1;

	while (child < n)  // child >= n 说明child已经越界了
	{
		//                      child+1 在这里可能越界
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// Pop删除尾部数据没有意义，默认要求删除堆顶数据（root）
// logN
//! 交换了头尾元素然后size--删除，最大程度保证了原本小堆的结构（大小亲缘关系），左子树和右子树都仍然是minHeap，所以只需要向下调整一次即可
//! 如果直接删除头元素，或直接进行内存位置调整，亲缘关系会被破坏，需要重新调整
void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size-1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}

HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

bool HPEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}
```

### Test.c
```c
#include"Heap.h"

void TestHeap1()
{
	int a[] = { 4,2,8,1,5,6,9,7,3,2,23,55,232,66,222,33,7,1,66,3333,999 };
	HP hp;
	HPInit(&hp);
	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}

    //!排序方法1
	int i = 0;
	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		//a[i++] = HPTop(&hp);// 在取出栈顶元素后直接覆盖在原数组上可行
		HPPop(&hp);
	}
	printf("\n");

	
	// 要求找出最大的前k个数（最有钱的前k个人）
	int k = 0;
	scanf("%d", &k);
	while (k--)
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");

	HPDestroy(&hp);
}

//! 能不能不建堆，而是直接在原数组上进行堆排序？之前所写的所有堆函数的参数都是HPDataType* a，而不是HP* php，这样就可以直接在原数组上进行堆排序
// 堆排序    O(N*logN)
// 冒泡排序  O(N^2) 
void HeapSort(int* a, int n)
{
	//todo 建堆方法1 复杂度O(N*logN)
	// 建大堆来排降序？
	// 建小堆来排升序？
	// 错，应当建小堆来排降序，建大堆来排升序 (感觉是反过来的)
	for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i); //将首元素视为一个堆，每次都把数组a中下标为i的元素视为新插入的元素进行向上调整，改变AdjustUp函数大于小于号即可变为大堆或小堆
	}
    //这一步完成后已经是一个大堆或者小堆，但是仍然不是有序的，需要继续操作

	//todo 建堆方法2 复杂度O(N)
	for (int i = (n-1-1)/2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

    //!排序方法2
    //!上面两种方法都只实现了大堆或小堆的建立，但是并没有实现排序，下面是实现排序的代码
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}




void TestHeap2()
{
	int a[] = { 4,2,8,1,5,6,9,7,2,7,9};
	HeapSort(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestHeap2();

	return 0;
}
```