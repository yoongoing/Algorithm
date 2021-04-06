#include <iostream>
#include <vector>

using namespace std;
#define MAX 101

int N;
int num[MAX];
int opt[4]; //(+,0) (-,1) (*,2) (%,3)

int Max = -987654321;
int Min = 987654321;

void brute(int cnt_opt, int temp){
	if(N-1 == cnt_opt){
		if(Max < temp) Max = temp;
		if(Min > temp) Min = temp;
		return;
	}

	if(opt[0]){
		opt[0]--;
		brute(cnt_opt+1, temp+num[cnt_opt+1]);
		opt[0]++;
	}
	if(opt[1]){
		opt[1]--;
		brute(cnt_opt+1, temp-num[cnt_opt+1]);
		opt[1]++;
	}
	if(opt[2]){
		opt[2]--;;
		brute(cnt_opt+1, temp*num[cnt_opt+1]);
		opt[2]++;
	}
	if(opt[3]){
		opt[3]--;
		brute(cnt_opt+1, temp/num[cnt_opt+1]);
		opt[3]++;
	}
}

int main(int argc, char const *argv[])
{
	
	cin>>N;

	for(int i=0; i<N; i++)
		cin>>num[i];
	for(int i=0; i<4; i++)
		cin>>opt[i];
	
	brute(0,num[0]);
	cout<<Max<<endl<<Min<<endl;


	return 0;
}