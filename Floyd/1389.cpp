#include <iostream>
#include <cstring>
#include <algorithm>

#define INF 987654321
#define MAX 100

using namespace std;

int N,M;
int relation[MAX+1][MAX+1];

void infinite_maker(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(relation[i][j] != 1) 
				relation[i][j] = INF;
		}
	}
}

void floyd(){
	for(int k=1; k<=N; k++){//출발점
		for(int i=1; i<=N; i++){//도착점
			for(int j=1; j<=N; j++){//중간점
				if(i == j) 
					continue;
				relation[i][j] = min(relation[i][k] + relation[k][j],relation[i][j]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;

	for(int i=0; i<M; i++){
		int x,y;
		cin>>x>>y;
		relation[x][y] = 1;
		relation[y][x] = 1;
	}
	infinite_maker();
	floyd();

	int result = INF;
	int index;
	for(int i=1; i<=N; i++){
		int total = 0;
		for(int j=1; j<=N; j++)
			if(relation[i][j]!= INF)
				total += relation[i][j];
		if(result > total){
			result = total;
			index = i;
		}
	}
	cout<<index<<endl;
	return 0;
}
