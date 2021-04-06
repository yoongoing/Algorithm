#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int E,S,M;
	cin>>E>>S>>M;

	int year = 1;
	while(1){
		if(((year-E)%15==0) && ((year-S)%28==0) && ((year-M)%19==0))
			break;
		year++;
	}
	cout<<year<<"\n";
	return 0;
}