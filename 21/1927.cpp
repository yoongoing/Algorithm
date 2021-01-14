#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin>>N;

    priority_queue<int, vector<int>, greater<int> > pq;
    
    int command;
    for(int i=0; i<N; i++){
        cin>>command;

        if(command == 0){
            if(pq.empty())
                cout<<"0\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }  
        else{
            pq.push(command);
        }
    }
    return 0;
}