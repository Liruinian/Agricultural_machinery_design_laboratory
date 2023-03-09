#include <stdio.h>

int main()
{
	int a, b, i, m = 0;
	scanf("%d%d", &a, &b);
	int num[a];
	for (i = 0; i < a; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] % b == 0)
		{
			m++;
		}
	}

	printf("%d\n", m);
	if (m % 2 == 0)
	{
		printf("True");
	}
	else
	{
		printf("False");
	}

	return 0;
}
