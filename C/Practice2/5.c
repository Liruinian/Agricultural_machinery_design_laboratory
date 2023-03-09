#include <stdio.h>

int main()
{
	int i, a, b, c, t;
	for (i = 100; i < 1000; i++)
	{
		a = i / 100;
		b = i % 100;
		t = b;
		b = t / 10;
		c = t % 10;

		if (i == cube(a) + cube(b) + cube(c))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

int cube(int inp)
{
	return inp * inp * inp;
}
