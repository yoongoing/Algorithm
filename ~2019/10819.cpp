#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int summation(vector<int> v){
	int sum = 0;
	
	for(int i=0; i<v.size()-1; i++){
		sum += abs(v[i] - v[i+1]);
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int N, total=0;
	cin>>N;

	vector<int> V(N);

	for (int i=0; i<N; i++) cin>>V[i];

	sort(V.begin(), V.end());

	while(next_permutation(V.begin(), V.end())){
		int temp = summation(V);
		total = max(total, temp);
	}
	cout<<total;

	return 0;
}