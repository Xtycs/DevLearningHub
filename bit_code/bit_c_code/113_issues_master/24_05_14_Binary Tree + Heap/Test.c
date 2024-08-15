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