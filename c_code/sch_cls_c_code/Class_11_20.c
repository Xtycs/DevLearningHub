//遇到main函数前不会开始函数，只是记录前面的东西（不产生实际运算，debug放这里没用）
//用到前面函数，形式化参数时开辟新内存，并把main中已经定义并开辟内存的东西copy一份，在计算完后这部分内存被清除
//! 期中考试题目用函数写
//*函数名不能用关键词
/*#include <stdio.h>
float cal_Atm_sum(int n,float a,float diff){

}*/

//*数组三者缺一不可
#include <stdio.h>
int main(){
    char STR[] = "abc";
    char STR2[4] = {'a', 'b', 'c'};//开辟空间为4，只有三个数，自动补最后一个
    char STR3[] = {'a', 'b', 'c'};
    printf("%s\n", STR);
    printf("%s\n", STR2);
    printf("%s\n", STR3);
    return 0;
}


//* pointers 指针
//指针的取值就是地址

