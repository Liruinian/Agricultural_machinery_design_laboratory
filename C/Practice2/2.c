#include <stdio.h>

int main()
{
	int n, m, t, i;
	printf("����nֵ��");
	scanf("%d", &n);
	t = n;
	for (i = 0; i < n; i++)
	{
		m += t;
		t--;
	}
	printf("��ǰn���Ϊ��%d", m);
	return 0;
}
