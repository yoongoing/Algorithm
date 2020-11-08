#include <iostream>

using namespace std;

int N,M;
int fr[2001];

int bfs()

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M;
	for(int i=0; i<M; i++){
		int a,b;
		cin>>a>>b;

		fr[a] = 1;
		fr[b] = 1;
	}

	return 0;
}