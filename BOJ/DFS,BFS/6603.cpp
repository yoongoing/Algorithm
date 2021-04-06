#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
	int n;

	while(true){
		cin>>n;
		vector<int> v(n);
		vector<int> d;
		if(n == 0) break;

		for(int i=0; i<n; i++) cin>>v[i];
		for(int i=0; i<6; i++) d.push_back(1);
		for(int i=6; i<n; i++) d.push_back(0);
		
		sort(v.begin(), v.end());
		do{
			for(int i=0; i<d.size(); i++){
				if(d[i] == 1) {cout<<v[i];  cout<<" ";}
			}
			cout<<"\n";
		}while(prev_permutation(d.begin(),d.end()));
		cout<<"\n";
	}
	return 0;
}
