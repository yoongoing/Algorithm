#include <stdio.h>
#include <string.h>
int whatisthis(char s[]);
void javachangec(char s[], char s1[]);
void cchangejava(char s[]);
int main(){
	int i,j;
	char identifier[1000] = {0};
	char data[1000] = {0};
	scanf("%s",identifier);
	int save = whatisthis(identifier);
	if(save == 3){
		printf("Error!\n");
	} 
	else if(save == 1){
		cchangejava(identifier);
		printf("%s\n", identifier);
	}
	else if(save == 2){
		javachangec(identifier,data);
		printf("%s\n",data);
	}
	else if(save == 4){
		for(i=0; identifier[i]!='\0'; i++){
			printf("%c",identifier[i]);
		}
		printf("\n");
	}

}

int whatisthis(char s[]){
	int i,j;
	int assign = 0;
	int cnt = 0;
	int length = strlen(s);
	for(i=0; s[i]!='\0'; i++){
		if(s[i] == '_'){
			if(i==0){
				assign = 3;
				break;
			}
			if(s[i+1]>='a' && s[i+1]<='z'){
				assign = 1;//C형식인것
			}

			else  {
				assign = 3;
				break;
			}	//Error
		}
		else if(s[i]>='A' && s[i]<='Z'){
			if(i != 0){
				assign = 2;//자바형식인것
			}
			else {
				assign = 3;
				break;//Error
			}
		}
		else{
			cnt++;
		}
		if(length == cnt){
			assign = 4;
		}
	}
	return assign;
}
//자바는 javaIdentifier
//C++은 c_identifier
void cchangejava(char s[]){
	int i,j;
	for(i=0; s[i]!='\0'; i++){
		if(s[i] == '_'){
			s[i] = s[i+1] - 32;
			for(j=i+1; s[j]!='\0'; j++){
				s[j] = s[j+1]; 
			}
		}
		else{
			if(i == 0){
				for(j=i; s[j]!='_'; j++){
					s[j] = s[j];
				}

			}
		}
	}
	s[j]='\0';
}

void javachangec(char s[], char s1[]){
	int i,j;
	char save;
	int cnt = 0;
	for(i=0; s[i]!='\0'; i++){
		if(s[i]>='A' && s[i]<='Z'){	
			s1[i+cnt] = '_';
			save = s[i] + 32;	
			s1[i+cnt+1] = save;

			for(j=i+1; s[j]!='\0'; j++){
				s1[j+1+cnt] = s[j];
			}
			cnt++;		
		}
		else{
			if(i == 0){
				for(j=i; !(s[j]>='A'&&s[j]<='Z'); j++){
					s1[j] = s[j];
				}
			}
		}
		
	}
}






