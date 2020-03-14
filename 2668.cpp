#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int visited[100]={0,};
int arr[100];

void dfs(int i){
	//일단 방문한거니까 들렀다고 표시
	visited[i]++;
	//다음 노드의 인덱스를 저장
	int next = arr[i];
	
	//현재 노드 자체로 사이클중이라면
	if(i == next){
		//사이클노드라고 표시한 후 리턴
		visited[i] = 2;
		return;
	}
	//다음 노드가 사이클 노드가 아니라면 dfs함수에 넣음
	if(visited[next] == 0 || visited[next] == 1) dfs(next);
	// else if(visited[next] == 0) visited[i] = 0;
	//현재 노드가 사이클 노드라면 리턴
	if(visited[i] == 2) return;
	//아니라면 0으로 초기화
	else visited[i] = 0;
}

int main(int argc, char const *argv[])
{
	int N, cnt=0;
	cin>>N;

	for(int i=1; i<=N; i++){
		cin>>arr[i];
	}

	for(int i=1; i<=N; i++){
		if(visited[i] == 0) dfs(i);
	}
	
	for(int i=1; i<=N; i++){
		if(visited[i] == 2){
			cnt++;
		}
	}
	
	cout<<cnt<<endl;

	for(int i=1; i<=N; i++){
		if(visited[i] == 2){
			cout<<i<<endl;
		}
	}
	return 0;
}