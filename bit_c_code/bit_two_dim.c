//*Read 10 integers from user input and store them in an array. Then, calculate and output the average of these integers.
#include <stdio.h>
// int main()
// {
//     int arr[10];

//     for (int i = 0; i < 10; i++)
//     {
//         printf("Please input ten integers:");
//         scanf("%d", &arr[i]);
//     }

//     int sum = 0;
//     for (int i = 0; i < 10; i++)
//     {
//         sum += arr[i];
//     }

//     printf("The average value is %d", sum / 10);
//     return 0;
// }


//*Swap the contents of array A with the contents of array B. (array size)
#include <stdlib.h>
int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    int swap;

    for (int i = 0; i < 5;i++)
    {
        swap = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = swap;
    }

//print two arrays
    for (int j = 0; j < 5;j++)
    {
        printf("%d ", arr1[j]);
    }
    printf("\n");
    for (int j = 0; j < 5;j++)
    {
        printf("%d ", arr2[j]);
    }
    system("pause");
    return 0;
}
