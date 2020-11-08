#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int cal(){
	int sum = 0;

	for(int i=0; i<n-1; i++)
		sum += abs(v[i] - v[i+1]); 

	return sum;
}

int main(int argc, char const *argv[])
{	
	cin>>n;
	v.resize(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
	}

	sort(v.begin(), v.end());

	int max = -1;
	do{
		int sum = cal();
		
		if(sum > max)
			max = sum;
	}while(next_permutation(v.begin(), v.end()));
	
	cout<<max<<"\n";
	return 0;
}