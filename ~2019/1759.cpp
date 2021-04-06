#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void printing(vector<char> v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i];
	}

}
int main(int argc, char const *argv[])
{
	int L,C;
	vector<char> v;
	vector<int> d;
	
	cin>>L>>C;

	for(int i=0; i<C; i++) cin>>v[i];
	printf("2\n");
	for(int i=0; i<L; i++) d.push_back(1);
	printf("3\n");
	for(int i=0; i<C-L; i++) d.push_back(0);
	printf("4\n");
	do{
		vector<char> end;
		for(int i=0; i<d.size(); i++){
			if(d[i] == 1) {
				printf("5\n");
				end.push_back(v[i]);
			}
		}
		sort(end.begin(), end.end());
		printing(end);
		cout<<"\n";
	}while(prev_permutation(d.begin(), d.end()));
	return 0;
}