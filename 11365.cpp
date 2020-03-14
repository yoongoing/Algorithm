#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	string print;
	char data[501];
	while(1){
		cin.getline(data,500);
		print = data;
		if(print == "END") break;
		reverse(print.begin(), print.end());
		printf("%s\n",print.c_str());	
	}
	
	return 0;
}