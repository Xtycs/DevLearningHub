<img src = ./5-19-上午.png/>

### Test.c （主要讲解找出数据中最大的k个数，Topk问题的第二种解法）
```c
#include"Heap.h"
#include<time.h>

//! Topk问题的第二种解法（节省空间）
void TestHeap2()
{
	int a[] = { 4,2,8,1,5,6,9,7,2,7,9};
	HeapSort(a, sizeof(a) / sizeof(int));
}

// 1.造数据
void CreateNDate()
{
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		int x = (rand()+i) % 10000000;//所有写进数据都小于10000000
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);//fin is the file pointer, not the file name
}

void TestHeap3()
{
	int k;
	printf("Enter k: ");
	scanf("%d", &k);
	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	// 2.读取前K个数据
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}//放入数据时是"%d\n", 读取数据时是"%d", 因为fscanf会自动忽略空格、换行符、制表符等空白字符


	// 3.建K个数的小堆
	for (int i = (k-1-1)/2; i>=0 ; i--)
	{
		AdjustDown(kminheap, k, i);
	}

	// 4.读取剩下的N-K个数据，只要比堆顶大的就替换堆顶
	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)//读到文件末尾或错误时，返回EOF(-1)
	{
		if (x > kminheap[0])
		{
			kminheap[0] = x;
			AdjustDown(kminheap, k, 0);
		}
	}

	printf("最大前%d个数", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kminheap[i]);
	}
	printf("\n");


	fclose(fout); // Close the file
    free(kminheap); // Free the allocated memory
}

int main()
{
	//CreateNDate();

	TestHeap3();

	return 0;
}
```