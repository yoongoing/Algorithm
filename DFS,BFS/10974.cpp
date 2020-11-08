#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	vector<int> v;
	v.resize(n);

	for(int i=1; i<=n; i++)
		v[i-1] = i;

	for(int i=0; i<n; i++)
		cout<<v[i]<<" ";
	cout<<"\n";
	while(next_permutation(v.begin(), v.end())){
		for(int i=0; i<n; i++){
			cout<<v[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}