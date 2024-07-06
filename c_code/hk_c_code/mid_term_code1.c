#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, a1, d,i,j,x;
    double s1,s2;
    printf("Student ID: 1230019461\n");
    printf("Please input an integer\n");
    scanf("%d", &n);
    printf("Please input the  first term of the Arithmetic series\n");
    scanf("%d", &a1);
    printf("Please input a common difference\n");
    scanf("%d", &d);
//fomula
    s1 = (n * a1) + (n * d * (n - 1))/2;

//no fomula
    s2 = a1;
    for (i = 1,x=1; i < n; i++,x++){
        double s = 0;
        s = a1 + x*d;
        s2 = s2 + s;
        
    }
        printf("(Use formula) The summition of the fist %d terms of the Arithmetic series (ratio=1.000000) is %f\n", n, s1);
        printf("(No formula) The summition of the fist %d terms of the Arithmetic series (ratio=1.000000) is %f", n, s2);
        system("pause");
        return 0;
}

