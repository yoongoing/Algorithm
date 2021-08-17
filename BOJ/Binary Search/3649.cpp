#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
ios_base::sync_with_stdio(0);
cin.tie(0);
int x;
while (cin >> x)
{
int n;
cin >> n;
vector<int> blocks(n);
for (int i = 0; i < n; i++)
{
cin >> blocks[i];
}
sort(blocks.begin(), blocks.end());
bool flag = false;
x *= 1e7;
for (int i = 0; i < n && blocks[i] <= x / 2; i++)
{
int low = i + 1, high = n - 1;
while (low <= high)
{
int mid = (low + high) / 2;
if (blocks[mid] + blocks[i] == x)
{
flag = true;
cout << "yes " << blocks[i] << " " << blocks[mid] << "\n";
break;
}
else if (blocks[mid] + blocks[i] < x)
{
low = mid + 1;
}
else
{
high = mid - 1;
}
}
if (flag)
{
break;
}
}
if (flag == false)
{
cout << "danger\n";
}
}
return 0;
}
