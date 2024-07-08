//! p20常见关键字1
//*auto是自动的，每个局部变量都是auto修饰的
//*extern申明外部符号
//*register寄存器关键字  计算机存储数据位置：内存(2T)，硬盘(500G)，网盘(几个G)，高速缓存(几十MB），寄存器(更小)
//*signed 有符号的
//*unsigned 无符号的
//*static 静态的
//*union 联合体(共用的)
//*void 无(空)    volatile 体现段位的关键词，暂时不讲

//*define和include是预处理指令

/*int main(){
    {
        auto int a = 10;//?自动创建自动销毁的,auto省略了
    }
    return 0;
}*/

/*int main(){
    register int num = 100;//?建议num的值存放在寄存器中,提升效率
    return 0;
}


//!初识常见关键字2
//*typedef 类型重定义
typedef unsigned int u_int;
int main(){
    unsigned int num = 100;
    u_int num2 = 100;
    return 0;
}*/

//*static 静态的
//* 1.修饰局部变量  2.修饰全局变量 3.修饰函数
#include <stdio.h>
/*void test(){
    //?int a = 1;
    static int a = 1;//?static修饰局部变量，改变其生命周期（本质上改变变量存储类型），但作用域仍然是局部的
    a++;
    printf("%d", a);
}
int main(){
    int i = 0;
    while(i<10){
        test();
        i++;
    }
    return 0;
}*/
//?栈区：局部变量，函数参数
//?堆区：动态内存分配的
//?静态区：全局变量，static修饰的静态变量

//* 2.修饰全局变量
int g_val = 2022;//?这是在另一个文件内声明的全局变量,可以用extern声明
static g_val = 2022;//?使得这个全局变量只能在自己所在源文件(.c)使用


extern int g_val;//?extern声明外部符号
int main(){
    printf("%d\n", g_val);
    return 0;
}

