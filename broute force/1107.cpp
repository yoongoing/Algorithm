#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>

using namespace std;

int channel,btn;
int button[10] = {1,1,1,1,1,1,1,1,1,1};
int mini = 0x3f3f3f3f;

int min(int a, int b){
	if(a < b) return a;
	return b;
}

void broute(string num){
	for(int i=0; i<10; i++){
		if(button[i]){
			string temp = num + to_string(i);
			mini = min(mini, abs(channel - stoi(temp))+ temp.length());
		
			if(temp.length() < 6)
				broute(temp);
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>channel>>btn;

	for(int i=0; i<btn; i++){
		int x;
		cin>>x;
		button[x] = 0;
	}	

	
	mini = min(mini, abs(100 - channel));

	if(btn < 10)
		broute("");
	
	cout<<mini;

	return 0;
}