// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     for (int i = 1; i <= 100; i++)
//     {
//         if (i%3 == 0)
//         {
//             printf("%d ", i);
//         }
//     }
//     system("pause");
//     return 0;
// }

//* modify three numbers in the order of big->small
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int arr[3];
//     int change;
//     printf("Please input three numbers\n");
//     scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
//     for (int i = 0; i < 2; i++)
//     {
//         if (arr[i] < arr[i + 1])
//         {
//             change = arr[i];
//             arr[i] = arr[i + 1];
//             arr[i + 1] = change;
//         }
//     }
//     for (int i = 0; i < 2; i++)
//     {
//         if (arr[i] < arr[i + 1])
//         {
//             change = arr[i];
//             arr[i] = arr[i + 1];
//             arr[i + 1] = change;
//         }
//     }
//     printf("%d %d %d", arr[0], arr[1], arr[2]);
//     system("pause");
//     return 0;
// }


//* Calculate 1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100
//*not smart method(use fmod function to calculate the remainder of the devision of floating point)
// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     float num = 1.0;
//     float sum = 0.0;
//     for (float i = 1.0; i <= 100;i++)
//     {
//         num = num / i;
//         if (fmod(i, 2) != 0)
//         {
//             sum = sum + num;
//         }
//         else
//         {
//             sum = sum - num;
//         }
//     }
//     printf("%f", sum);
//     return 0;
// }

//*better method
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     float num = 1.0;
//     float sum = 0.0;
//     for (float i = 1.0; i <= 100;i++)
//     {
//         num = num / i;
//         sum += num;
//         num = -num;
//     }
//     printf("%f", sum);
//     system("pause");
//     return 0;
// }


//*Count how many digits 9 appear in all integers from 1 to 100
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int count = 0;
//     for (int i = 1; i <= 100;i++)
//     {
//         if (i%10 == 9 && i/10 == 9)
//         {
//             count += 2;
//         }
//         else if (i%10 == 9 || i/10 == 9)
//         {
//             count++;
//         }
//     }
//     printf("%d", count);
//     system("pause");
//     return 0;
// }

//*print the leap year闰年
//*能被4整除，不能被100整除；或者能被400整除的是leap year
// #include<stdio.h>
// #include <stdlib.h>
// int main()
// {
// 	int y = 0;
// 	int count = 0;
// 	for (y = 1000; y <= 2000; y++)
// 	{
// 		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
// 		{
// 			printf("%d ", y);
// 			count++;
// 		}
// 	}
// 	printf("\ncount = %d\n", count);
//     system("pause");
//     return 0;
// }

//*find the biggest number in ten numbers
// #include <stdio.h>
// #include <stdlib.h>
// #include <windows.h>
// int main()
// {
//     int arr[10];
//     int change = 0;
//     printf("Please input ten integers:\n");

//     for (int i = 0; i <= 9;i++)
//     {
//         scanf("%d", &arr[i]);
//     }

//     for (int j = 1; j <= 10;j++)
//     {
//         for (int i = 0; i <= 8; i++)
//         {
//             if (arr[i] < arr[i + 1])
//             {
//                 change = arr[i];
//                 arr[i] = arr[i + 1];
//                 arr[i + 1] = change;
//             }
//         }
//     }
//     printf("%d", arr[0]);
//     system("pause");
//     return 0;
// }

#include <stdio.h>
int main()
{
    char a = 3;
    char b = 127;

    char c = a + b;
    
    printf("%d", c);
    return 0;
}