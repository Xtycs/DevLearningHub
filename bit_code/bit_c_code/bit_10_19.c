//! p24常量和宏
//*define是一个预处理指令
//*1.define定义符号
#include <stdio.h>
/*#define MAX 10000
int main(){
    printf("%d\n",MAX);
    return 0;
}*/

//*2.define定义宏
/*#define ADD(X,Y) X+Y  //?((x)+(y))注意宏的定义要准确，从而替换
int main(){
    printf("%d\n", 4*ADD(2, 3));
                //?4*2+3
    return 0;
}*/


//!p26指针
/*int main(){
    int a = 10;//?a在内存中分配到4个字节
    //?&a取得是第一个字节的地址
    printf("%p\n", &a);//?%p专门用来打印地址
    int * pa = &a;//?pa是用来存放地址的，在c语言中pa叫指针变量
                  //? *说明pa是指针变量，int说明pa执行的对象是int类型的

    char ch = 'w';
    char * pc = &ch;
    return 0;
}*/

//* 测试指针能不能存放自己的地址
/*int main(){
    int * pa = &pa;
    return 0;
}*/

//*指针就是地址
/*int main(){
    int a = 10;
    int *pa = &a;
    *pa = 20;//todo *是解引用操作符（单目操作符），*pa就是通过pa的地址，找到a，更改了a的值

    printf("%d\n", a);
    return 0;
}*/

//todo 指针大小相同，因为指针用来存放地址，因此指针需要多大空间取决于地址的存储需要多少
//todo 32位 32bit 4byte
//todo 64位 64bit 8byte
/*int main(){
    printf("%d\n", sizeof(char *));
    printf("%d\n", sizeof(short *));
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(long *));
    printf("%d\n", sizeof(long long *));
    printf("%d\n", sizeof(float *));
    printf("%d\n", sizeof(double *));
    return 0;
}*/



//! p26初识结构体(struct)
//*结构体可以让c语言创建新的类型出来

//*创建一个学生
struct Stu{
    char name[20];//todo 成员变量
    int age;
    double score;
};

int main(){
    struct Stu s = {"Felix", 20, 85.5};//?结构体的创建和初始化
    printf("1:%s %d %lf\n", s.name, s.age, s.score);//todo 结构体变量.成员变量

    struct Stu *ps = &s;
    printf("2:%s %d %lf\n", (*ps).name,(*ps).age,(*ps).score);

    printf("3:%s %d %lf\n", ps->name, ps->age, ps->score);
                    //todo  结构体指针->成员变量名
    return 0;
}

