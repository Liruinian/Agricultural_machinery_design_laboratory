#include <stdio.h>

void main ()
{
	int speed;
	printf("���� = ");
	scanf("%d",&speed);
	if ((speed >= 0) && (speed < 60))
	{
		printf("������ʻ");
	}else 
	if ((speed >= 60) && (speed <= 120))
	{
		printf("������ʻ");	
	}else
	if((speed > 120)){
		printf("������ʻ");
	}else
	{
		printf("�Ƿ�����");
	}
}
