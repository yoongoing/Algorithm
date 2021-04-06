#include <iostream>
#include <string>

#define MAX 1501
using namespace std;

int words[MAX][MAX];

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;

	for(int k=0; k<tc; k++){
		int len;
		cin>>len;

		for(int i=0; i<len; i++){
			string str;
			cin>>str;
			int size = str.size();
			for(int j=0; j<size; j++)
				words[i][j] = str[j];
		}

		
	}
	return 0;
}