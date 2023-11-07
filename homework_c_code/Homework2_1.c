#include <stdio.h>//65
#include <stdlib.h>
int main(){
    printf("Data Type: |  char  |  int  |  long long  |  float  |  double  |\n");
    printf("-----------------------------------------------------------------\n");
    printf("Data Size: |   %d    |   %d   |      %d      |    %d    |    %d     |\n", sizeof(char), sizeof(int), sizeof(long long), sizeof(float), sizeof(double));
    system("pause");
    return 0;
}