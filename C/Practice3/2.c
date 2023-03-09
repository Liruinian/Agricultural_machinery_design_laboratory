#include <stdio.h>

int main(){
	int n,a,b,i; 
	printf("数据组数: ");
	scanf("%d",&n);
	int s[n];
	for(i=0;i<n;i++){
		printf("输入数据: ");
		scanf("%d %d",&a,&b);
		s[i] = a + b;
	}
	printf("输出结果: ");
	for(i=0;i<n;i++){
		printf("%d ",s[i]);
	}
	return 0;	
	} 

