#include <stdio.h>
#include <stdlib.h>
int main(){
    int m, n;
    printf("Please input an integer about the crown\n");
    scanf("%d", &n);
    printf("Please input another integer about the trunk\n");
    scanf("%d", &m);
    printf("Merry Christmas!\n");
    for (int i = 1; i <= n;i++){
        for (int space = 0; space < (n + 2) - i;space++){
            printf(" ");
        }
        for (int star = 0; star < 2 * i - 1;star++){
            printf("*");
        }
        printf("\n");
    }
    for (int column = 1; column <= m;column++){
        for (int space2 = 1; space2 <= n + 1; space2++)
        {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    system("pause");
    return 0;
}