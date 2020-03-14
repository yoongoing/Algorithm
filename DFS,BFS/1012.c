#include <stdio.h>





int main(){
	int n,i,j,l;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		int data1[10000][10000] = {0};
		int data2[10000][2] = {0};//data2[j][0] : x, data2[j][1] : y
		int m,n,k;
		scanf("%d %d %d",&m,&n,&k);
		for(j=0; j<k; j++){
			scanf("%d %d",data2[j][0],data2[j][1]);
		}
		for(j=0; j<k; j++){
			for(l=0; l<2; l++){
				if(data2[j][l] == j || data2[j][l] == l)
			}
		}
	}
}