#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int save_num = 0;
int f[4];


int clock_(int x){
	int min = x;
	for(int i=0; i<3; i++){
		x = (x%1000) * 10 + (x/1000);
		if(x < min) min = x;
	}
	return min;
}


int main(int argc, char const *argv[])
{
	cin>>f[0]>>f[1]>>f[2]>>f[3];	
	
	int c = clock_(f[0]*1000 + f[1]*100 + f[2]*10 + f[3]);
	int cnt = 0;
	for(int i=1111; i<=c; i++){
		if(clock_(i) == i) cnt++;
	}

	cout<<cnt;
	return 0;
}