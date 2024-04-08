#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch;
    printf("Please input some words!\n");
    while((ch=getchar()) !=EOF)
        ch = ch - 1;
        putchar(ch);
    return 0;
}

