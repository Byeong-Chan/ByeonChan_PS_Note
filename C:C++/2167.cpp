#include <cstdio>
int dp[310][310];
int main() {
    int i, j, n, m;
    int stx, sty, edx, edy;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            scanf("%d",&dp[i][j]);
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    int Q;
    scanf("%d",&Q);
    for(i=0;i<Q;i++) {
        scanf("%d %d %d %d",&stx,&sty,&edx,&edy);
        printf("%d\n",dp[edx][edy] - dp[stx-1][edy] - dp[edx][sty-1] + dp[stx-1][sty - 1]);
    }
    return 0;
}