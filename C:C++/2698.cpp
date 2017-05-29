#include <cstdio>
long long dp[110][110][2];
int main() {
    int i, j, n, m;
    int t;
    dp[0][0][0] = 1;
    for(i=0;i<100;i++) {
        for(j=0;j<=100;j++) {
            dp[i+1][j][0] += dp[i][j][0] + dp[i][j][1];
            dp[i+1][j][1] += dp[i][j][0];
            dp[i+1][j+1][1] += dp[i][j][1];
        }
    }
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        if(m > n) printf("0\n");
        else printf("%lld\n",dp[n][m][0] + dp[n][m][1]);
    }
    return 0;
}