#include <cstdio>
long long dp[410][410];
long long tmp[410][410];
int main() {
    int i, j, k, n;
    int x, y;
    dp[200][200] = 1;
    scanf("%d",&n);
    for(k=0;k<n;k++) {
        scanf("%d %d",&x,&y);
        for(i=0;i<=400;i++) {
            for(j=0;j<=400;j++) {
                tmp[i][j] = dp[i][j];
                dp[i][j] = 0;
            }
        }
        for(i=0;i<=400;i++) {
            for(j=0;j<=400;j++) {
                if (tmp[i][j] == 0) continue;
                dp[i][j] += tmp[i][j];
                dp[i+x][j+y] += tmp[i][j];
            }
        }
    }
    printf("%lld",dp[200][200] - 1);
    return 0;
}