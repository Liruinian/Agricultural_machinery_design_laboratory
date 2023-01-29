#include <stdio.h>

int main()
{
	int a, b, m = 0, n = 0;
	// m为偶数
	scanf("%d%d", &a, &b);
	while (b > a - 1)
	{
		if (b % 2 == 0)
		{
			m++;
		}
		else
		{
			n++;
		}
		b--;
	}
	printf("偶数个数：%d\n奇数个数：%d", m, n);
	return 0;
}
