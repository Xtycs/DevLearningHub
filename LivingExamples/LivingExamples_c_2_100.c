/*//todo 题目：企业发放的奖金根据利润提成。
利润(I)低于或等于10万元时，奖金可提10%；
利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
20万到40万之间时，高于20万元的部分，可提成5%；
40万到60万之间时高于40万元的部分，可提成3%；
60万到100万之间时，高于60万元的部分，可提成1.5%；
高于100万元时，超过100万元的部分按1%提成。
从键盘输入当月利润I，求应发放奖金总数？

//todo 程序分析：请利用数轴来分界，定位。注意定义时需把奖金定义成双精度浮点(double)型。*/
#include <stdio.h>

double reward(double p){
    //double p,r;//!p在这里不能重复声明,p已经在函数输入值那里声明了
    double r;
    if(p<=100000){
        r = 0.1 * p;
    }
    else if(p>100000 && p<=200000){
        r = 0.1 * (100000) + 0.75 * (p - 100000);
    }
    else if(p>200000 && p<=400000){
        r = 0.1 * (100000) + 0.75 * (100000) + 0.05 * (p - 200000);
    }
    else if(p>400000 && p<=600000){
        r = 0.1 * (100000) + 0.75 * (100000) + 0.05 * (200000) + 0.03 * (p - 400000);
    }
    else if(p>6000000 && p<=1000000){
        r = 0.1 * (100000) + 0.75 * (100000) + 0.05 * (200000) + 0.03 * (400000) + 0.015 * (p - 600000);
    }
    else if(p>=1000000){
        r = 0.1 * (100000) + 0.75 * (100000) + 0.05 * (200000) + 0.03 * (400000) + 0.015 * (600000) + 0.01 * (p - 1000000);
    }
    return r;
}

int main(){
    double p,r;
    printf("Please inout your profit\n");
    scanf("%lf", &p);
    r = reward(p);
    printf("Your reward is %lf\n", r);
    return 0;
}

/*In C, you can redeclare a variable within a nested scope because the inner declaration creates a new 
variable that "shadows" the outer variable. This is valid and does not affect the outer variable. 
However, it's important to note that the inner variable is a separate entity from the outer one, and 
changes made to the inner variable do not affect the outer variable.*/

//todo This is the standard answer.
/*#include<stdio.h>
int main()
{
    double i;
    double bonus1,bonus2,bonus4,bonus6,bonus10,bonus;
    printf("你的净利润是：\n");
    scanf("%lf",&i);
    bonus1=100000*0.1;
    bonus2=bonus1+100000*0.075;
    bonus4=bonus2+200000*0.05;
    bonus6=bonus4+200000*0.03;
    bonus10=bonus6+400000*0.015;
    if(i<=100000) {
        bonus=i*0.1;
    } else if(i<=200000) {
        bonus=bonus1+(i-100000)*0.075;
    } else if(i<=400000) {
        bonus=bonus2+(i-200000)*0.05;
    } else if(i<=600000) {
        bonus=bonus4+(i-400000)*0.03;
    } else if(i<=1000000) {
        bonus=bonus6+(i-600000)*0.015;
    } else if(i>1000000) {
        bonus=bonus10+(i-1000000)*0.01;
    }
    printf("提成为：bonus=%lf",bonus);
 
    printf("\n");
}*/
