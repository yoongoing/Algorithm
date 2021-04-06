#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 20

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
			
				int idx = 0;
				while(!q.empty()){
					int temp = q.front();
					q.pop();
					if(block[idx][i] == 0)
						block[idx][i] = temp;
					else if(block[idx][i] == data){
						block[idx][i] *= 2;
						idx++;
					}
					else{
						idx++;
						block[idx][i] = data;
					}

				}
			}
		}
		break;

	case 1://right
		for(int i=0; i<N; i++){
			for(int j=N-1; j>=0; j--){
				if(block[i][j])
					q.push(block[i][j]);
			
				int idx = N-1;
				while(!q.empty()){
					int temp = q.front();
					q.pop();
					if(block[idx][i] == 0)
						block[idx][i] = temp;
					else if(block[idx][i] == data){
						block[idx][i] *= 2;
						idx--;
					}
					else{
						idx--;
						block[idx][i] = data;
					}

				}			
			}
		}
	case 2://top
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(block[j][i])
					q.push(block[j][i]);
			
				int idx = 0;
				while(!q.empty()){
					int temp = q.front();
					q.pop();
					if(block[i][idx] == 0)
						block[i][idx] = temp;
					else if(block[i][idx] == data){
						block[i][idx] *= 2;
						idx++;
					}
					else{
						idx++;
						block[idx][i] = data;
					}

				}
			}
		}
	case 3://bottom
		for(int i=0; i<N; i++){
			for(int j=N-1; j>=0; j--){
				if(block[j][i])
					q.push(block[j][i]);
			
				int idx = 0;
				while(!q.empty()){
					int temp = q.front();
					q.pop();
					if(block[i][idx] == 0)
						block[i][idx] = temp;
					else if(block[i][idx] == data){
						block[i][idx] *= 2;
						idx--;
					}
					else{
						idx--;
						block[idx][i] = data;
					}

				}
			}
		}
	}
}


void dfs(int cnt){
	if(cnt == 5){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				result = max(result, block[i][j]);
			}
		}
		return;
	}

	int cpyblock[MAX][MAX];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cpyblock[i][j] = block[i][j];
		}
	}
	
	for(int i=0; i<4; i++){
		shift(i);
		dfs(cnt+1);

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				block[i][j] = cpyblock[i][j];
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin>>block[i][j];

	dfs(0);
	cout<<result<<endl;
	return 0;
}