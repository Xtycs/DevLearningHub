//p13观看github教程
//转义字符改变了字符原本的意思
#include <stdio.h>
#include <string.h>
/*int main(){
    //printf("(are you ok??)");   //三字母词
    //(are you ok]
    //printf("%s\n","\"");        //单引号同理

    printf("%d\n",100);
    printf("%c",'a');
    printf("%s\n","abc");
    printf("\a");
    return 0;
}*/

/*int main(){
    printf("%c\n",'\130');             //注意\ddd ddd表示1-3个八进制数字 130换为十进制是88，X的ASCII码值是88
    printf("%c %d\n",'\101','\101');   //将八进制101换为十进制65
    
    printf("%c\n",'\x30');             // \xdd dd表示2个十六进制数字,这里先把33换为十进制48，打印出字符0
    return 0;
}*/

//练习题
/*int main()
{
    printf("%d\n", strlen("c:\test\328\test.c"));   //数出来14个 8不能算八进制数
    return 0;

}*/


//选择语句
/*int main(){
    int input = 0;//输入
    printf("加入澳科大:>");
    printf("要好好学习么(1/0)?>:");
    scanf("%d",&input);
    if (input == 1);
       printf("好offer\n");
    if (input == 0);
       printf("卖红薯\n");
    return 0;
}*/

//敲三万行代码 while循环
/*int main(){
    int line = 0;
    while(line<30000)
    {
        printf("write cods:%d\n",line);
        line++;

    }
    if (line == 30000)
    {
        printf("good offer\n");
    }
    return 0;
}*/

//使用函数
/*nt Add(int x, int y)
{
    int z = 0;
    z = x + y;
    return z;
}

int main()
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d%d",&num1,&num2);
    //int sum = num1 + num2;

    //函数方法解决
    int sum = Add(num1,num2);
    printf("%d\n",sum);
    return 0;

}*/

int main()
{
    //数组是一组相同类型元素的集合
    //10个整形1-10存起来
    //数组是用下标来访问的
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};   //下标0，1，2....   arr[0]指的是1以此类推
    int i = 0;
    while (i<10)
    {
        printf("%d",arr[i]);
        i++;
    }
    //char ch[5]  = {'a','b','c'};  //不完全初始化，剩余的默认为0

    return 0;
}