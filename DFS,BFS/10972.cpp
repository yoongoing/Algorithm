#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	v.resize(n);

	for(int i=0; i<n; i++){
		cin>>v[i];
	}

	if(next_permutation(v.begin(),v.end())){
		for(int i=0; i<n; i++)
			cout<<v[i]<<" ";
		cout<<"\n";
	}
	else
		cout<<"-1\n";
	
	return 0;
}