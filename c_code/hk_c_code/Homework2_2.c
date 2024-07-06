#include <stdio.h>
#include <stdlib.h>
int main(){
    int a = 9;
    int b = 15;
    int c = 128;
    int d = 2048;
    int e = 9527;
    printf("-----------------------------------------------------------------\n");
    printf("Decimal Form:       |  %d  |  %d  |  %d  |  %d  |  %d  |\n", a, b, c, d, e);
    printf("-----------------------------------------------------------------\n");
    printf("Octal Form:         |  %o |  %o  |  %o  |  %o  |  %o |\n", a, b, c, d, e);
    printf("-----------------------------------------------------------------\n");
    printf("Hexadecimal Form:   |  %x  |  %x   |  %x   |  %x   |  %x  |\n", a, b, c, d, e);
    printf("-----------------------------------------------------------------\n");
    system("pause");
    return 0;
}