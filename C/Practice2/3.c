#include <stdio.h>

int main()
{
	int a, b, c, m = 0, n = 0, i;
	// m为偶数
	scanf("%d%d", &a, &b);
	c = b;
	for (i = 0; i < c - a + 1; i++)
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
