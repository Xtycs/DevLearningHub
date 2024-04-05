//!靠填空题和简答题，求计算结果等
//* 写函数，作用是输入变量S，不需要返回值（void），输出S+1
#include <stdio.h>

//*我写的
/*int Cal(int x){
    x += 1;
    return x;
}

int main(){
    int x = 1;
    //? x = Cal(x);
    x = Cal(x);
    printf("%d", x);
    return 0;
}*/

//*老师写的
/*int update(int x2){
    int z = x2 + 1;
    return z;
}
int main(){
    int y;
    int x = 1;
    y = update(x);
    printf("the update of x is %d", y);
    return 0;
}*/

//?在内存里x=2，x+1=3，需要额外copy一个区域z=2，用z+1后把值传给x所在的内存
//?指针可以直接对于x的地址所存储的内容进行修改
//*用函数给未初始化的数组赋值（用键盘）
//? 数组不能接受全体赋值或者平移，只能用地址
/*int initial(int *S){
    for (int i = 0; i <= sizeof(S) / sizeof(int);i++){
        printf("Please input the number as the %dth element of S\n",i);
        int number;
        scanf("%d", &number);
        S[i] = number;
    }
    return 0;
}*/
void initial(int *S1,int len){
    for (int index = 0; index <= len;index++){
        int s;
        printf("Please input the number as the %dth element of S\n",index);
        scanf("%d", &s);
        *(S1 + index) = s;

    }
}

int main(){
    int S[5];
    initial(S,5);
    printf("%c", S);
    return 0;
}

//*scanf函数会从输入流中找到 % 指定的数据，并按照后面的地址赋给某个变量
//*后面地址的数据类型要与 % 抽出数据的类型一致
//? char name[81]
//? scanf("%s",name), 而不是scanf("%s",&name)，这个是把值赋给地址的地址
