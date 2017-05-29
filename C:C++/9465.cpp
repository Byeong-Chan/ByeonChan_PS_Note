#include <cstdio>
#include <algorithm>
using namespace std;
int o[100010][2];
int dp[100010][3];
int main() {
    int t, i, n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&o[i][0]);
        for(i=1;i<=n;i++) scanf("%d",&o[i][1]);
        
        for(i=1;i<=n;i++) {
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
            dp[i][1] = max(dp[i-1][0] + o[i][0], dp[i-1][2] + o[i][0]);
            dp[i][2] = max(dp[i-1][0] + o[i][1], dp[i-1][1] + o[i][1]);
        }
        printf("%d\n",max(dp[n][0], max(dp[n][1], dp[n][2])));
        for(i=1;i<=n;i++) dp[i][0] = dp[i][1] = dp[i][2] = 0;
    }
    return 0;
}