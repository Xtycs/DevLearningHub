/*int main() {
    int input, attempts = 0;
    int password = 222;
    int max_attempts = 5;

    for (attempts = 0; attempts < max_attempts; attempts++) {
        printf("Please enter your password: \n");
        scanf("%d", &input);

        if (input == password) {
            printf("Successful Verification.\n");
            break;
        } else {
            if (attempts == max_attempts - 1) {
                printf("Exceeded maximum number of attempts.\n");
            } else {
                printf("The password is incorrect, you have %d times to try.\n", max_attempts - attempts - 1);
            }
        }
    }

    return 0;
}*/





/*int main() {
    int password = 222;
    int input, attempts = 0;
    int max_attempts = 4;

    while (attempts < max_attempts) {
        printf("Enter the password: \n");
        scanf("%d", &input);

        if (input == password) {
            printf("Successful Verification\n\n");
            break;
        } else {
            attempts++;
            if (attempts < max_attempts) {
                printf("The password is incorrect\n");
            } else {
                printf("Exceeded maximum number of attempts\n");
            }
        }
    }

    return 0;
}*/

/*int main() {
    int password = 222;
    int T = 4; // Maximum number of attempts
    int userInput;
    int i;

    for (i = 0; i < T; i++) {
        printf("Enter the password: \n");
        scanf("%d", &userInput);

        if (userInput == password) {
            printf("Successful Verification\n");
            break;
        } else {
            printf("The password is incorrect, you have %d times to try\n", T - i - 1);
        }
    
    }
    if (i == T) {
        printf("Exceeded maximum number of attempts\n");
    }
    
    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>
int main(){
    int input, attempts = 0;
    int password = 222;
    int max_attempts = 5;
    for (attempts= 0; attempts<max_attempts; max_attempts--)
    {
        printf("Please enter your password.\n");
        scanf("%d", &input);
        if (input != password)
        {
            if(attempts=max_attempts)
            {
            printf("Exceeded maximum number of attempts\n");
            return 0;
            }
            else
            {
                printf("The password is incorrect. You have %d times to try.\n", max_attempts);
            continue;
            }
        }
        else if(input == password)
        {
            printf("Successful Verification.\n");
            return 0;
        }
    }
    return 0;
}

//*provided by CHatgpt
/*int main() {
    int password = 222;
    int T = 3; // Maximum number of attempts
    int userInput;
    int i;

    for (i = 0; i < T; i++) {
        printf("Enter the password: \n");
        scanf("%d", &userInput);

        if (userInput == password) {
            printf("Successful Verification\n");
            break;
        } else {
            printf("The password is incorrect, you have %d times to try\n", T - i - 1);
        }
    
    }
    if (i == T) {
        printf("Exceeded maximum number of attempts\n");
    }
    
    return 0;
}*/