//!  |前面函数的结果输入到后面
//* 1.Debugging using VScode
//? two aspects of bugs :1.Typos and grammar  2.logical ralated bugs

#include <stdio.h>
/*#define PI 3.14159
int main(){
    float radius = 2;
    float area;
    area = PI * radius * radius;
    printf("The area is %f", area);
    return 0;
}*/
#include <stdlib.h>
int main(){
    int guess = 1;
    char ch;
    printf("Pick an integer from 1 to 100. I will guss the number");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong");
    printf("\nUh...is your number %d\n",guess);
    while((ch=getchar()) !='y')//?  n+回车  回车键也会加入判断，不是y所以会再输出一行
        printf("Well , then, it is %d\n", ++guess);
    printf("I know I will do it");
    system("pause");
    return 0;
}


//*function
//?self-contain unit of program code, making a program modular
//?core component:1.the type of return(only one)
//?               2.the name of the function
//?               3.the type of the argument(could be more than one)
//主函数main,写函数总分总

#include <stdio.h>
#define PI=3.14
int main(){
    int selection;
    printf("Welcome to use out counter, please select what you want to calculate");
    printf("1. canculate the area of the circle\n");
    printf("2. calculate the minimal value\n");
    printf("3. calculate the absolute value\n");
    printf("4. calculate the perimeter");
    scanf("%d", &selection);
    if(selection==1){
        float area;
        float radium;
        printf("Please input a radium\n");
        sacnf("%f", &radium);
        area = cal_area(radium);
    }
    if(selection==2){
        float minimal_value;
        float value1,value2;
        printf("Please input two values\n");
        scanf("%f %f", &value1, value2);
        minimal_value = min_value(value1, value2);
        //?加点交互性的printf
    }
    if(selection==3){
        float absolute_value;
        float value;
        printf("Please input a value\n");
        scanf("%f", &value);
        absolute_value = abs_value(value);
        printf("The absolute value is %f", absolute_value);
    }
    return 0;
}
