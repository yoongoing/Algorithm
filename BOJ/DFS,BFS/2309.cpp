#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int height[9];
int check[9] = {0,};
vector <int> v;

void dfs(int prev, int H_sum, int cnt){
	if(cnt == 7){
		if(H_sum == 100){
			for(int i=0; i<9; i++)
				if(check[i])
					v.push_back(height[i]);
			sort(v.begin(),v.end());
			for(int i=0; i<7; i++)
				cout<<v[i]<<"\n";
			exit(0);
		}
		else
			return;
	}

	
	for(int i=prev+1; i<9; i++){
		check[i] = 1;
		dfs(i, H_sum+height[i], cnt+1);
		check[i] = 0;
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i=0; i<9; i++)
		cin>>height[i];

	dfs(-1,0,0);
	return 0;
}