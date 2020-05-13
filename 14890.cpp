#include <iostream>

using namespace std;
#define MAX 101

int N,L;
int stair[MAX*2][MAX];

int ans=0;
//0 은 세로 1은 가로
void sol(){
	int i,j;

	for(i=0; i<N*2; i++){
		int cnt  = 1;
		int temp = stair[i][0];

		for(j=0; j<N-1; j++){
			if(stair[i][j] == stair[i][j+1])	cnt++;
			
			else if(stair[i][j]+1 == stair[i][j+1] && cnt >= L){ 
				cnt = 1;
			}
			
			else if(stair[i][j]-1 == stair[i][j+1] && cnt >= 0){
				cnt = -L + 1;
			}
			
			else
				break; 

		}
		if(j == N-1 && cnt >= 0) ans++;
	}	
}

int main(int argc, char const *argv[])
{
	cin>>N>>L;

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin>>stair[i][j];
	//행을 transpose
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			stair[i+N][j] = stair[j][i];

	sol();
	cout<<ans<<endl;
	return 0;
}