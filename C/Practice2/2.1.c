#include <stdio.h>

int main()
{
	int n, m, i;
	printf("输入n值：");
	scanf("%d", &n);
	while (n > 0)
	{
		m += n;
		n--;
	}
	printf("其前n项和为：%d", m);
	return 0;
}
