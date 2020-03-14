#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int arr[10][2] = {{7,1},{2,9},{3,9},{3,4},{7,5},{6,5},{3,8},{9,8},{7,1},{9,9}};
	int current = 0;
	string s;

	cin>>s;
	int len = s.length();

	for(int i=0; i<len; i++){
		int ch = s[i] - '0';
		current = arr[current][ch];
	}

	if(current == 4 || current == 5 || current == 8){
		cout<<"SUBMARINE";
	}
	else cout<< "NOISE";

	return 0;
}