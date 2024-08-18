#include"Heap.h"
#include<time.h>

// void TestHeap1()
// {
// 	int a[] = { 4,2,8,1,5,6,9,7,3,2,23,55,232,66,222,33,7,1,66,3333,999 };
// 	HP hp;
// 	HPInit(&hp);
// 	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++)
// 	{
// 		HPPush(&hp, a[i]);
// 	}

// 	int i = 0;
// 	while (!HPEmpty(&hp))
// 	{
// 		printf("%d ", HPTop(&hp));
// 		a[i++] = HPTop(&hp);
// 		HPPop(&hp);
// 	}
// 	printf("\n");

// 	�ҳ�����ǰk��
// 	/*int k = 0;
// 	scanf("%d", &k);
// 	while (k--)
// 	{
// 		printf("%d ", HPTop(&hp));
// 		HPPop(&hp);
// 	}
// 	printf("\n");*/

// 	HPDestroy(&hp);
// }

// ������    O(N*logN)
// ð������  O(N^2) 
// void HeapSort(int* a, int n)
// {
// 	���򣬽�С��
// 	���򣬽����
// 	���ϵ������� O(N*logN)
// 	/*for (int i = 1; i < n; i++)
// 	{
// 		AdjustUp(a, i);
// 	}*/

// 	���µ������� O(N)
// 	for (int i = (n-1-1)/2; i >= 0; i--)
// 	{
// 		AdjustDown(a, n, i);
// 	}

// 	O(N*logN)
// 	int end = n - 1;
// 	while (end > 0)
// 	{
// 		Swap(&a[0], &a[end]);
// 		AdjustDown(a, end, 0);
// 		--end;
// 	}
// }

//! Topk问题的第二种解法（节省空间）
void TestHeap2()
{
	int a[] = { 4,2,8,1,5,6,9,7,2,7,9};
	HeapSort(a, sizeof(a) / sizeof(int));
}

void CreateNDate()
{
	// 造数据
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

	// 读取前K个数据
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}//放入数据时是"%d\n", 读取数据时是"%d", 因为fscanf会自动忽略空格、换行符、制表符等空白字符

	// 11:51����
	// 建K个数的小堆
	for (int i = (k-1-1)/2; i>=0 ; i--)
	{
		AdjustDown(kminheap, k, i);
	}

	// 读取剩下的N-K个数据
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