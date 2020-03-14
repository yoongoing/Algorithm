#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;

int matrix[11][11];

vector<pair<int, int> > point;
vector<int> row;
vector<int> column;

void check_Row(){
	int last = -1;
	for (int i=0; i<10; i++){
		int cnt = 0;
		for(int j=0; j<10; j++){
			if(matrix[j][i] == 1){
				cnt+=matrix[j][i];
				last = j;
			}
		}
		if(cnt == 1){
			point.push_back(make_pair(last,i));
		} 
		if(cnt!= 0) row.push_back(cnt); 
	}
}

void check_Column(){
	int last = -1;
	for (int i=0; i<10; i++){
		int cnt = 0;
		for(int j=0; j<10; j++){
			if(matrix[i][j] == 1){
				cnt+=matrix[i][j];
				last = j;
			}
		}
		if(cnt == 1)
			point.push_back(make_pair(i,last)); 
		if(cnt!= 0) column.push_back(cnt); 
	}
}

int is_True(){
	int temp;
	
	temp = abs(row[0] - row[1]);
	if(!(temp == 1 || temp ==2)){
		return 0;
	}
	for(size_t i=1; i<row.size(); i++){
		if(temp != abs(row[i-1] - row[i])) {
			return 0;
		}
	}
	

	temp = abs(column[0] - column[1]);
	if(!(temp == 1 || temp ==2)){
		return 0;
	}
	for(size_t i=1; i<column.size(); i++){
		if(temp != abs(column[i-1] - column[i])) {
			return 0;
		}
	}
	return 1;
}


int main(int argc, char const *argv[])
{
	string str;
	for(int i=0; i<10; i++){
		cin >>str;
		for(int j=0; j<10; j++)
			matrix[i][j]= str[j] -'0';
	}
	
	check_Row();
	check_Column();
	

	if(is_True() == 0) cout<<"0"<<endl;
	else{
		if(point.size() == 2)
			point.push_back(make_pair(point[0].first,point[1].second)); 
		sort(point.begin(),point.end());
		for(size_t i=0; i<point.size(); i++)
			cout<<point[i].first+1<<" "<<point[i].second+1<<endl;
	}

	return 0;
}