#include <stdio.h>

int main()
{
	int n, m, i;
	printf("����nֵ��");
	scanf("%d", &n);
	while (n > 0)
	{
		m += n;
		n--;
	}
	printf("��ǰn���Ϊ��%d", m);
	return 0;
}
