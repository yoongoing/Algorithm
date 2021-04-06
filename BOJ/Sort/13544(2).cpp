#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100000;
int arr[MAX];
vector<int> seg[MAX*4+1];
void init(int l, int r, int node){
	if(l==r){
		seg[node].push_back(arr[l]);
		return;
	}
	int mid = (l+r)/2;
	init(l,mid,node*2), init(mid+1,r,node*2+1);
	auto &left = seg[node*2], &right = seg[node*2+1];
	//두 구간을 merge sort로 합쳐준다.
	merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(seg[node]));
}
//구간 [l:r]에서 value보다 큰 원소의 개수를 리턴한다.
int query(int value, int l, int r, int node, int nodeL, int nodeR){
	if(r<nodeL || nodeR<l) return 0;
	//겹치는 부분이면 upper_bound로 arr[r]보다 큰 원소의 개수를 구할 수 있다.
	if(l <= nodeL && nodeR <= r)
		return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), value);
	int mid = (nodeL + nodeR)/2;
	return query(value,l,r,node*2,nodeL,mid)+query(value,l,r,node*2+1,mid+1,nodeR);
}
int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);
	int n,m,lastAns=0;
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	init(0, n-1, 1);
	cin >> m;
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		lastAns = query(c^lastAns,(a^lastAns)-1,(b^lastAns)-1,1,0,n-1);
		cout << lastAns << '\n';
	}
}