#include <stdio.h>

int main(){
	int n,a,max=0,min=10000,i; 
	scanf("%d",&n);
	int s[n];
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a>max){
			max = a;
		}if(a < min){
			min = a;
		}
	}
	printf("���ֵ��%d\n��Сֵ��%d",max,min);
	return 0;	
	} 

