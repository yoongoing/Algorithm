#include <iostream>

using namespace std;

int cnt = 0;
int num[3] = {1,2,3};

void dfs(int sum, int end){
	if(sum > end)
		return;
	if(sum == end){
		cnt++;
		return; 
	}
	for(int i=0; i<3; i++){
		dfs(sum+num[i], end);
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin>>T;

	for(int test=0; test<T; test++){
		int n;
		cin>>n;
		dfs(0,n);
		cout<<cnt<<"\n";
		cnt = 0;
	}
	return 0;
}