#include <iostream>
#include <math.h>

#define MAX 21
using namespace std;

int n;
int ability[MAX][MAX];
int status[MAX];
int ans = 987654321;


void calculate(){
	int start_ = 0;
	int link_ = 0;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i == j) continue;
			if(status[i] == 1 && status[j] == 1)
				start_ += ability[i][j];
			if(status[i] == 0 && status[j] == 0)
				link_ += ability[i][j];
		}
	}

	ans = min(ans, abs(start_-link_));
}


void dfs(int cnt, int k){
	if(cnt == n/2){
		calculate();
		return;
	}

	for(int i=k+1; i<=n; i++){
		if(status[i]){
			continue;
		}
			
		status[i] = 1;
		dfs(cnt+1,i);
		status[i] = 0;
	}
}

int main(int argc, char const *argv[])
{
	//s:19 l:12
	cin>>n;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>ability[i][j];

	dfs(0,0);

	cout<<ans<<endl;
	return 0;
}