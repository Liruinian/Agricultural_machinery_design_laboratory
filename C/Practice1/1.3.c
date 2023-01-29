#include <stdio.h>

void main ()
{
	float r,c,s;
	float pi = 3.14;
	printf("r = ");
	scanf("%f",&r);
	c = 2*pi*r;
	s = pi * r * r;
	printf("c = %.2f\ns = %.2f",c,s);
}
