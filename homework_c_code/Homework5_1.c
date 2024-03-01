#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char operator[3];
    float a, b, s;

    printf("TingyangXie 1230019461\n");
    printf("Enter an operator: (&&, ||, ==, !=, >, <, >=, <=, +, -, *, /, %): ");
    fgets(operator, sizeof(operator), stdin);

    size_t length = strlen(operator);
    if (length > 0 && operator[length - 1] == '\n') {
        operator[length - 1] = '\0';
    }

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);


    if (strcmp(operator, "&&") == 0) {
        s = (a != 0) && (b != 0);
    } 
    else if (strcmp(operator, "||") == 0) {
        s = (a != 0) || (b != 0);
    }
    else if (strcmp(operator, "!=") == 0) {
        s = (a != b);
    }
    else if (strcmp(operator, "==") == 0) {
        s = (a == b);
    }
    else if (strcmp(operator, ">=") == 0) {
        s = a >= b;
    }
    else if (strcmp(operator, "<=") == 0) {
        s = a <= b;
    }
    else {
        switch (operator[0]) {
            case '+':
                s = a + b;
                break;
            case '-':
                s = a - b;
                break;
            case '*':
                s = a * b;
                break;
            case '/':
                if (b != 0) {
                    s = a / b;
                } else {
                    printf("Division can not be zero\n");
                    return 1;
                }
                break;
            case '%':
                if (b != 0) {
                    s = (int)a % (int)b;
                } else {
                    printf("Modulo can not be zero\n");
                    return 1;
                }
                break;
            case '>':
                s = a > b;
                break;
            case '<':
                s = a < b;
                break;
        }
    }
    printf("%.2f %s %.2f = %.2f\n", a, operator, b, s);
    system("pause");
    return 0;
}
