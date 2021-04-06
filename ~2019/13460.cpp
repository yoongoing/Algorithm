#include <iostream>
#include <queue>

using namespace std;

int N,M;
int total = 987654321;
char map[11][11] = {0,};

pair <int, int> red;
pair <int, int> blue;
pair <int, int> hole;

int reverse_dir(int dir){
	if(dir == 0)	return 1;
	if(dir == 1)	return 0;
	if(dir == 2)	return 3; 
	if(dir == 3)	return 2;
	
	return 4;
}

void ball_checker(int dir, int check){
	if((dir==0) && (check==1))	blue.second += 1;
	if((dir==0) && (check==2))	red.second 	+= 1;

	if((dir==1) && (check==1))	blue.second -= 1;
	if((dir==1) && (check==2))	red.second 	-= 1;

	if((dir==2) && (check==1))	blue.first 	+= 1;
	if((dir==2) && (check==2))	red.first 	+= 1;

	if((dir==3) && (check==1))	blue.first 	-= 1;
	if((dir==3) && (check==2))	red.first 	-= 1;
}

int shift(int dir){

	// 0: normal, 1:red우선순위, 2:blue우선순위
	int check = 0;

	// left
	if(dir == 0){
		
		if((red.first==blue.first) && (red.second<blue.second))
			check = 1;
		else if((red.first==blue.first) && (red.second>blue.second))
			check = 2;

		// red
		for(int j=red.second-1; j>=0; j--){
			if(map[red.first][j] == '#')
				break;
			if(map[red.first][j] == 'O'){
				map[red.first][j+1] = '.';
				red.second = j;
				break;
			}

			map[red.first][j] = 'R';
			map[red.first][j+1] = '.';
			red.second = j;
			
		}
		// blue
		for(int j=blue.second-1; j>=0; j--){
			if(map[blue.first][j] == '#')
				break;
			if(map[blue.first][j] == 'O'){
				map[blue.first][j+1] = '.';
				blue.second = j;
				break;
			}

			map[blue.first][j] = 'B';
			map[blue.first][j+1] = '.';
			red.second = j;
		}
	}

	// right
	else if(dir == 1){

		if((red.first==blue.first) && (red.second<blue.second))
			check = 2;
		else if((red.first==blue.first) && (red.second>blue.second))
			check = 1;

		// red
		for(int j=red.second+1; j<M; j++){
			if(map[red.first][j] == '#')
				break;
			if(map[red.first][j] == 'O'){
				map[red.first][j-1] = '.';
				red.second = j;
				break;
			}
			
			map[red.first][j] = 'R';
			map[red.first][j-1] = '.';
			red.second = j;
		}
		// blue
		for(int j=blue.second+1; j<M; j++){
			if(map[blue.first][j] == '#')
				break;
			if(map[blue.first][j] == 'O'){
				map[blue.first][j] = '.';
				blue.second = j;
				break;
			}
			
			map[blue.first][j] = 'B';
			map[blue.first][j-1] = '.';
			red.second = j;
		}
	}

	// up
	else if(dir == 2){

		if((red.second==blue.second) && (red.first<blue.first))
			check = 1;
		else if((red.second==blue.second) && (red.first>blue.first))
			check = 2;

		// red
		for(int i=red.first-1; i>=0; i--){
			if(map[i][red.second] == '#')
				break;
			if(map[i][red.second] == 'O'){
				map[i+1][red.second] = '.';
				red.first = i;
				break;
			}
			
			map[i+1][red.second] = 'R';
			map[i+1][red.second] = '.';
			red.first = i;
		}
		// blue
		for(int i=blue.first-1; i>=0; i--){
			if(map[i][blue.second] == '#')
				break;
			if(map[i][blue.second] == 'O'){
				map[i+1][blue.second] = '.';
				blue.first = i;
				break;
			}

			map[i+1][blue.second] = 'B';
			map[i+1][blue.second] = '.';
			red.first = i;
		}
	}

	// down
	else if(dir == 3){
		if((red.second==blue.second) && (red.first<blue.first))
			check = 2;
		else if((red.second==blue.second) && (red.first>blue.first))
			check = 1;

		// red
		for(int i=red.first+1; i<M; i++){
			if(map[i][red.second] == '#')
				break;
			if(map[i][red.second] == 'O'){
				map[i-1][red.second] = '.';
				red.first = i;
				break;
			}

			map[i-1][red.second] = 'R';
			map[i-1][red.second] = '.';
			red.first = i;
		}
		// blue
		for(int i=blue.first+1; i<M; i++){
			if(map[i][blue.second] == '#')
				break;
			if(map[i][blue.second] == 'O'){
				map[i-1][blue.second] = '.';
				blue.first = i;
				break;
			}

			map[i-1][blue.second] = 'B';
			map[i-1][blue.second] = '.';
			red.first = i;
		}
	}

	return check;
}

// 0:left, 1:right, 2:up, 3:down, -1,4:first trial
void dfs(int cnt, int prev_dir){
	
	if((red.first==hole.first) && (red.second==hole.second)){
		total = min(total, cnt);
		return;
	}

	if(cnt > 10)
		return;

	cout<<red.first<<", "<<red.second<<endl;

	pair<int, int> cpy_red = red;
	pair<int, int> cpy_blue = blue;
	
	char cpy_map[11][11];

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cpy_map[i][j] = map[i][j];

	for(int i=0; i<4; i++){
		if((i!=reverse_dir(prev_dir)) && (i!=prev_dir)){
			// dir로 shift
			int check = shift(i);

			// 공의 우선순위 판단 후 좌표 재설정
			ball_checker(i, check);
			
			dfs(cnt+1, i);
			
			// 재귀니까 원상복
			for(int i=0; i<N; i++)
				for(int j=0; j<M; j++)
					map[i][j] = cpy_map[i][j];
			red = cpy_red;
			blue = cpy_blue;
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++){
			
			cin>>map[i][j];
			
			if(map[i][j] == 'R'){
				red.first = i;
				red.second = j;
			}
			
			else if(map[i][j] == 'B'){
				blue.first = i;
				blue.second = j;
			}
			
			else if(map[i][j] == 'O'){
				hole.first = i;
				hole.second = j;
			}
		}

	dfs(0,-1);
	
	if(total == 987654321)
		cout<<"-1"<<endl;
	else
		cout<<total<<endl;

	return 0;
}