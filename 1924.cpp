#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x,y,i;
	int total=0, day;
	int date[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d",&x,&y);
	for(i=0; i<x-1; i++){
		total += date[i];
	}	
	
	total += y;
	day = total%7;

	if(day == 0) printf("SUN\n");
	else if(day == 1) printf("MON\n");
	else if(day == 2) printf("TUE\n");
	else if(day == 3) printf("WED\n");
	else if(day == 4) printf("THU\n");
	else if(day == 5) printf("FRI\n");
	else if(day == 6) printf("SAT\n");

	return 0;
}