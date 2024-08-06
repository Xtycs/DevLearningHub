#include<stdio.h>
#include<time.h>

//int main()
//{
//	//int begin1 = clock();
//	//int n = 100000000;
//	//int x = 10;
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	++x;
//	//}
//	//int end1 = clock();
//
//	// 16:00继续
//	int x = 0;
//	int begin2 = clock();
//	int n1 = 100000;
//	for (int i = 0; i < n1; ++i)
//	{
//		for (int j = 0; j < n1; j++)
//		{
//			for (int k = 0; k < n1; k++)
//			{
//				++x;
//			}
//		}
//	}
//	int end2 = clock();
//
//	printf("%d\n", x);
//	//printf("%d ms\n", end1-begin1);
//	printf("%d ms\n", end2 - begin2);
//
//	return 0;
//}

void func(int n)
{
	int x = 0;
	for (int i = 1; i < n; i *= 2)
	{
		++x;
	}
	printf("%d\n", x);
}


//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//
//	// 区间查找
//	// [begin, end]  -> 保持左闭右闭区间
//	int begin = 0;
//	int end = n - 1;
//	// begin   mid   end
//	while (begin <= end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}

int BinarySearch(int* a, int n, int x)
{
	//assert(a);

	// 区间查找
	// [begin, end）  -> 保持左闭右开区间
	int begin = 0;
	int end = n;
	// begin  mid   end
	while (begin < end)
	{
		//int mid = begin + ((end - begin) >> 1);
		int mid = (begin+end)/2;
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}
	return -1;
}


// 计算阶乘递归Fac的时间复杂度？
//long long Fac(size_t N)
//{
//	if (0 == N)
//		return 1;
//
//	for (int i = 0; i < N; ++i)
//	{
//		//...
//	}
//
//	return Fac(N - 1) * N;
//}

long long Fac(size_t N)
{
	if (N == 0)
		return 1;
	return Fac(N - 1) * N;
}

// O(2^N) 只有理论意义，实践中太慢了，N==50就要算好久了
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//	return Fib(N - 1) + Fib(N - 2);
//}

// 1  1  2  3  5  8....
// 时间复杂度：O(N)
unsigned long long Fib(size_t N)
{
	unsigned long long f1 = 1;
	unsigned long long f2 = 1;
	unsigned long long f3 = 0;
	for (size_t i = 3; i <= N; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	return f3;
}

// 大数运算

// 2^30
// 1024*1024*1024

int main()
{
	/*func(8);
	func(1024);
	func(1024*1024);*/

	printf("%ulld\n", Fib(10000));

	/*int  a[] = {0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", BinarySearch(a, 10, i));
	}*/

	return 0;
}