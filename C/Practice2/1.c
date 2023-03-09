#include <stdio.h>

int main()
{
	long long input;
	int a = 0, b = 0, i;
	scanf("%lld", &input);
	while (input >= 10)
	{
		a++;
		b += input % 10;
		input /= 10;
	}
	// 加上最高位的数字
	b += input;
	a += 1;
	printf("%d\n%d", a, b);
	return 0;
}
