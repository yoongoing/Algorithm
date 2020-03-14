#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N,B,C;
	int A[1000001] = {0,};

	cin>>N;
	for(int i=0; i<N; i++)
		cin>>A[i];
	cin>>B>>C;


	long long total = 0;

	for(int i=0; i<N; i++)
	{
		int quo;
		int remain;

		A[i] -= B;
		total++;


		if(A[i] > 0){
			quo = A[i]/C;
			remain = A[i]%C;
			if(remain != 0) total+= quo+1;
			else total+= quo;
		}
	}
	cout<<total;


	return 0;
}