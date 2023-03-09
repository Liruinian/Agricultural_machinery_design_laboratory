#include <stdio.h>

void main ()
{
	int a;
	int b = 7;
	scanf("%d",&a);
	b = a % 7;
	if(b != 0)
	{
		printf("No");
	} else {
		printf("Yes");
	}
	
}
