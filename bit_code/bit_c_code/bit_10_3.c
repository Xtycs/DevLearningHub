//算数操作符+-*/%
//移位操作符>> <<

#include <stdio.h>

/*int main()
{
//float a = 9 / 2;
//float a = 9 / 2.0;
int a = 9 % 2;       //%取模
printf("%d\n",a);
return 0;

}*/


//左移操作符移动的是二进制位
//a的值是2，a是整型4个字节32bit，2存进去就是00000000000000000000000000000010
//二进制位向左移动一位，最后补一个0，变成00000000000000000000000000000100，也就是4
/*int main(){
    int a = 2;
    int b = a << 1;
    printf("%d\n",b);
    return 0;

}

//位操作符：&按位与  |按位或  ^按位异或
int main(){
    int a = 2;
    a = a + 5;
    a += 5;                 //复合赋值，和上一行一样
    
    a = a - 3;
    a -= 3;

    a = a % 3;
    a %= 3;
    
    
    printf("%d\n",b);
    return 0;

}*/

//a+b  +有两个操作数，双目操作符
//单目操作符只有一个操作数
/*int main(){
    //0表示假，非0就是真
    int a = 10;
    printf("%d\n",!a);//真假转换

    if (a)
    {
        //如果a为真，做事
        
    }
    if (!a)
    {
        //如果a为假，!a变为真，那么做事
    }
    return 0;

}*/

int main()
{
    //sizeof是操作符,后面的括号可以省略，不是函数
    int a = 10;
    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(a));

    return 0;
}

/*int main()
{
    //10*4=40
    int arr[10] = {0};
    printf("%d\n",sizeof(arr));//计算的是数组的总大小，单位是字节
    printf("%d\n",sizeof(arr[0]));

//计算数组元素个数
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n",sz);
    system("pause");
    return 0;
}*/