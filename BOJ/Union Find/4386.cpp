#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<double, double> > v;
vector<pair<double, pair<int, int> > > info;
int root[10010] = {0,};
int N;

double calculate(double x1, double y1, double x2, double y2){
    double dx = (x1 - x2) * (x1 - x2);
    double dy = (y1 - y2) * (y1 - y2);
    double dist = sqrt(dx + dy);

    return dist;
}

int find(int n){
    if(root[n] == n)
        return n;
    return root[n] = find(root[n]);
}

void my_union(int a, int b){
    a = find(a);
    b = find(b);
    root[b] = a;
}

int compare(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b)
        return 1;
    return 0;
}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=0; i<N; i++){
        double a,b;
        cin>>a>>b;

        v.push_back(make_pair(a,b));
        root[i] = i;
    }

    for(int i=0; i<v.size(); i++){
        double x1 = v[i].first;
        double y1 = v[i].second;

        for(int j=i+1; j<v.size(); j++){
            double x2 = v[j].first;
            double y2 = v[j].second;

            double dist = calculate(x1, y1, x2, y2);
            info.push_back(make_pair(dist, make_pair(i,j)));
        }
    }

    sort(info.begin(), info.end());

    double ans;
    for(int i=0; i<info.size(); i++){
        double dist = info[i].first;
        int i_idx = info[i].second.first;
        int j_idx = info[i].second.second;

        if(!compare(i_idx, j_idx)){
            my_union(i_idx, j_idx);
            ans += dist;
        }
    }
    cout<<ans<<"\n";
    return 0;
}