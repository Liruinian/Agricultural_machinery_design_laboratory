#include <stdio.h>

void main()
{
	char c[] = "*";
	int i,a;
	for(i = 0; i < 6;i++)
	{
		for(a = 0; a < i + 1; a++)
		{
			printf("%s",c);
		}
		printf("\n");
	}
}  
