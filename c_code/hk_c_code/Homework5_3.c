#include <stdio.h>
#include <stdlib.h>
int Factorial(int i){
    int f = 1;
    if(i==0){
        f = 1;
    }
    else if(i<0){
        printf("invalied input\n");
    }
    else{
        for (int j = 0; j < i;j++){
            f = f * (i - j);
        }
    }
    return f;
}

int main(){
    int i,f;
    printf("TingyangXie 1230019461\n");
    printf("Please input an non-negative integer:");
    scanf("%d", &i);
    f = Factorial(i);
    printf("Factorial of %d: %d\n", i, f);
    system("pause");
    return 0;
}

//* use the function with no return valule(use pointer)
/*#include <stdio.h>
void Factorial(int i, int* f) {
    *f = 1;
    if (i == 0) {
        *f = 1;
    } else if (i < 0) {
        printf("Invalid input\n");
        *f = -1;  // Modify the value pointed to by f for invalid input
    } else {
        for (int j = 0; j < i; j++) {
            *f = *f * (i - j);
        }
    }
}

int main() {
    int i, f;
    printf("Please input a non-negative integer: ");
    scanf("%d", &i);
    Factorial(i, &f);  // Pass the address of f to modify its value
    printf("Factorial of %d: %d\n", i, f);
    return 0;
}*/