#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin>>N;

	double arr[10001];
	double sum=0., max = -1;

	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i];
	}
	
	for(int i=0; i<N; i++){
		sum = 1;
		for(int j=i; j<N; j++){
			sum *= arr[j]; 
			if(sum > max) max = sum;
		}
	}
	cout<<fixed;
	cout.precision(3);
	cout<<max;


	return 0;
}