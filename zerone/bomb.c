#include <stdio.h>
 int main(){
 	int i,j,k;
 	int data[1000][1000]={0};
 	// int data1[1000][1000];
 	for(i=1;i<11;i++){
 		for(j=1;j<11;j++){
 			scanf("%d",&data[i][j]);
 		}
 		
 	}
 	
 	for(i=1;i<11;i++){
 		for(j=1;j<11;j++){
 			if(data[i][j]== 1){
 				data[i][j] = 10;
 			}
 		}
 	}

 	for(i=1;i<11;i++){
 		for(j=1;j<11;j++){			
 			if(data[i][j] >= 10){
 				// data[i][j]++;
 				data[i][j-1]++;
 				data[i][j+1]++;
 				data[i-1][j-1]++;
 				data[i-1][j]++;
 				data[i-1][j+1]++;
 				data[i+1][j]++;
 				data[i+1][j-1]++;
 				data[i+1][j+1]++;

 			}			
 		}
 	}
 	for(i=1;i<11;i++){
 		for(j=1;j<11;j++){	
 			if(data[i][j]>=10){
 				printf("* "); 
 			}
 			else{
 				printf("%d ",data[i][j]);
 			}
 		}
 		printf("\n");
 	}

}