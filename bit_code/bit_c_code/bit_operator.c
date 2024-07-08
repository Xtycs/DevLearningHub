//*In an integer array, only one number appears once, and all other arrays appear in pairs. 
//*Find the number that appears only once
// #include <stdio.h>
// int main()
// {
//     int arr[9] = {1, 2, 3, 4, 5, 1, 2, 3, 4};
//     int size = sizeof(arr) / sizeof(int);
//     //int j;   do not clarify j in the for loop, which will make variable j only work in loop for.(it is ok if printf(arr[i]))

//     for (int i = 0; i < size; )
//     {
//         int flag = 0;
//         for (int j = 0; j < size; j++)
//         {
//             if (arr[i] == arr[j] && i != j)
//             {
//                 flag = 1;
//                 i++;
//                 break;
//             }
//         }

//         if (flag == 0) //if didn't find the same value and break, flag will remain value 0.
//         {
//             printf("The number which appear once is %d", arr[i]);
//             i++;//with out this statement, this program will become an endless loop.
//         }
//     }
//     return 0;
// }

//*method of ^
// int find_single(int arr[], int sz)
// {
//     int ret = 0;
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         ret ^= arr[i];
//     }
//     return ret;
// }
// int main()
// {
//     int arr[] = { 1,2,3,4,5,1,2,3,4 };
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int single = find_single(arr, sz);
//     printf("%d\n", single);
 
 
//     return 0;
// }


//*operator >> and <<
//* <<移位规则：左边抛弃，右边补0 (左移有二倍的效果)
//* >>移位规则:1.逻辑位移：右边丢弃，左边补0 (逻辑右移和左移的规则一样都是补0完事)
//*           2.算数位移：右边丢弃，左边按照符号位补1或0 (一般有1/2倍的效果)
//! 特殊记忆：-1的补码是全1，算数位移后还是自己
#include <stdio.h>
// int main()
// {
//     int num = 10;
//     int n = num << 1;
//     printf("num=%d\n", num);
//     printf("n=%d", n);

//     return 0;
// }

// int main()
// {
//     int num = 10;
//     int n = num >> 1;
//     printf("num=%d\n", num);
//     printf("n=%d", n);

//     return 0;
// }


//* If my computer display Logical displacement it will be suitable for both positive and negative
//* But the thearithmetic displacement makes it put 符号位1或0 to replace the loosing digit
//! 这里的初始值i其实对应的是第1,3,5/2,4,6位移动到32位的左右端的距离，从而与1进行&操作
int main()
{
	int num = 9;
	//打印奇数位
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
    
	//打印偶数位
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
    return 0;
}
