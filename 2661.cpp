#include <stdio.h>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

int n;

stack<pair<int, int> > s;
vector<int> ans;
vector<int> col;
bool being(int temp){
	for(int i=0; i<col.size(); i++)
		if(col[i] == temp) return true;
	return false;
}
void dfs(int row){
	if(row+1 == n) return;
	//ans.push();
}

int main(int argc, char const *argv[])
{
	cin>>n;


	for(int i=0; i<n; i++){

	}	
	return 0;
}