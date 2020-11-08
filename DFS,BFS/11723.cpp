#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	bool visit[21];
	for(int i=0; i<n; i++){
		
		string str;
		cin>>str;

		if(str == "add"){
			int key;
			cin>>key;

			visit[key] = true;
		}
		else if(str == "remove"){
			int key;
			cin>>key;
			visit[key] = false;
		}
		else if(str == "check"){
			int key;
			cin>>key;

			if(visit[key])
				cout<<"1\n";
			else
				cout<<"0\n";
		}
		else if(str == "toggle"){
			int key;
			cin>>key;

			if(visit[key])
				visit[key] = false;
			else
				visit[key] = true;
		}
		else if(str == "all"){
			for(int i=1; i<=20; i++)
				visit[i] = true;
		}
		else if(str == "empty"){
			for(int i=1; i<=20; i++)
				visit[i] = false;	
		}
	}

	return 0;
}