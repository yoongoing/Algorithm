#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int X,Y;
char map[100][100];
bool check[26];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int maxi = 0;

int DFS(int y, int x,int chk)
{
    // 사용한 알파벳 체크
    chk_alpha[chk-'A'] = true;

    int ans = 0;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k]; int ny = y + dy[k];

        if (0 <= ny && ny < Y && 0 <= nx && nx < X)
        {
            int next = map[ny][nx];
            // 다른 알파벳을 가진 판이면 방문한다.
            if (chk_alpha[next-'A']==false)
            {
                chk_alpha[next - 'A'] = true;
                // 최대값만 저장
                ans = max(ans,DFS(ny, nx,next));
                // 백트래킹
                chk_alpha[next - 'A'] = false;
            }
        }
    }

    return ans+1;
}
int main(void){
	string str;
	cin>>Y>>X;

	for(int i=0; i<Y; i++){
		cin>>str;
		for(int j=0; j<X; j++){
			map[i][j] = str.at(j);
		}
	}

	dfs(0,0, 1);
	cout<<maxi;
}