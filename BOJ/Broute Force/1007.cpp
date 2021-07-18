#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<pair<int, int> > V;

int H, N;
int visited[21] = {0,};
pair<double, double> P;
double Min = 40000000007.0;

double cal(){
    double first=0.0, second=0.0;
    for(int i=0; i<V.size(); i++){
        if(visited[i]){
            first += V[i].first;
            second += V[i].second;
        }
        else{
            first -= V[i].first;
            second -= V[i].second;
        }
    }
    
    double result = sqrt((pow(first, 2) + pow(second, 2)));
    return result;
}

void dfs(int idx, int cnt){
    if(cnt == H){
        Min = min(Min, cal());
        return;
    }
    for(int i=idx+1; i<V.size(); i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i, cnt+1);
            visited[i] = 0;
        }
    }
}

void init(){
    V.clear();
    Min = 40000000007.0;
    P.first = 0.0;
    P.second = 0.0;
}

int main(void){
    int T;
    cin>>T;
    cout << fixed;
	cout.precision(12);
    for(int k=0; k<T; k++){
        cin>>N;
        H = N/2;
        for(int i=0; i<N; i++){
            double x1, y1;
            cin>>x1>>y1;
            V.push_back(make_pair(x1, y1));
        }
        dfs(-1, 0);

        cout<<Min<<"\n";
        init();
    }

    return 0;
}