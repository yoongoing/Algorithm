#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
	int y;
	int x;
	int age;
	int live;
}T;

bool cmp(T a, T b){
	return a.age < b.age;
}


int main(int argc, char const *argv[])
{
	vector<T> v;
	T t;
	t.y = 4;
	t.x = 5;
	t.age = 3;
	t.live = 9;
	v.push_back(t);
	
	t.y = 3;
	t.x = 6;
	t.age = 3;
	t.live = 10;
	v.push_back(t);

	t.y = 2;
	t.x = 7;
	t.age = 3;
	t.live = 1;
	v.push_back(t);

	t.y = 1;
	t.x = 8;
	t.age = 3;
	t.live = 2;
	v.push_back(t);
	sort(v.begin(),v.end(),cmp);

	for(int i=0; i<v.size(); i++){
		cout<<v[i].y<<", "<<v[i].x<<endl;
		cout<<"age: "<<v[i].age<<"live: "<<v[i].live<<"\n";
	}
	return 0;
}