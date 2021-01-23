#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100010

int N,M;


struct MergeSort{
    int arr[MAX];
    vector<int> seg[MAX*4+1];

    void init(int node, int left, int right){
        // 리프노드라면
        if(left == right){
            seg[node].push_back(arr[left]);
            return; 
        }

        // 구간설정해주고
        int mid = (left + right) / 2;
        init(node*2, left, mid);
        init(node*2+1, mid+1, right);

        // 머지!
        vector<int> &left_temp = seg[node*2];
        vector<int> &right_temp = seg[node*2+1];
        merge(left_temp.begin(), left_temp.end(), right_temp.begin(), right_temp.end(), back_inserter(seg[node]));
    }


    int query(int node, int left, int right, int qLeft, int qRight, int value){
        // 구간에 완벽하게 포함되지 않는다면
        if(right < qLeft || qRight < left)
            return 0;
        
        // 겹치는게 있다면
        if(left <= qLeft && qRight <= right){
            int result = seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), value);
            return result;
        }
            

        int mid = (qLeft + qRight) / 2;
        return query(node*2, left, right, qLeft, mid, value)\
                + query(node*2+1, left, right, mid+1, right, value);
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 수열의 크기 N
    cin>>N;

    MergeSort *mg = new MergeSort();
    // A1, A2, ..., AN
    for(int i=0; i<N; i++)
        cin>>mg->arr[i];

    // 트리 초기화
    mg->init(1, 0, N-1);
    
    // 쿼리의 개수 M
    cin>>M;

    int lastAns = 0;
    // M개의 줄에는 a, b, c
    for(int i=0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;

        lastAns = \
        mg->query(1, 0, N-1, (a^lastAns)-1, (b^lastAns)-1, c^lastAns);
        cout<<lastAns<<"\n";
    }
    return 0;
}