#include <iostream>
#include <cstdio>

#define MAX 1000003
 
using namespace std;
int check[MAX];
void set_(){
	for(int i=2; i*i<MAX; i++)
		if(!check[i])
			for(int j=i*i; j<MAX; j+=i) // 배수를 지운다.
				check[j] = 1;
	check[1] = 1;
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	set_();	

	int n;
	while(1){
		cin>>n;
		if(n == 0)
			break;

		bool chk = false;
		
		for(int i=3; i<=n; i+=2){
			if(!check[i] && !check[n-i]){
				cout<<n<<" = "<<i<<" + "<<n-1<<"\n";
				chk = true;
				break;
			}
		}
		if(!chk)
			cout<<"Goldbach\'s conjecture is wrong.\n";
	}
	return 0;
}
