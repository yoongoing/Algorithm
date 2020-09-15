#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n1, n2;
	cin>>n1>>n2;

	int larger = max(n1,n2);
	int a = 0;

	for(int i=1; i<=larger; i++){
		if((n1%i == 0) && (n2%i == 0)){
			a = max(a,i);
		}
	}
	
	cout<<a<<endl;
	cout<<a * (n1/a) * (n2/a)<<endl;


	return 0;
}