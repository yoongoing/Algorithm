#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	int cnt = 0;
	for(int i=0; i<N; i++){
		int n;
		cin>>n;

		vector<int> v;
		for(int j=1; j<=n; j++){
			if(n%j == 0)
				v.push_back(j);
		}
		
		if(v.size() == 2)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}