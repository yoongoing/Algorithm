#include <algorithm>
#include <iostream>

using namespace std;
 
#define INF 987654321987654321
 
int N, D;
long long a[100000], dp[100000], tree[262144];
void update(int index, int S, int E, int k, long long var)
{
    if (S == E)
    {
        tree[index] = var;
        return;
    }
    if (k <= (S + E) / 2)
        update(index * 2, S, (S + E) / 2, k, var);
    else
        update(index * 2 + 1, (S + E) / 2 + 1, E, k, var);
    tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
}
 
long long find(int index, int S, int E, int i, int j)
{
    // printf("index:%d, start :%d, end:%d, i:%d, j:%d\n", index, S, E, i, j);
    if (i > E || j < S)
        return -INF;
    if (i <= S && j >= E)
        return tree[index];
    return max(find(index * 2, S, (S + E) / 2, i, j), find(index * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
 
int main()
{
    cin >> N >> D;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < N; i++)
    {
        dp[i] = a[i];
        dp[i] = max(dp[i], a[i] + find(1, 0, N - 1, max(0, i - D), i - 1));
        // cout<<"\n";
        update(1, 0, N - 1, i, dp[i]);
    }
    sort(dp, dp + N);
    cout<<dp[N-1]<<"\n";
}