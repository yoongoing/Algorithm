#include <iostream>

using namespace std;
int n;
int cost[11][11];
int visit[11] = {0,};
int min_cost = 987654321;

void dfs(int cur_city, int end_city, int cnt, int cost_sum){
	if(cnt==n && cur_city==end_city){
		min_cost = min(min_cost, cost_sum);
		return;	
	}

	for(int i=0; i<n; i++){
		if(cost[cur_city][i] == 0) //같은도시방문 안됨
			continue;
		if(visit[i]) //갔던 도시방문 안됨
			continue;
		if(cost_sum+cost[cur_city][i] <= min_cost){
			visit[i] = 1;
			dfs(i, end_city, cnt+1, cost_sum+cost[cur_city][i]);
			visit[i] = 0;	
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>cost[i][j];
		}
	}
	for(int i=0; i<n; i++){
		dfs(i, i, 0, 0);
	}
	cout<<min_cost<<"\n";
	return 0;
}