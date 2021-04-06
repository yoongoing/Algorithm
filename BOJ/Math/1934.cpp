#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int n1, n2;
		cin>>n1>>n2;

		int larger = max(n1,n2);
		int a = 0;

		for(int j=1; j<=larger; j++){
			if((n1%j == 0) && (n2%j == 0)){
				a = max(a,j);
			}
		}
		cout<<a * (n1/a) * (n2/a)<<endl;
	}
	return 0;
}