#include <iostream>

using namespace std;

int N,M,H;

int ladder[31][11];
int MIN = 987654321;

int check(){
	for(int i=1; i<=N; i++){
		int start = i;
		for(int j=1; j<=H; j++){
			if(ladder[j][start])
				start++;
			else if(ladder[j][start-1])
				start--;
		}
		if(start != i)
			return 0;
	}
	return 1;
}


void dfs(int y, int cnt){
	// cnt>3 이면 종료
	if(cnt > 3)
		return;

	// cnt<=3 인데 조건만족시 min값 업데이트
	if(check()){
		MIN = min(MIN, cnt);
		return;
	}

	// cnt<=3인데 조건불만족시 사다리 놓기
	for(int i=y; i<=H; i++){
		for(int j=1; j<=N; j++){
			if(ladder[i][j] || ladder[i][j-1] || ladder[i][j+1])
				continue;
			ladder[i][j] = 1;
			dfs(i, cnt+1);
			ladder[i][j] = 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M>>H;

	for(int i=0; i<M; i++){
		int y,x;
		cin>>y>>x;
		ladder[y][x] = 1;
	}
	dfs(1, 0);

	if(MIN == 987654321)
		cout<<"-1\n";
	else
		cout<<MIN<<"\n";
	return 0;
}