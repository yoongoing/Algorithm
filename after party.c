#include <stdio.h>

int main(){
	int i,people_total,meter,people,enter;
	scanf("%d %d",&meter,&people);
	people_total = meter * people;
	for(i=0; i<5; i++){
		scanf("%d",&enter);
		printf("%d ",enter - people_total);
	}
}