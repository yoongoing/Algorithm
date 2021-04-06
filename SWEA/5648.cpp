#include <iostream>
#include <vector>

using namespace std;
#define BASE 1000
#define MAX 4001


typedef struct
{
    int x;
    int y;
    int dir;
    int E;
    int stat;
}Atom;

int map[MAX][MAX];
vector <Atom> atoms;
int K = 0;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1};

bool check(int y, int x){
    if(y<0 || x<0 || y>4000 || x>4000)
        return true;
    return false;
}

void simulator(){
    while(!atoms.empty()){
        int size = atoms.size();
        //원자 이동
        for(int i=0; i<size; i++){
            map[atoms[i].y][atoms[i].x] = 0;

            int dir = atoms[i].dir;
            int nx = atoms[i].x + dx[dir];
            int ny = atoms[i].y + dy[dir];
            
            //범위를 벗어나면 소멸
            if(check(ny,nx)){
                atoms[i].stat = 0;
                continue;
            }
            
            //좌표 재설정
            atoms[i].x = nx;
            atoms[i].y = ny;
            
            //현재 원소의 좌표에 원소의 에너지 표시
            map[ny][nx] += atoms[i].E;
        }

        //충돌확인
        for(int i=0; i<size; i++){
            if(atoms[i].stat == 0)
                continue;
            if(map[atoms[i].y][atoms[i].x] != atoms[i].E){
                K += map[atoms[i].y][atoms[i].x];
                map[atoms[i].y][atoms[i].x] = 0;
                atoms[i].stat = 0;
            }      
        }

        vector<Atom> temp;
        temp.assign(atoms.begin(),atoms.end());
        atoms.clear();
        //범위 밖에 원소 제거
        for(int i=0; i<size; i++)
            if(temp[i].stat != 0)
                atoms.push_back(temp[i]);
    }    
}

int main(){
    int test_case;
    cin>>test_case;

    for(int T=1; T<=test_case; T++){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            Atom atom;
            cin>>atom.x>>atom.y>>atom.dir>>atom.E;
            atom.x += BASE;
            atom.y += BASE;
            atom.x *= 2;
            atom.y *= 2;
            atom.stat = 1;
            atoms.push_back(atom);
        }
        simulator();
        cout<<"#"<<T<<" "<<K<<endl;
        K = 0;
    }
    return 0;
}ㄴ