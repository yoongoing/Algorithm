#include <iostream>
#include <cstring>

using namespace std;

long long int multi(long long int x,long long int num,long long int c){
	if(num == 0) return 1;
	long long temp = multi(x,num/2,c);
	temp *= temp;
	temp %= c;
	if(num%2 == 0){
		return  temp;
	} 
	return x*temp%c;
	
}

int main(int argc, char const *argv[])
{
	long long int A,B,C;
	cin>>A>>B>>C;

	cout<<multi(A,B,C)<<endl;
	return 0;
}