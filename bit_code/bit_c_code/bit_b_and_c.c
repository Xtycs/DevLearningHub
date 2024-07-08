#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// int main()
// {
//     srand((unsigned)time(NULL));

//     int num = 1 + rand() % 100;
//     int guess;
//     for (int i = 1; i <= 3;i++){
//         printf("Please guess the number(you have three times):");
//         scanf("%d", &guess);
//         if (guess == num){
//             printf("Right\n");
//         }
//         else{
//             printf("False\n");
//         }
//     }
//     printf("num =%d", num);
//     system("pause");
//     return 0;
// }

//*multiply chat
// int main()
// {
//     for (int i = 1; i <= 9;i++)
//     {
//         for (int j = 1; j <= i;j++)
//         {
//             printf("%2d*%d=%2d", i, j, i * j);
//         }
//         printf("\n");
//     }
//     return 0;
// }


//*find the grreatest common divisor and the least multiple
// int main()
// {
//     int a1, a2, b1, b2;
//     int t;
//     printf("Please input two numbers:\n");
//     scanf("%d %d", &a1, &a2);
//     b1 = a1;
//     b2 = a2;
//     while (t = a1 % a2, t != 0)
//     {
//         a1 = a2;
//         a2 = t;
//     }
//     printf("The greatest common divisor is %d\n", a2);
//     printf("The least common multiple is %d", b1 / a2 * b2);
//     system("pause");
//     return 0;
// }

//*print the prime number form 100 to 200
// int main()
// {
//     for (int i = 100; i <= 200;i++)
//     {
//         int flag = 0;
//         for (int j = 2; j < i;j++)
//         {
//             if (i % j == 0)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0)
//         {
//             printf("%d\n", i);
//         }
//     }
//     system("pause");
//     return 0;
// }

#define DEBUG
#include <assert.h>
int main()
{
    int *a = NULL;
    assert(a != NULL);//if a not point to NULL,nothing happend, but if not, program will pause and give the infor about the error line
    
}