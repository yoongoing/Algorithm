#include <iostream>
#include <queue>
#include <cstring>

#define MAX 22

using namespace std;

int N,M,K;

int map[MAX][MAX];
int people[MAX][MAX] = {0,};
int arrival[MAX][MAX] = {0,};

pair<int, int> taxi;
pair<int, int> next_people;
int cur_people;
pair<int, int> next_arrival;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int check(){
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(people[i][j] != 0) //사람이 있다면
				return 1;
	return 0;
}

int find(int y, int x, int kinda){
	queue<pair<int, int> > q;
	int cost[MAX][MAX];
	memset(cost, -1, sizeof(cost));

	q.push(make_pair(y,x));
	cost[y][x] = 0;

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 범위 밖이면 안됨
			if((ny<1) || (nx<1) || (ny>N) || (nx>N))
				continue;

			// 빈칸이면서 방문하지 않은곳은 됨
			if(map[ny][nx]==0 && cost[ny][nx]==-1){
				cost[ny][nx] = cost[y][x] + 1;
				q.push(make_pair(ny,nx));
			}
		}
	}

	int min_cost = 987654321;
	if(kinda == 1){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(people[i][j]!=0 && cost[i][j]!=-1){
					if(min_cost > cost[i][j]){
						min_cost = cost[i][j];
						next_people.first = i;
						next_people.second = j;
					}

					else if(min_cost == cost[i][j]){
						if(next_people.first > i){
							next_people.first = i;
							next_people.second = j;
						}
						else if(next_people.first == i){
							if(next_people.second > j)
								next_people.second = j;
						}
					}
				}
			}
		}	
	}
	else if(kinda == 2){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(arrival[i][j] == cur_people){
					next_arrival.first = i;
					next_arrival.second = j;
					return cost[i][j];
				}
			}
		}
	}

	return min_cost;
}

int sol(){
	while(1){
		int cost;
		
		// 현재 택시 좌표로부터 가장 가까운사람 찾고 cost 리턴
		cost = find(taxi.first, taxi.second, 1);
		if(cost == 987654321) //없거나 이동못한다는 소리 
			return -1;


		// 현재 연료보다 크면 -1 리턴
		if(cost > K)
			return -1;
		// cout<<next_people.first<<", "<<next_people.second<<"\t";

		// 아니면, 택시 좌표 업데이트하고, 연료도 업데이트, 사람이 있는 곳도 0
		taxi.first = next_people.first;
		taxi.second = next_people.second;
		cur_people = people[next_people.first][next_people.second];
		people[next_people.first][next_people.second] = 0;
		K -= cost;

		// 목적지까지 가는 최단거리 찾고 cost 리턴
		cost = find(taxi.first, taxi.second, 2);
	
		if(cost == 987654321) //이동 못한다는 소리 
			return -1;
		// 현재 연료보다 크면 -1 리턴
		if(cost > K)
			return -1;

		// cout<<next_arrival.first<<", "<<next_arrival.second<<"\n";

		// 아니면, 택시좌표 업데이트하고, 연료도 업데이트, 목적지가 있는곳도 0 
		taxi.first = next_arrival.first;
		taxi.second = next_arrival.second;
		arrival[next_arrival.first][next_arrival.second] = 0;
		K -= cost;

		// 목적지까지 가는연료*2 더해주기
		K += cost*2;

		// for(int i=1; i<=N; i++){
		// 	for(int j=1; j<=N; j++){
		// 		cout<<people[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M>>K;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin>>map[i][j];
		}
	}
	cin>>taxi.first>>taxi.second;

	for(int i=1; i<=M; i++){
		int fy,fx,ty,tx;
		cin>>fy>>fx>>ty>>tx;
		people[fy][fx] = i;
		arrival[ty][tx] = i;
	}
	int answer = sol();
	cout<<answer<<"\n";
	return 0;
}