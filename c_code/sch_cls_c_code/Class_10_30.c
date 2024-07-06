//!statement
/*#include <stdio.h>
int main(){
    int integer;
    for(integer=0,integer<=10,integer++)
    {
        if(integer/2>1,integer%2==0)

        printf("%d\n", integer);
        
    }
    return 0;
}*/

/*int main()
{
    int integer;
    for (integer = 0; integer <= 10; integer++)
    {
        if(integer%2==0 && integer%3!=0){
            printf("%d is the number you want\n", integer);
        }
    }
    return 0;
}*/


//* Example 3(caesar cipher)
/*#include <stdio.h> 
int main(){
    char plaintext[100] = "I like singing, dance,and rip";
    int index;
    int password = 5;
    for (index = 0; index <= 33;index++){
        printf("The first character of this string is %c", plaintext[0] + password);
        printf("%c", plaintext[index] + password);//?将[]内的换为一个变量，不断++
        
    }
    return 0;
}*/

//*array declaration



//*eample: calculate the trace of a square matrix
/*Trace: the summation of 
#include <stdio.h>
int main(){
    int matrix[3][3] = ({1, 2, 3}, {4, 5, 6}, {7, 8, 9});//?same as following
    int matrix[3][3] = (1, 2, 3, 4, 5, 6, 7, 8, 9);
    int row;
    int column;
    for (row = 0; row <= 3; row++){
    
    }
}*/

#include <stdio.h> // for printf()
//#include "helper.h" // for plus(), times()
//#include "sum.h" // for sum()
int main(void){
  int x, y;
  printf("Hi there, please provide two integers \n");
  scanf("%d%d", &x, &y);
  printf("The sum of %d + %d is %d \n", x, y, plus(x, y));
  printf("The sum of integers from %d to %d is %d \n", x, y, 
         sum(x, y));
  printf("the product of %d and %d is %d\n", x, y, times(x, y)) ;
  return 0;
}

