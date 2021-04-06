#include <stdio.h>

int main(){
	int j,x;
	int i = 0;
	int n = 1;
	int a = 0;
	int b = 0;
	scanf("%d",&x);
	int save;
	while(n * (n+1) / 2 <= x ){
		save = n * (n + 1) / 2;		
		n++;
		i++;
	}
	int aa = x - save;
	if(aa == 0){
		if(x == 1){
			printf("1/1\n" );
			return 0;
		}
		else{
			if(i%2 == 0){
				printf("%d/1\n",i);
				return 0;
			}
			else{
				printf("1/%d\n",i);
				return 0;
			}
		}			
	}
	if(i%2 == 0){
		a = i;
		b = 0;	
		for(j=1; j<aa; j++){
			a--;
			b++;
		}
	}	
	else{
		a = 0;
		b = i;
		for(j=1; j<aa; j++){
			b--;
			a++;
		}
	}
	
	
	printf("%d/%d\n",a+1,b+1);
}
/*
#include<stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    for(int i=1;;i++){
        if(i*(i+1)/2>n){
            if(i%2==1){
                printf("%d/%d",i*(i+1)/2-n+1,i-i*(i+1)/2+n);
            }
            else{
                printf("%d/%d",i-i*(i+1)/2+n,i*(i+1)/2-n+1);
            }
            break;
        }
        else if(i*(i+1)/2==n){
            if(i%2==1){
                printf("1/%d",i);
            }
            else{
                printf("%d/1",i);
            }
            break;
        }
    }
    return 0;
}
*/