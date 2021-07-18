#include <iostream>

using namespace std;
 
int F(int i, int j) {
    int n = max(abs(i), abs(j));
    int val = (2 * n + 1);
    val *= val;
 
    int diff = 2 * n;
    if (i == n)return val - (n - j);
    val -= diff;
    if (j == -n)return val - (n - i);
    val -= diff;
    if (i == -n)return val - (j + n);
    val -= diff;
    return val - (i + n);
}
 
int G(int val) {
    return val ? G(val / 10) + 1 : 0;
}
 
int main(void) {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
 
    int k=0;
    for (int i=r1; i<=r2; ++i)
        for (int j=c1; j<=c2; ++j)
            k = max(k, G(F(i,j)));
 
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j)
            printf("%*d ", k, F(i, j));
        cout<<"\n";
    }
}
