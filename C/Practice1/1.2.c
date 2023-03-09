#include <stdio.h>

void main ()
{
	int x,y,res;
	printf("x = ");
	scanf("%d",&x);
	res = x; 
	for(y = 0; y < 3 - 1; y++)
	{
		res = x * res;
	}
	printf("y = x^3 = %d",res);
}
