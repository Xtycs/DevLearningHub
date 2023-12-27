#include <stdio.h>
//if there is no break statement after a Case, the control will fall through to the next statement 
//regardless of whether its condition is true. This is called "fall-though behavior"
int main()
{
	int c= 0, k;
	for (k = 1; k < 3; k++){
		switch (k)
		{
		    default:c += k;
		    case 2:
			  c++; 
              break;
		    case 4:
			  c += 2; 
              break;
		}
    }
	printf("%d",c);
	return 0;
}