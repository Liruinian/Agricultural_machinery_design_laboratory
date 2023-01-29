#include <stdio.h>

void main ()
{
	int speed;
	printf("车速 = ");
	scanf("%d",&speed);
	if ((speed >= 0) && (speed < 60))
	{
		printf("低速行驶");
	}else 
	if ((speed >= 60) && (speed <= 120))
	{
		printf("正常行驶");	
	}else
	if((speed > 120)){
		printf("超速行驶");
	}else
	{
		printf("非法输入");
	}
}
