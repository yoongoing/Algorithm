#include <iostream>
#include <algorithm>
#include <math.h>

#define MAX 15
using namespace std;

int N;
int plan[MAX+1][2];
int max_ = 0;



void DFS(int n, int total){
	if(n == N+1){
		max_ = max(max_,total);
		return;
	}

	DFS(n+1, total);
	
	if(n+plan[n][0] <= N+1){
		DFS(n+plan[n][0], total+plan[n][1]);
	}
	

}

int main(int argc, char const *argv[])
{
	plan[0][0] = plan[0][1] = 0;

	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>plan[i][0]>>plan[i][1];
	}

	DFS(1,0);
	
	cout<<max_<<endl;
	return 0;
}