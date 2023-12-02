#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    int layer;
    printf("Please input an integer:\n");
    scanf("%d", &n);
    printf("There is a %d layer triangle\n", n);
    for (layer = 1; layer <= n; layer++) {
        
        for (int space = 0; space < n - layer; space++) {
            printf("o");
        }
        
        for (int star = 0; star < 2 * layer - 1; star++) {
            printf("*");
        }
        
        for (int space = 0; space < n - layer; space++) {
            printf("o");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
