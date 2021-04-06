#include <stdio.h>
#include <string.h>

int main(){
	int check[1000] = {0};
	int i,a,index,save,average,index2,frequent;
	for(i=0; i<10; i++){
		scanf("%d",&a);
		check[a]++;
		save = save + a;
		index++;
	}
	average = save / index;
	for(i=0; i<1000; i++){
		if(i == 0){
			frequent = check[i];
			index2 = i;
		}
		if(frequent < check[i]){
			frequent = check[i];
			index2 = i;
		}
	}
	printf("%d\n%d\n",average,index2);
}