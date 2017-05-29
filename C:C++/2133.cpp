#include <cstdio>
long long dp[33][6];
int main() {
    int i;
    int n;
    dp[0][0] = 1;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        dp[i][0] += dp[i-1][1] + dp[i-1][2] + dp[i-1][5];
        dp[i][1] += dp[i-1][4] + dp[i-1][0];
        dp[i][2] += dp[i-1][3] + dp[i-1][0];
        dp[i][3] += dp[i-1][2];
        dp[i][4] += dp[i-1][1];
        dp[i][5] += dp[i-1][0];
    }
    printf("%lld\n",dp[n][0]);
    return 0;
}


/*

 101 x
 000 0
 100 1
 001 2
 110 3
 011 4

*/