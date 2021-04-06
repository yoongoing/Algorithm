#include <stdio.h>

int main(){
	int N,input;
	int save_total=-100000; 
	int save_change = 0;
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&input);
		save_change += input;
		if(save_total < save_change){
			save_total = save_change;
		}
		if(save_change < 0){
			save_change = 0;
		}

	}
	printf("%d\n",save_total);

}