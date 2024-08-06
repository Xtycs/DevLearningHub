#include <stdio.h>
#include <time.h>


int main()
{
    int begin1 = clock();//计算的是从程序开始到这里的时间,以毫秒为单位

    int n = 100000000;
    int x = 10;
    for (int i = 0; i < n; ++i)
    {
        ++x;
    }
    int end1 = clock();
    printf("%d ms\n", end1 - begin1);

    return 0;
}

void bubble_sort(int* a, int n)
{
    for (int end = n - 1; end > 0; --end)
    {
        int exchange = 0;
        for (int i = 0; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                exchange = 1;
            }
        }
        if (exchange == 0)
        {
            break;
        }
    }
}

void sort(int* a, int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)//different iteration statement, but have same result
        {
            if(a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

//两道题leetcode：轮转数组189，消失的数字

//轮转数组：
//思路一：暴力解法，每次将数组向右移动一位，重复k次
int tmp = nums[numsSize - 1];
for (inbt i = numsSize - 1; i >= 0; i++)
{
    nums[i + 1] = nums[i];
}
nums[0] = tmp;

//思路二：三段逆置
//1.前n-k个元素逆置（也就是下标0,n-k-1）  2.后k个元素逆置  3.整个数组逆置
//1.整个数组逆置  2.前k个元素逆置  3.后n-k个元素逆置


