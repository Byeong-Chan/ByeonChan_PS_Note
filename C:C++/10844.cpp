#include <cstdio>

#define mod 1000000000

int dp[110][10];
int main() {
    int i, j, n;
    int ans = 0;
    scanf("%d",&n);
    for(i=1;i<10;i++) dp[0][i] = 1;
    for(i=1;i<n;i++) for(j=0;j<10;j++) {
        if(j-1 >= 0) dp[i][j] += dp[i-1][j-1];
        if(j+1 < 10) dp[i][j] += dp[i-1][j+1];
        dp[i][j] %= mod;
    }
    for(i=0;i<10;i++) {
        ans += dp[n-1][i];
        ans %= mod;
    }
    printf("%d\n",ans);
    return 0;
}