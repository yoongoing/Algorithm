#include <string>
#include <iostream>
#include <map>

#define MAX 28
using namespace std;



string sol(string str, int n, int k){
	map<string, int> words;
	int side = n/4;
	

	for(int i=0; i<side; i++){	
		int j;
		for(j=0; j<n;   ){
			int k;
			string str_4N = "";

			for(k=j; k<j+side; k++){
				str_4N += str[k];
			}
			if(words[str_4N] != 1)
				words[str_4N] = 1;

			j += side;
		}

		char temp = str[n-1];
		char prev = str[0];
		for(j=1; j<n; j++){
			int curr = str[j];
			str[j] = prev;
			prev = curr;
		}
		str[0] = temp;
	}
	
	int size = words.size();
	int cnt = 1;
	for(auto it = words.begin(); it != words.end(); it++){
		if((size-k+1) == cnt)
			return it->first;
		cnt++;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	for(int testcase=0; testcase<t; testcase++){
		int n,k;
		cin>>n>>k;

		string str;
		cin>>str;

		string ans;
		ans = sol(str,n,k);

		char F[MAX];
		for(int i=0; i<n/4; i++)
			F[i] = ans[i];

		int nDec = (int)strtol(F, NULL, 16);
		cout<<"#"<<testcase+1<<" "<<nDec<<endl;
	}
	return 0;
}