/*#include <stdio.h>
int main(){
    int x;
    for (x = 0;;x++){
        if((x + 100)==(int)(sqrt(x + 100)) * (int)(sqrt(x + 100)) && (x +168) == (int)(sqrt(x + 168)) * (int)(sqrt(x + 168))){
            printf("The integer is %d", x);
            break;
        }
    }
    return 0;
}*/

/*#include <stdio.h>
int main(){
    int x;
    for (x = 0;;x++){
        if((x + 100) == sqrt(x + 100) * sqrt(x + 100) && (x +168) == sqrt(x + 168) * sqrt(x + 168)){
            printf("The integer is %d", x);
            break;
        }
    }
    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>

/*int main(){
    int i, j,row;
    printf("Please input an integer represent the rows of the tower\n");
    scanf("%d", &row);
    for (i = 0; i < row;i++){
        char z = 'Z';
        for (j = 0; j <= i;j++){
            printf("%c", z);
            z--;
        }
        printf("\n");
    }
    return 0;
}*/

//*时间转换
int main(){
    int input, hour, minite, second;
    printf("Please input the seconds\n");
    scanf("%d", &input);
    hour = input / 3600;
    minite = (input - hour * 3600) / 60;
    second = (input - hour * 3600) % 60;
    printf("%d : %d : %d\n", hour, minite, second);
    return 0;
}

//*摄氏，华氏转化
int main()
{
	double F,C;
	scanf("%lf",&F);
	C=(F-32)*5/9;
	printf("%.2f",C);
    return 0;
}


