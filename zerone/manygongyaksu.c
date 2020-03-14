#include <stdio.h>
#include <string.h>

int main(){
	int n,a,b,i;
	int data[10000] = {0};
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
		scanf("%d",&data[i]);
	}
	a = 0;
	b = 0;
	int q,r,ii;
	if(n == 1){
		printf("%d\n",data[0]);
	}
	else{
		for(i=0; i<n; i++){
			ii = data[i];
			if(a != 0){					
				while(1){
					if(a > ii){
						q = a/ii;
						r = a%ii;
						if(r == 0){
							break;
						}
						a = ii;
						ii = r;
					}
					else{
						q = ii/a;
						r = ii%a;
						if(r == 0){
							break;
						}
						ii = a;
						a = r;
					}

				}
				if(a > ii){
					if(ii != 1){
						b = ii;
					}
					else{
						printf("1\n");
						return 0;
					}
				}
				else{
					if(a != 1){
						b = a;
					}
					else{
						printf("1\n");
						return 0;
					}
				}
			}
			if(i == 0){
				a = data[i];
			}
			else{
				a = b;
			}	
		}
		printf("%d\n",b);
	}
}