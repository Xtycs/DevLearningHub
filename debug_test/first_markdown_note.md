First Header | Second Header
------------ | -------------
Content from cell 1 | Content from cell 2
Content in the first column | Content in the second column

"Print to line number code": {
            "prefix": "code",
            "body": [
            "```cpp {.line-numbers}",
            "$2",
            "```" ],
            "description": "得到一个带语法高亮和行号的代码块模板"
        }

### date: 7 / 7 / 2024
### 7.2 链式访问-Chained access
***将一个函数的返回值作为另一个函数的参数***
```
int main()
{
    printf("%d\n, strlen("abcd));
    return 0;
}
```
***Demo:***
```
#include <stdio.h>
int main()
{
    printf("%d\n", printf("%d", printf("%d", 43)));
}
```
***printf()函数返回值是打印字符的个数,这里的43打印了两个字符，空格也算一个字符，output：4321***

***高内聚低耦合-软件工程中的名词：设计模块时尽量独立，不要过多依靠其他函数***

### 8.3. Static and extern
***原本局部变量存储在栈区，static修饰存储到静态区，生命周期与全局变量一致（注意两者之间依然有差别，见下面的解释）***
```
void test()
{
    int i = 0;//每次进入函数都会重置为0
    static int i = 0;
    i++;
    printf("%d\n", i);
}

int main()
{
    int i = 0;
    for (int i = 0; i < 5; i++)
        test();
    return 0;
}
```
***extern用来声明外部符号***
```
int g_val = 10;
```
```
extern int g_val;
int main()
{
    printf("%d\n", g_val);
    return 0;
}
```
***But:***
```
static int g_val = 10;
```
```
extern int g_val;
int main()
{
    printf("%d\n", g_val);
    return 0;
}
```
***Conlusion: static int g_val只能在本源文件中使用，不能在其他源文件中使用***
***Reason: 全局变量默认具有外部链接属性，但是static修饰后变为内部链接属性，即使extern也无法正常使用***
```
static int Add(int a, int b)
{
    return a + b;
}
```
```
extern int Add(int a, int b);
int main()
{
    printf("%d\n", Add(1, 2));
    return 0;
}
```
***如果有一个函数只想在本源文件只用，禁止外部访问，可以添加static修饰***
