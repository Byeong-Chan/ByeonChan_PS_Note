#include <cstdio>
long long dp[23][23][23];
long long fac[23][23];
int main() {
    int i, j, k, l, n;
    int x, y;
    int t;
    scanf("%d",&t);
    for(i=19;i>=0;i--) {
        fac[i][0] = 1;
        for(j=1;j<=i;j++) fac[i][j] = fac[i][j-1] * (i-j+1);
    }
    while(t--) {
        scanf("%d %d %d",&n,&x,&y);
        dp[0][1][1] = 1;
        for(i=0;i<n-1;i++) {
            for(j=i+1;j<n;j++) {
                for(k=1;k<=x;k++) {
                    for(l=1;l<=y;l++) {
                        if(k+1 <= x) dp[j][k+1][l] += dp[i][k][l] * fac[n-i-2][j-i-1];
                        if(l+1 <= y) dp[j][k][l+1] += dp[i][k][l] * fac[n-i-2][j-i-1];
                    }
                }
            }
        }
        printf("%lld\n",dp[n-1][x][y]);
        for(i=0;i<n;i++) {
            for(j=1;j<=x;j++) {
                for(k=1;k<=y;k++) {
                    dp[i][j][k] = 0;
                }
            }
        }
    }
    return 0;
}