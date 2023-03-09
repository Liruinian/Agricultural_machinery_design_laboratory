#include <stdio.h>

int main()
{
	int n, m, t, i;
	printf("输入n值：");
	scanf("%d", &n);
	t = n;
	for (i = 0; i < n; i++)
	{
		m += t;
		t--;
	}
	printf("其前n项和为：%d", m);
	return 0;
}
