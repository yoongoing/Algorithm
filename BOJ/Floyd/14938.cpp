#define MAX 987654321
#include <iostream>
#include <algorithm>
using namespace std;
int node, d, road, a, b, val, result = 0;
int item[101];
int arr[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> d >> road;
	for (int i = 1; i <= node; i++)
		cin >> item[i];
	for (int i = 1; i <= node; i++) 
		for (int j = 1; j <= node; j++) 
			if(i!=j)	arr[i][j] = MAX;
	for (int i = 0; i < road; i++) {
		cin >> a >> b >> val;
		arr[a][b] = val;
		arr[b][a] = val;
	}	
	for (int k = 1; k <= node; k++) 
		for (int i = 1; i <= node; i++) 
			for (int j = 1; j <= node; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];

	for (int i = 1; i <= node; i++) {
		int temp = 0;
		for (int j = 1; j <= node; j++)
			if (arr[i][j] <= d)
				temp += item[j];
		result = max(result, temp);
	}
	cout << result;
	return 0;
}