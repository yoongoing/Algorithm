#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L,C;
char alph[16];
int check[16] = {0,};

void dfs(int idx, int cnt){
	if(cnt == L){
		string str;
		int vowel = 0;
		int consonant = 0;

		for(int i=0; i<C; i++){
			if(check[i]){
				str += alph[i];
				if((alph[i]=='a') || (alph[i]=='i') || (alph[i]=='e') || (alph[i]=='o') || (alph[i]=='u'))
					vowel++;
				else
					consonant++;
			}
		}
		if((vowel<1) || (consonant<2))
			return;

		cout<<str<<"\n";
		return;
	}

	for(int i=idx+1; i<C; i++){
		if(check[i])
			continue;

		check[i] = 1;
		dfs(i, cnt+1);
		check[i] = 0;
	}
}


int main(int argc, char const *argv[])
{
	cin>>L>>C;

	for(int i=0; i<C; i++)
		cin>>alph[i];
	sort(alph,alph+C);
	dfs(-1, 0);
	return 0;
}