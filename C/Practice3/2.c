#include <stdio.h>

int main(){
	int n,a,b,i; 
	printf("��������: ");
	scanf("%d",&n);
	int s[n];
	for(i=0;i<n;i++){
		printf("��������: ");
		scanf("%d %d",&a,&b);
		s[i] = a + b;
	}
	printf("������: ");
	for(i=0;i<n;i++){
		printf("%d ",s[i]);
	}
	return 0;	
	} 

