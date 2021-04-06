#include <stdio.h>

int main(){
	int hour,min;
	scanf("%d %d",&hour,&min);
	if(hour == 0){
		if(min - 45 < 0){
		hour = 23;
		min = 15 + min;
		}
		else{
			min = min - 45;
		}
	}	
	else{
		if(min - 45 < 0){
		hour--;
		min = 15 + min;
		}
		else{
			min = min - 45;
		}
	}
	printf("%d %d",hour,min);
}