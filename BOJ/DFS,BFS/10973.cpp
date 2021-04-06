#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	vector<int> v;
	v.resize(n);

	for(int i=0; i<n; i++)
		cin>>v[i];

	if(prev_permutation(v.begin(), v.end())){
		for(int i=0; i<n; i++)
			cout<<v[i]<<" ";
		cout<<"\n";
	}
	else
		cout<<"-1\n";

	return 0;
}