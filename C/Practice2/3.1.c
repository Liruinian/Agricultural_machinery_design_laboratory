#include <stdio.h>

int main()
{
	int a, b, m = 0, n = 0;
	// mΪż��
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
	printf("ż��������%d\n����������%d", m, n);
	return 0;
}
