//*Febnacci number
//*recursion method
// #include <stdio.h>
// int Feb(int a);

// int main()
// {
//     int n = 0;
//     int output;

//     printf("which Febnacci number you want to get:");
//     scanf("%d", &n);

//     output = Feb(n);
//     printf("%d", output);

//     return 0;
// }

// int Feb(int a)
// {
//     if (a == 1 || a == 2)
//     {
//         return 1;
//     }
//     else
//     {
//         return Feb(a - 1) + Feb(a - 2);
//     }
// }

//*non-recursion method
// int main()
// {
//     int m, result;
//     printf("which Febnacci number you want to get:");
//     scanf("%d", &m);
//     int arr[m];

//     for (int i = 0; i < m; i++)
//     {
//         if (i == 0 || i == 1)
//         {
//             arr[i] = 1;
//         }
//         else
//         {
//             arr[i] = arr[i - 1] + arr[i - 2];
//         }
//     }
//     printf("It is %d", arr[m-1]);//the subscript of array need to minus(subtract) 1
//     return 0;
// }

//? another
// #include<stdio.h>
// int main()
// {
// 	long long n,a=1,b=1,s=0,i;
// 	scanf("%lld",&n);
// 	if(n<3)
// 	printf("1");
// 	else
// 	{
// 		for(i=3;i<=n;i++)
// 		{
// 			s=a+b;
// 			a=b;
// 			b=s;
// 		}
// 		printf("%lld",s);
// 	}
// }

//* calculate the k squared og n(recursion)
// #include <stdio.h>
// int Sq(int k,int n);

// int main()
// {
//     int k, n;
//     int output;
//     printf("Please input the number n and it's squared k\n");
//     scanf("%d %d", &k, &n);

//     output = Sq(k, n);
//     printf("it is %d", output);
// }

// int Sq(int k, int n)
// {
//     if(n==1)
//     {
//         return k;
//     }
//     else
//     {
//         return k * Sq(k, n - 1);
//     }
// }

//* Calculate the sum of each digit of a number (recursive implementation)
// #include <stdio.h>
// int Print(int n);

// int main()
// {
//     int a;
//     printf("input the number:");
//     scanf("%d", &a);

    
//     int sum = Print(a);
//     printf("\n%d", sum);
//     return 0;
// }

// int Print(int n)
// {
//     static int sum = 0;//! must use static, or the variable sum will be initialized to zero every times
//     if (n > 9)
//     {
//         Print(n / 10);
//     }
    
//     printf("%d ", n % 10);//! do not use else, we need these statements to be carry out whether n>9 or not
//     sum += n % 10;
//     return sum;
// }

//* Recursion and non-recursion implement the factorial of n respectively
// #include <stdio.h>
// int Fac(int n);

// int main()
// {
//     int a;
//     printf("Please input the number a:");
//     scanf("%d", &a);

//     int fac = Fac(a);
//     printf("it is %d", fac);
//     return 0;
// }

// int Fac(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return n * Fac(n - 1);
//     }
// }
