
// #include <cstring>
// #include <iostream>
// #include <math.h>
// using namespace std;
// int N,K;
// int total = 0;

// int divider(int s){
// 	// int total = 0;
// 	int temp;
// 	// int flag = 0;
	

// 	int quo, remain;
// 	quo = s/2;
// 	remain = s%2;

// 	//cout<<"1 quo: "<<quo<<endl;
// 	if(N == s) return s;

// 	if(N*2 >= s){
// 		// flag = 1;
// 		total += abs(quo-N);
// 	}
// 	else{
// 		temp = divider(quo);
// 		int i;
// 		cout<<"temp: "<<temp<<endl;
// 		for(i=0;; i++){
// 			temp *= 2;
// 			if(temp > s) break;
// 			cout<<"["<<i<<"]"<<temp<<" "<<endl;

// 		}
// 		cout<<i<<endl;
// 		total += i;
// 	}
	
// 	if(remain != 0) total+=1;
// 	cout<<"total is = "<<total<<endl;
// 	return quo;
// }

// int main(int argc, char const *argv[])
// {

// 	cin>>N>>K;
// 	divider(K);
// 	cout<<total;


// 	return 0;
// }


#include <cstring>
#include <iostream>
#include <queue>

int N,K;
using namespace std;
bool check[200002] = {0,};


int calculator(int next,int temp){
	if(next == 0) return temp-1;
	else if(next == 1) return temp+1;
	return 2*temp;
}

void bfs(int n){
	queue <int> q;
	q.push(n);
	int total = 0;
	int k=0;
	while(!q.empty()){
		k++;
		int size = q.size();

		for(int i=0; i<size; i++){
			int temp = q.front();
			if(temp == K) {
				cout<<total<<endl;
				return;
			}
			
			q.pop();

			if(check[temp]) continue;
		
			check[temp] = true;
			for(int j=0; j<3; j++){
				int next = calculator(j,temp);
				if(next>=0 && next<200002) {
					q.push(next);
				}
			}
		}
		total++;
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>K;
	bfs(N);

	return 0;
}






