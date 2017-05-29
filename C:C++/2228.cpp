#include <cstdio>
#include <algorithm>

using namespace std;

int dp[110][110][2];
int main() {
    int i, j, n, m;
    int x;
    scanf("%d %d",&n,&m);
    for(i=0;i<=n;i++) {
        for(j=0;j<=m;j++) {
            dp[i][j][0] = dp[i][j][1] = -0x7fffffff;
        }
        dp[i][0][0] = 0;
    }
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        for(j=0;j<=m;j++) {
            if(dp[i-1][j][0] != -0x7fffffff) {
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);
                dp[i][j+1][1] = max(dp[i][j+1][1], dp[i-1][j][0] + x);
            }
            if(dp[i-1][j][1] != -0x7fffffff) {
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][1]);
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + x);
            }
        }
    }
    printf("%d\n",max(dp[n][m][0], dp[n][m][1]));
    return 0;
}