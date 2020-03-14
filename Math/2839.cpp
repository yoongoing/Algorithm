#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,five, five_,three;
	scanf("%d",&n);

	five = n/5;
	five_ = n%5;

	while(five>=0){
		if(five_%3 == 0){
			three = five_/3;
			printf("%d\n",five + three);
			return 0;
		}
		else
			five--;
			five_ += 5;
	}
	printf("-1\n");
	return 0;
}