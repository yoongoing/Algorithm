#include <iostream>

using namespace std;

int GDC(int a, int b){
	if(a%b == 0)	
		return b;	
	return GDC(b, a%b);
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	for(int test_case=0; test_case<T; test_case++){
		int N;
		cin>>N;

		int num[101];
		for(int i=0; i<N; i++)
			cin>>num[i];
		
		long long sum = 0;
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				sum += GDC(max(num[i],num[j]), min(num[i],num[j]));
			}
		}
		cout<<sum<<endl;;
	}
	return 0;
}