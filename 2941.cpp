#include <stdio.h>

int main(int argc, char const *argv[])
{
	char data[101];
	int check = 0;
	scanf("%s",data);
	for(int i=0; data[i]!= '\0'; i++){
		if(data[i] == 'c'){
			if(data[i+1] == '=' || data[i+1] == '-') {i++; check++;}
		}
		else if(data[i] == 'd'){
			if(data[i+1] == '-') {i++; check++;}
			else if(data[i+1] == 'z'){
				if(data[i+2] == '=') {i+=2; check++;}
				else check++;
			}
			else check++;
		}
		else if(data[i] == 'l'){
			if(data[i+1] == 'j') {i++; check++;}
			else check++;
		}
		else if(data[i] == 'n'){
			if(data[i+1] == 'j') {i++; check++;}
			else check++;
		}
		else if(data[i] == 's'){
			if(data[i+1] == '=') {i++; check++;}
			else check++;
		}
		else if(data[i] == 'z'){
			if(data[i+1] == '=') {i++; check++;}
			else check++;
		}
		else check++;
	}
	printf("%d\n", check);
	return 0;
}