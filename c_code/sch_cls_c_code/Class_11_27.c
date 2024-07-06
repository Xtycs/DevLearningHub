//数据类型决定从同样的二进制数中取出的类型，且决定从指针地址往后数的内存数，内存中一个小空间是1byte
#include <stdio.h>
//* get the value of any adress
//整数型指针变量存储整数型地址
/*int main(){
    int x = 124123;
    char *ptr = (char *)&x;
    //? 把原本&x整数型地址转换为
}
//地址越小越在前面？地址之间 < > ==

int *p;
char *c;*/
//数据类型决定了地址后面多少空间被绑定在一起，但是指针只是第一个地址，sizeof之后大小是一样的，后面的一堆不存
//*求数组的和
/*int main(){
    float vector[4] = {1, 0, 2, 1, 3, 4, 5, 6};
    float sum;
    for (int i = 0; i < 4 ; i++){     //i=index
        sum += vector[i];
    }
    printf("The sum of the vector is %f", sum);
    return 0;
}*/
//*使用*&+求数组和(用地址)
/*int main(){
    float vector[4] = {1, 0, 2, 1, 3, 4, 5, 6};
    float sum;
    for (int i = 0; i < 4; i++){
        sum = sum + *(vector+i);      //?  vector[index]
        vector = vector + 1;
    }
    printf("The sum of the vector is %f", sum);
    return 0;
}*/

//*改变循环条件
int main(){
    float vector[4] = {1.0, 2.1, 3.4, 5.6};
    float sum;
    float *current;
    for (float current = vector; current <= vector + 3; current+=1){
        sum = sum + *current;
    }
    printf("The sum of the vector is %f", sum);
    return 0;
}


