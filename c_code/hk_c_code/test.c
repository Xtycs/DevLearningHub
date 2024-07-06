#include <stdio.h>

int main() {
    char operator;
    float a, b, result;

    printf("Enter an operator: (+, -, *, /, %, >, <, >=, <=, ==, !=, &&, ||): ");
    scanf("%s", &operator);

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    switch (operator) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0) {
                result = a / b;
            } else {
                printf("Error: Division by zero\n");
                return 1;  // Exit with an error code
            }
            break;
        case '%':
            if (b != 0) {
                result = (int)a % (int)b;
            } else {
                printf("Error: Modulo by zero\n");
                return 1;  // Exit with an error code
            }
            break;
        case '>':
            result = a > b;
            break;
        case '<':
            result = a < b;
            break;
        case '>=':
            result = a >= b;
            break;
        case '<=':
            result = a <= b;
            break;
        case '==':
            result = (a == b);
            break;
        case '!=':
            result = (a != b);
            break;
        case '&&':
            result = (a != 0) && (b != 0);
            break;
        case '||':
            result = (a != 0) || (b != 0);
            break;
    }
    printf("%f %s %f = %f\n", a, operator, b, result);
    return 0;
}