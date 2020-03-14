#include <stdio.h>
#define MAXVAL   100    /* maximum depth of val stack */

static int sp = 0;             /* next free stack position */
static double val[MAXVAL];     /* value stack */


void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
	if (sp >0)
		return val[--sp];
	else {
		return -1.0;
	}
}
void empty(void){
	if(sp == 0){
		printf("1\n");
	}
	else{
		printf("0\n");
	}
}
void top(void){
	if(sp == 0){
		printf("-1\n");
	}
	else {
		printf("%f\n",pop());
	}
}
void size(void){
	printf("%d\n",sp);
}

int main(){
	int num;
	scanf("%d",&num);
	for(int i=0; i<num; i++){
		int check = 0;
		double number;
		char demand[1000]={0};
		scanf("%s",demand);
		if(demand[0] == 'p'){
			scanf("%lf",&number);
			check++;
			if(demand[1] == 'u'){
				check++;
			}
		}
		else if(demand[0] == 't'){
			check = 3;
		}
		else if(demand[0] == 's'){
			check = 4;
		}
		else if (demand[0] == 'e'){
			check = 5;
		}


		if(check == 1){
			printf("%.f\n",pop());
		}
		else if(check == 2){
			push(number);
		}
		else if (check == 3){
			double c = pop();
			printf("%.f\n", c);
			push(c);
		}
		else if(check == 4){
			size();
		}
		else if(check == 5){
			empty();
		}		
	}

}