#include <stdio.h>

int main(){
	int n,r,c,s,s1,s2; 
	// c:col¡– r:row–– s1,s2:star1,2
	scanf("%d",&n);
	s = n / 2 + 1;
	printf("s=%d\n",s);
 	for(r=0;r<n;r++){
 		if(r<s){
 			s1 = s + r;
			s2 = s - r;
			
		 }else{
		 	s1 -= 1;
		 	s2 += 1;
		 }
		for(c=1;c<n + 1;c++){
				if(c==s1 || c==s2){
					printf("*");
				}else{
					printf(" ");	
				}
			}
			printf("\n"); 
		} 
		return 0;	
	} 

