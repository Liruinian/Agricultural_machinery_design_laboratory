#include <stdio.h>
#include <string.h>

int main()
{
	printf("两数相除：请选择输入模式\n1 整数取余模式\n2 小数模式\n") ; 
	int s;
	int a,b;
	float af,bf;
	scanf("%d",s);
	printf("请输入除数和被除数，以回车键结束\n") ; 
	switch (s)
	{
		case 1:
			scanf("%d%d",&a,&b);
			printf("结果 = %d",a / b);
			printf("余数 = %d",a % b);
		case 2:
			scanf("%f%f",&af,&bf);
			printf("结果 = %f",af / bf);
		default:
			printf("Not valid input");
	}
	
	return 0;
} 
