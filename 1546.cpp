#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n,i;
	float data[1001],max=0,total=0;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%f",&data[i]);
		if(data[i] > max) max = data[i];
	}
	for(i=0; i<n; i++){
		data[i]  = (data[i] / max )*100;
		total += data[i];
	}
	printf("%f\n",total/n);
	return 0;
}