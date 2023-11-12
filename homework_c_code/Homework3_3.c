#include <stdio.h>
#include <stdlib.h>
int main(){
    int input, attempts = 0;
    int password = 222;
    int max_attempts = 4;
    for (attempts= 0; attempts<=max_attempts; attempts++){
        printf("Please enter your password.\n");
        scanf("%d", &input);
        if (input == password){   
            printf("Successful Verification.\n");
            break;            
        }
        else{
            if(max_attempts == attempts){
                printf("Exceeded maximum number of attempts");
                break;
            }
            else{
                printf("The password is incorrect, you have %d times to try\n", max_attempts - attempts);
            }
        }
    }
    return 0;
}
