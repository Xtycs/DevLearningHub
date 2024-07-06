//* strlen char*: const char* and restrict char*
#include <stdio.h>
#include <string.h>
/*int main(){
    int x;
    char str1[10] = "abcdef";
    x = strlen() 
    return 0;
}*/

/*int main(){
    char str[10];
    int max = 7;
    //?gets(str);
    fgets(str, max,stdin);//?保留/n,因为可以从文档中识别输入，空格是很重要的组成不会转化为/0
    int x = strlen(str);//?strlen不识别/0但是会识别/n
    int puts(x);
    return 0;
}*/

/*int main(){
    char str2[5] = "abcd";
    for (int a = 0; a <= 5;a++){
        printf("input the code\n");
        char str1[5];
        //gets(str1);
        fgets(str1, 4, stdin);
        if (strcmp(str1, str2) == 0)
        {
            printf("Correct!\n");
            goto finish;
        }
        else{
            printf("try again\n");
        }
    }
    finish:
    return 0;
}*/



//代码敲初始化结构体，键盘输入怎么初始化结构体
//!12.9补课内容
//*注意从大到小定义结构体或联合体，最大程度分配内存
//*union内部不区分各成员的内存，在赋给一个成员数据之后，之前成员的数据丢失
//*今天ppt10-20分考试内容，结构体，联合体，enum
struct book{
    char name[100];
    int pages;
    char author[50];
    float price;
};

typedef struct book BK;

/*int main(){
    BK math = {.name = "best math book ever",
               .pages = 120,
               .author = "Felix",
               .price = 100};
    printf("The price of the book %s is %f", math.name, math.price);
    return 0;
}*/

int main(){
    BK library[100];
    printf("Welcome to use the library system.\n");
    printf("Please input the basic information of the book.\n");
    printf("Please input the name of the book.\n");
    gets(library[0].name);
    printf("Please input the pages of the book.\n");
    gets(library[0].pages);
    printf("Please input the author of the book.\n");
    gets(library[0].author);
    printf("Please input the price of the book.\n");
    //? gets(library[0].price);
    scanf("%f", &library[0].price);
    printf("the name is %c\n", library[0].name);
    printf("the pages is %d\n", library[0].pages);
    printf("the author is %c\n", library[0].author);
    printf("the price is %f\n", library[0].price);
    return 0;
}

//*1. storage management
//malloc()  free()
int main(){
    int *x;
    x = (int *)malloc(3 * sizeof(int));
    free(x);
}

//*2. linked list(单双链表会考)
typedef struct node node;
struct node{
    int age;
    float weight;
    char name[100];
    struct node *next;
};
int main(){
    node N1;
    node N2;
    N1.next = &N2;
}


