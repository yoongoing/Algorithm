#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

string N;
int M,K;

int cache[1000001][11];

string swap(string str, int i, int j){
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;

	return str;
}

int dfs(int cnt, string str, int result){
	if (cnt == K){
		return atoi(str.c_str());
	}
	
	if(cache[atoi(str.c_str())][cnt] != -1)
		return cache[atoi(str.c_str())][cnt];

	for(int i=0; i<M-1; i++){
		for(int j=i+1; j<M; j++){

			if(i==0 && str[j]=='0')
				continue;

			str = swap(str,i,j);
			result = max(result, dfs(cnt+1, str, result));
			str = swap(str,i,j); //재귀라서 원상복귀
		}
	}
	cache[atoi(str.c_str())][cnt] = result; //메모제이션 
	
	return result;

}

int main(int argc, char const *argv[])
{
	cin>>N>>K;
	M = N.length();

	memset(cache,-1,sizeof(cache));
	
	cout<<dfs(0,N,-1)<<endl;

	return 0;
}