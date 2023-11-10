#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    int N;
    int S = 0;
    int n = 0;
    printf("Please input an integer.\n");
    scanf("%d", &N);
    for (n = 0; n < N; n++)
    {
        if(n%2==0){
            continue;
        }
        else
        {
            S = S + n;
        }
    }
    printf("The summation of odd numbers less than %d is %d\n", N, S);
    system("pause");
    return 0;
}

