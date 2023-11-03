//!11月13日，一个小时到一个半小时，4道题目编程，范围到今天截止
//*判断，正中间的旁边有几个*，循环加判断，行列循环
//输入输出流二进制流,没按enter之前在数据流里缓存(buffer)未进入program，enter之后缓存清除进入项目中
//if you mistype ,youcan fix your mistake before the buffer is flushed
//buffer is flushed when it is full,the buffer size depend on the system 


/*#include <stdio.h>
int main(void){
    char ch;
    printf("Please input some words!\n");
    while ((ch=getchar()) !='#'){//?不等于#才会打印
        putchar(ch);
    }
    printf("The next charater is:\n");
    ch = getchar();
    putchar(ch);
    printf("\n");
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
/*int main(void){
    char ch;
    int total_number;
    printf("Please input some words!\n");
    while ((ch=getchar()) !=EOF){//?输入EOF后跳出
        total_number++;
    }
    printf("%d", total_number);
    system("pause");
    return 0;
}*/


int main(){
    char ch;
    printf("Please input some words!\n");
    while((ch=getchar()) !=EOF)
        ch = ch + 1;
        putchar(ch);
    return 0;
}

//直接在搜索栏搜索cmd，自动改变当前地址，打开文件里面会自带一个eof，不需要按control z(键盘上的EOF)
//<后面的所有东西相当于输入到屏幕中了，进入程序，程序给出输出
//两个缓存区，cmd里没按enter前，输入进去program但是没有程序没有结束，没有进入输出流
//屏幕直接连内存没有buffer 文件通常连接buffer

//重定向把键盘或屏幕换成文件或程序
//>>双箭头可以保留原先的内容
//上方向键可以查找cmd历史记录
