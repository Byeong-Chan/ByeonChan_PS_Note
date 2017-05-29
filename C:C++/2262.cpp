#include <cstdio>
#include <algorithm>
using namespace std;
int dp[260][260];
int mini[260][260];
int o[260];
int Abs(int a) {
    if (a < 0) return -a;
    return a;
}
int main() {
    int i, j, k;
    int l, r;
    int n;
    int x;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&o[i]);
    for(i=0;i<n;i++) {
        for(j=i;j<n;j++) mini[i][j] = dp[i][j] = 0x7fffffff;
        dp[i][i] = 0;
        mini[i][i] = o[i];
    }
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    for (i=2;i<=n;i++) {
        for (j=0;j<=n-i;j++) {
            l = j;
            r = j+i-1;
            mini[l][r] = mini[l][l];
            for(k=l+1;k<=r;k++) {
                x = dp[l][k-1] + dp[k][r] + Abs(mini[l][k-1] - mini[k][r]);
                dp[l][r] = min(x, dp[l][r]);
                mini[l][r] = min(mini[l][r], mini[l][k-1]);
                mini[l][r] = min(mini[l][r], mini[k][r]);
            }
        }
    }
    printf("%d\n",dp[0][n-1]);
    return 0;
}