#include <stdio.h>

int main(){
	int n,i,j,m;
	int sum = 0;
	int save;
	int index[1000] = {0};
	int total = 0;
	int data[155] = {0};
	for(i=0; i<8; i++){
		scanf("%d",&data[i]);		
	}
	for(i=0; i<8; i++){
		index[i] = data[i];		
	}
	for(i=0; i<8; i++){
		// first = data[i];
			for(j=i+1; j<8; j++){
				if(data[i] >= data[j]){
					save = data[i];
					data[i] = data[j];
					// first = data[j];
					data[j] = save;					
				}							
			}			
	}		
	for(i=7; i>=3; i--){
		sum = sum + data[i];	
	}	
	printf("%d\n",sum);
	for(i=0; i<8; i++){
		for(j=3; j<8; j++){
			if(index[i] == data[j]){
				printf("%d ",i+1);
			}
		}
	}
}
/*
#include<stdio.h>

int main(){
    int data[10]={0},check[10]={0},max=0,max_idx=-1,sum=0;
    for(int i=0;i<8;i++){
        scanf("%d",&data[i]);
    }
    for(int i=0;i<5;i++){       // 최대값 5개만 찾으면 되므로
        for(int j=0;j<8;j++){   // 배열에서 체크되지 않은 최대값을 찾는 for문
            if(max<data[j] && check[j]==0){
                max_idx = j;
                max = data[j];
            }
        }
        sum+=max;   // 찾은 최대값들을 계속해서 쌓아줌
        check[max_idx]=1;   // 찾은 최대값 위치는 더 이상 볼 필요 없으므로 check[max_idx]을 0에서 1로 변경
        max=0;      // max 초기화를 안해주면 제일 큰 값 하나만 찾게되고 그 값이 sum에 5번 쌓임
    }
    printf("%d\n",sum);
    for(int i=0;i<8;i++){
        if(check[i])    // 찾은 최대값들 숫자 위치만 출력
            printf("%d ",i+1);
    }
    return 0;
}
*/
