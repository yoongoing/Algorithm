#include <cstring>
#include <iostream>
#include <queue>

#define MAX 20
using namespace std;

int N;
int block[MAX][MAX];
int result;

void shift(int type){
	queue<int> q;

	switch(type){
	case 0://left
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(block[i][j])
					q.push(block[i][j]);
				block[i][j] = 0;
			}
			int idx = 0;
			while(!q.empty()){
				int data = q.front();
				q.pop();

				if(block[i][idx]  == 0)
					block[i][idx] = data;
				
				else if(block[i][idx] == data){
					block[i][idx] *=2;
					idx++;
				}
				else{
					idx++;
					block[i][idx] = data;
				}
			}		
		}
		break;

	case 1://right
		for(int i=0; i<N; i++){
			for(int j=N-1; j>=0; j--){
				if(block[i][j])
					q.push(block[i][j]);
				block[i][j] = 0;
			}
			int idx = N-1;
			while(!q.empty()){
				int data = q.front();
				q.pop();

				if(block[i][idx]  == 0)
					block[i][idx] = data;
				
				else if(block[i][idx] == data){
					block[i][idx] *=2;
					idx--;
				}
				else{
					idx--;
					block[i][idx] = data;
				}
			}		
		}
		break;
	case 2: //up
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(block[j][i])
					q.push(block[j][i]);
				block[j][i] = 0;
			}
			int idx = 0;
			while(!q.empty()){
				int data = q.front();
				q.pop();

				if(block[idx][i]  == 0)
					block[idx][i] = data;
				
				else if(block[idx][i] == data){
					block[idx][i] *=2;
					idx++;
				}
				else{
					idx++;
					block[idx][i] = data;
				}
			}		
		}
		break;
	case 3://down
		for(int i=0; i<N; i++){
			for(int j=N-1; j>=0; j--){
				if(block[j][i])
					q.push(block[j][i]);
				block[j][i] = 0;
			}
			int idx = N-1;
			while(!q.empty()){
				int data = q.front();
				q.pop();

				if(block[idx][i]  == 0)
					block[idx][i] = data;
				
				else if(block[idx][i] == data){
					block[idx][i] *=2;
					idx--;
				}
				else{
					idx--;
					block[idx][i] = data;
				}
			}		
		}
		break;
	}
}
void dfs(int cnt){
	if(cnt == 5){
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				result = max(result,block[i][j]);
		return;
	}
	int cpyblock[MAX][MAX];

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cpyblock[i][j] = block[i][j];
	}

	for(int i=0; i<4; i++){
		shift(i);
		dfs(cnt+1);

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				block[i][j] = cpyblock[i][j];
	}
}

int main(int argc, char const *argv[])
{
	cin>>N;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>block[i][j];
		}
	}
	dfs(0);

	cout<<ans<<endl;

	return 0;
}