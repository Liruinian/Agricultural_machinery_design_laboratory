#include <stdio.h>
#include <string.h>

int main()
{
	printf("�����������ѡ������ģʽ\n1 ����ȡ��ģʽ\n2 С��ģʽ\n") ; 
	int s;
	int a,b;
	float af,bf;
	scanf("%d",s);
	printf("����������ͱ��������Իس�������\n") ; 
	switch (s)
	{
		case 1:
			scanf("%d%d",&a,&b);
			printf("��� = %d",a / b);
			printf("���� = %d",a % b);
		case 2:
			scanf("%f%f",&af,&bf);
			printf("��� = %f",af / bf);
		default:
			printf("Not valid input");
	}
	
	return 0;
} 
