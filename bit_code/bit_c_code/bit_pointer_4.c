//* pointer minus pointer :两个地址在内存中间隔多少个指针类型的字节倍数 ,效果相当于strlen函数
// #include <stdio.h>
// size_t my_strlen(const char* s)
// {
//     char *p = s;
//     assert(s != NULL);
//     while (*p != '\0')
//     {
//         p++;
//     }
//     return p - s;
// }

// int main()
// {
//     printf("%d\n", my_strlen("abc"));
//     return 0;
// }

//* The use of function assert() which is in assert.h head file
//* 如果assert后的表达式为真（非0）则继续运行，假则会报错并显示具体文件和行数
#include <assert.h>
#include <stdio.h>
// int main()
// {
//     int *p = NULL;
//     assert(p != NULL);
//     return 0;
// }

//* When you no longer need assert, #define NDEBUG      is ok.
//*                                 #include <assert.h>


//todo array pointer(数组的指针)
// int main()
// {
//     int arr[10] = {0,1,2,3,4,5,6,7,8,9};
//     &arr; //&name of pointer

//     int *p1 = arr;
//     int (*p2)[10] = &arr; //[]的优先级更高，所以用()保证*与p先结合,记住把变量名字去掉后就是其类型

//     printf("%p\n", p2);
//     printf("%p\n", *p2);
//     printf("%p\n", p2 + 1); //加一后差了40个byte
// }

//*The nature of passing parameter by two-dimention array
//形参是二维数组，实参也是二维数组
// void print(int arr[3][5], int r, int c)
// {
//     for (int i = 0; i < r;i++)
//     {
//         for (int j = 0; j < c;j++)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
//     print(arr, 3, 5);

//     return 0;
// }

//二维数组的数组名是数组首元素（第一行所有算第一个元素）的地址，二维数组数组名天然就是一个数组指针
//首元素的地址是第一行的地址,不是第一行第一个的地址(待议)
//而第一行的地址就是一维数组的地址
// void print(int (*arr)[5], int r, int c)
// {
//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             printf("%d ", *(*(arr + i) + j)); // 相当于 arr[i],二维数组的arr[i]指的就是第i行的一维数组的数组名
//             // 给数组指针取值后变为了这个数组的数组名，也就是本数组首元素的地址
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
//     print(arr, 3, 5);

//     return 0;
// }

int main()
{
    char arr[] = {"abcde"};
    char *pt = arr;
    for(int i=0;i<=4;i++)
    {
        //printf("%c", pt[i]);
        printf("%c", *(pt + i));
    }
    return 0;
}