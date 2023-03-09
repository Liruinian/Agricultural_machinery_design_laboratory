#include <stdio.h>

int main(){
	int m,n,i,j,max=0,d,dm,dn;
	// m:行 n:列 
	scanf("%d %d",&m,&n);
	for(i=1;i<m+1;i++){
		for(j=1;j<n+1;j++){
			scanf("%d",&d);
			if(d > max){
				max = d;
				dm = i;
				dn = j;
				
			}
		}
	}
	
	printf("最大值：%d\n所在行：%d 所在列：%d",max,dm,dn);
	return 0;	
	} 

