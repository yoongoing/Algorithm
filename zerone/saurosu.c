#include <stdio.h>
#include <string.h>

int main(){
	int n,i,mok,na,nn,ii;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		nn = n;
		ii = i;
		while(1){
			mok = nn/ii;
			na = nn%ii;
			if(na == 0){
				break;
			}
			nn = ii;
			ii = na;
		}
		if(ii == 1){
			printf("%d ",i);
		}		
	}		
}
