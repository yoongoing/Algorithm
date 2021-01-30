#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin>>N;

    priority_queue<int, vector<int>, less<int> > pq;
    for(int i=0; i<N; i++){
        int command;
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