#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int map[9][9];
int check[9][9];

int sudoku(int i, int j){
	
}
int main(void)
{
	for(int i=0; i<9; i++){
		for(int i=0; i<9; i++){
			cin>>map[i][j];
			if(map[i][j] != 0) 
				check[i][map[i][j]-1] = 1; 
		}
	}

	for(int i=0; i<9; i+=3){
		for(int j=0; j<9; j+=3)
			sudoku(i,j);
	}


	return 0;
}