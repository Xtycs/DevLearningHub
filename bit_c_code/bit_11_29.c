//! 分支和循环（2）

//*goto语句使用  会打乱函数顺序尽量不用，但是可以快速跳出多层循环
#include <stdio.h>

/*int main(){
    zhangsan:
        printf("hehe");
        goto zhangsan;
        return 0;
}*/

//*随机数
/*void menu(){
    printf("**************");
    printf("*** 1.play ***");
    printf("*** 2.exit ***");
    printf("**************");
}
void game(){
    int guess;
}

int main(){
    do{
        menu();
        printf("Please choose;>");
        scanf("%d", &input);
        switch(input){
            case
        }
    }
}*/



//*数组
//?求数组元素个数
/*int main(){
    int arr[10] = {0};
    printf("%d\n", sizeof(arr));
    printf("%d\n", sizeof(arr[0]));
    printf("%d\n", sizeof(arr) / sizeof(arr[0]));
    return 0;
}*/

//?求数组元素的地址
int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    int sz = sizeof(arr) / sizeof(arr[0]);//todo The number of arr[10]
    for (int i = 0; i < sz;i++){
        printf("&arr[%d]=%p\n", i, &arr[i]); //todo %p打印十六进制
        
    }
    return 0;
}
// todo a  b   c  d
// todo 11 12 13 14
/*
&arr[0]=000000000061FDF0
&arr[1]=000000000061FDF4
&arr[2]=000000000061FDF8
&arr[3]=000000000061FDFC
&arr[4]=000000000061FE00
&arr[5]=000000000061FE04
&arr[6]=000000000061FE08
&arr[7]=000000000061FE0C
&arr[8]=000000000061FE10
&arr[9]=000000000061FE14
*/