#include <stdio.h>

int main(){
	int n,i,j,d,md=0,sd=0;
	scanf("%d",&n);
	for(i=1;i<n+1;i++){
		for(j=1;j<n+1;j++){
			scanf("%d",&d);
			if(i==j){
				md += d;
			}
			if(n-j+1 == i){
				sd += d;
			}
		}
	}
	printf("���Խ���֮�ͣ�%d\n�ζԽ���֮�ͣ�%d",md,sd);
	return 0;
}


