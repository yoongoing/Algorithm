#include <iostream>
#include <string>

using namespace std;

int n;
int num[12];
int oper_num[4];

int max_sum = -1000000001;
int min_sum = 1000000001;


void dfs(int plus, int minus, int multiply, int devide, int sum, int idx){
	if(idx == n){
		if(max_sum < sum) max_sum = sum;
		if(min_sum > sum) min_sum = sum;
		return;
	}
	if(plus > 0)		dfs(plus-1, minus  , multiply  , devide  , sum+num[idx], idx+1);
	if(minus > 0)		dfs(plus  , minus-1, multiply  , devide  , sum-num[idx], idx+1);
	if(multiply > 0)	dfs(plus  , minus  , multiply-1, devide  , sum*num[idx], idx+1);
	if(devide > 0)		dfs(plus  , minus  , multiply  , devide-1, sum/num[idx], idx+1);
	
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0; i<n; i++){
		cin>>num[i];
	}	
	for(int i=0; i<4; i++){
		cin>>oper_num[i];
	}

	dfs(oper_num[0],oper_num[1],oper_num[2],oper_num[3],num[0],1);

	cout<<max_sum<<"\n"<<min_sum<<"\n";

	return 0;
}