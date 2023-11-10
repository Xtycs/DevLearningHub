#include <stdio.h>
#include <stdlib.h>
int main(){
    double S,T;
    printf("Please enter your salary.\n");
    scanf("%lf", &S);
    if(S<=5000){
    }
    if(S>5000 & S<=8000){
        T = 0.03 * (S - 5000);   
    }
    if(S>8000 & S<=17000){
        T = 90 + 0.1 * (S - 8000);  
    }
    if(S>17000 & S<=30000){
        T = 990 + 0.2 * (S - 17000);
    }
    if(S>30000 & S<=40000){
        T = 3590 + 0.25 * (S - 30000);
    }
    if(S>40000 & S<=60000){
        T = 6090 + 0.3 * (S - 40000);
    }
    if(S>60000 & S<=85000){
        T = 12090 + 0.35 * (S - 60000);
    }
    if(S>85000){
        T = 20840 + 0.45 * (S - 85000);
    }
    printf("You have to pay tax %f\n", T);
    system("pause");
    return 0;
}