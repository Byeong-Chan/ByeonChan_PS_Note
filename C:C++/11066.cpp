#include <cstdio>
#include <algorithm>

using namespace std;

const long long INF = (long long)0x7fffffff << 30;
long long dp[510][510];
int sum[510];
int o[510];
int main() {
    int i, j, k, n;
    int t;
    int st, ed;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                dp[i][j] = INF;
            }
            scanf("%d",&o[i]);
            dp[i][i] = 0;
            sum[i] = sum[i-1] + o[i];
        }
        for(i=1;i<=n-1;i++) {
            for(j=1;j<=n;j++) {
                st = j;
                ed = i+j;
                if(ed > n) continue;
                for(k=st;k<ed;k++) {
                    if(dp[st][k] == INF || dp[k+1][ed] == INF) continue;
                    
                    long long tmp = dp[st][k] + dp[k+1][ed] + sum[ed] - sum[st-1];
                    dp[st][ed] = min(dp[st][ed], tmp);
                }
            }
        }
        printf("%lld\n",dp[1][n]);
    }
    return 0;
}