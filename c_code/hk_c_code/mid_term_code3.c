#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    
    srand(time(0));
    int rand_i = rand() % 100;

    int input, attempts = 0;
    int max_attempts = 5;
    printf("Student ID: 1230019461\n");
    for (attempts= 1; attempts<=max_attempts; attempts++){
        printf("Please input a possible integer\n");
        scanf("%d", &input);
        if (input == rand_i){   
            printf("BINGO\n");
            break;            
        }
        else{
            if(input >> rand_i){
                printf("TOO BIG\n");
            }
            if(input << rand_i){
                printf("TOO SMALL\n");
            }
            if(max_attempts == attempts){
                printf("GAME OVER, the correct number is %d", rand_i);
                break;
            }
        }
    }
    system("pause");
    return 0;
}