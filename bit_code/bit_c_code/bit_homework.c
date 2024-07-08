#include <stdio.h>
int main()
{
	int a, b, c;
	a = 5;
	c = ++a;
	b = ++c, c++, ++a, a++;
	b += a++ + c;
	printf("a = %d b = %d c = %d\n:", a, b, c);
	return 0;
}

#include <stdio.h>
int main()
{
    int a = 7;
    int b = 2;
    float c = 2.0f;
    printf("%d\n", 3);
    printf("%f\n", a / c);

    return 0;
}