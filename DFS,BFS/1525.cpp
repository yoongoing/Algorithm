#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

string map = "";
string End = "123456780";

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int bfs(){
	queue<pair<string, int> > q;
	set<string> check;
	
	q.push(make_pair(map,0));
	check.insert(map);

	while(!q.empty()){
		string str = q.front().first; 	// 현재 string 상태
		int cnt = q.front().second;		// 현재 string까지 오는 count
		q.pop();

		if(str == End)
			return cnt;

		int y = str.find("0") / 3;
		int x = str.find("0") % 3;
		
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if((ny<0) || (nx<0) || (ny>=3) || (nx>=3))
				continue;

			string next = str;

			swap(next[y*3 + x], next[ny*3 + nx]);

			if(check.find(next) == check.end()){
				check.insert(next);
				q.push(make_pair(next,cnt+1));
			}
		}
	}
	return  -1;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++){
			char c;
			cin>>c;
			map += c;
		}

	int cnt = bfs();
	cout<<cnt<<"\n";

	return 0;
}