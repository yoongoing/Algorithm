#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

int r,c,k;

int arr[101][101] = {0,};
int cnt[101] = {0,};


int sol(int count){
	int R = 3;
	int C = 3;
	
	while(1){
		if(arr[r][c] == k)
			break;
		if(count > 100)
			return -1;
		

		int MAX = -1;
		if(R>=C){
			for(int i=1; i<=R; i++){
				memset(cnt, 0, sizeof(cnt));

				for(int j=1; j<=C; j++){
					cnt[arr[i][j]]++;
				}
				
				vector<pair<int,int> > temp;
				for(int j=1; j<=100; j++){
					if(cnt[j] != 0)
						temp.push_back(make_pair(cnt[j], j));
				}

				sort(temp.begin(), temp.end());
		

				for(int j=1; j<=C; j++)
					arr[i][j] = 0;
				
				int idx = 1;
				for(int k=0; k<temp.size(); k++){
					arr[i][idx++] = temp[k].second;
					arr[i][idx++] = temp[k].first;
				}
				idx--;

				if(idx > MAX){
					MAX = idx;
				}
			}
			C = MAX;
		}
		else{
			for(int j=1; j<=C; j++){
				memset(cnt, 0, sizeof(cnt));

				for(int i=1; i<=R; i++){
					cnt[arr[i][j]]++;
				}

				vector<pair<int, int> > temp;
				
				for(int i=1; i<=100; i++){
					if(cnt[i] != 0){
						temp.push_back(make_pair(cnt[i], i));
					}
				}

				sort(temp.begin(), temp.end());

				for(int i=1; i<=R; i++)
					arr[i][j] = 0;

				int idx = 1;
				for(int k=0; k<temp.size(); k++){
					arr[idx++][j] = temp[k].second;
					arr[idx++][j] = temp[k].first;

				}
				idx--;

				if(idx > MAX){
					MAX = idx;
				}
			}
			R = MAX;
		}
		count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>r>>c>>k;

	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			int n;
			cin>>n;
			arr[i][j] = n;
		}
	}

	cout<<sol(0)<<"\n";
	return 0;
}