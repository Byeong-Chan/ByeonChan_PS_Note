#include <cstdio>
long long dp[93][2];
int main() {
    int i, n;
    dp[1][1] = 1;
    scanf("%d",&n);
    for(i=2;i<=n;i++) {
        dp[i][0] += dp[i-1][1] + dp[i-1][0];
        dp[i][1] += dp[i-1][0];
    }
    printf("%lld\n",dp[n][0] + dp[n][1]);
    return 0;
}