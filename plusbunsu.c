#include <stdio.h>

int main(){
	int a,b;
	int save_a, save_b;
	int save_ab_down;
	int save_ab_up;
	int i,j;
	for(i=0; i<2; i++){
		scanf("%d %d",&a,&b);		
		if(i == 0){
			save_a = a;
			save_b = b;
		}
		else{
			if(save_b != b){
				save_ab_down = save_b * b;
				save_ab_up = a * save_b + b * save_a;
			}
			else{
				save_ab_down = b;
				save_ab_up = a + save_a;
			}
		}

	}
	int save_a_2 = save_ab_up;
	int save_b_2 = save_ab_down;
	int c,d;
	if(save_ab_up > save_ab_down){
		while(1){
			c = save_a_2 % save_b_2;
			d = save_a_2 / save_b_2;
			if(c == 0){
				if(save_b_2 == 1){
					printf("%d %d\n",save_ab_up,save_ab_down);
					break;
				}
				else{
					save_ab_up = save_ab_up / save_b_2;
					save_ab_down = save_ab_down / save_b_2;
					save_a_2 = save_ab_up;
					save_b_2 = save_ab_down; 
					continue;
				}
				
			}
			save_a_2 = save_b_2;
			save_b_2 = c;
		}
	}
	else{
		while(1){
			c = save_b_2 % save_a_2;
			d = save_b_2 / save_a_2;
			if(c == 0){
				if(save_a_2 == 1){
					printf("%d %d\n",save_ab_up,save_ab_down);
					break;
				}
				else{
					save_ab_up = save_ab_up / save_a_2;
					save_ab_down = save_ab_down / save_a_2;
					save_a_2 = save_ab_up;
					save_b_2 = save_ab_down; 
					continue;
				}
				
			}
			save_b_2 = save_a_2;
			save_a_2 = c;
		}
	}
}	
/*
#include <stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    int a,b,c,d,z,x;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    z=a*d+c*b;
    x=d*b;
    printf("%d %d",z/gcd(z,x),x/gcd(z,x));
}
*/	