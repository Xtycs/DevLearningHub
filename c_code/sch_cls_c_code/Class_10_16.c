#include <stdio.h>
/*int main(){
    int x = 0;
    int y = 0;
    printf("Please input an integer x\n");
    scanf("%d",&x);
    printf("Please input an integer y\n");
    scanf("%d",&y);
    if(x > y){
        printf("x is greater than y");
        //printf("the maximal value is %d",x);
    }
    else{
        printf("y is greater than x");
        //printf("the maximal value is %d",y);
    }
    return 0;
}*/

/*int main(){
    int x;
    printf("Please input your score\n");
    scanf("%d",&x);
    //if(93<x<=100)             //计算机先计算93<x,返回值为0错误，0<=100成立
    if(93<x && x<=100){
        printf("your grade is A+");
    }
    else if(89<x && x<=93){
        printf("your grade is A");
    }
}*/

/*int main(){
    int number = 0;
    while(number<10){
        number = number + 1;
        printf("number = %d\n",number);
        
    }
    return 0;
}*/

//break退出机制和continue使用
int main(){
    int number = 0;
    int a,b,c;
    while(number<20){
        number++;
        if(number<18){
            continue;
        }
    printf("number = %d\n",number);
    }
    return 0;
}