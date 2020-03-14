#include <stdio.h>
#include <string.h>
int doub(int a){
	int save = 1;
	while (a != 0){
		save = save * 10;
		a--;
	}
	return save;
}

int main(){
	char data1[10000] = {0};
	char data2[10000] = {0};
	int i,save1,save2,save3,scan1,scan2,total1,total2,total3;
	scanf("%s %s",data1,data2);
	scan1 = strlen(data1);
	scan2 = strlen(data2);
	for(i=0; i<scan1; i++){
		if(data1[i] == '5'){
			data1[i] = '6';
		}
		save1 = save1 + (data1[i] - 48) * doub(scan1-i-1);
	}
	for(i=0; i<scan2; i++){
		if(data2[i] == '5'){
			data2[i] = '6';
		}
		save2 = save2 + (data2[i] - 48) * doub(scan2-i-1);
	}
	total1 = save1 + save2;
	save1 = 0;
	save2 = 0;
	for(i=0; i<scan1; i++){
		if(data1[i] == '6'){
			data1[i] = '5';
		}
		save1 = save1 + (data1[i] - 48) * doub(scan1-i-1); 
	}
	for(i=0; i<scan2; i++){
		if(data2[i] == '6'){
			data2[i] = '5';
		}
		save2 = save2 + (data2[i] - 48) * doub(scan2-i-1);
	}
	total2 = save1 + save2;
	printf("%d %d\n",total2,total1);
}
	