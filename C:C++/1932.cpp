#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int i, j, n, x;
    scanf("%d",&n);
    vector<vector<int> > dp(n+1);
    dp[0] = vector<int>(2, 0);
    for(i=1;i<=n;i++) {
        dp[i] = vector<int>(i+2, 0);
        for(j=1;j<=i;j++) {
            scanf("%d",&x);
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + x;
        }
    }
    int ans = 0;
    for(i=1;i<=n;i++) if(dp[n][i] > ans) ans = dp[n][i];
    printf("%d\n",ans);
    return 0;
}