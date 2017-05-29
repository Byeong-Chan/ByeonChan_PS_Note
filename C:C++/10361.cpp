#include <cstdio>
#define mod 1000000007
int dp[1010], tmp[1010];
int main() {
    int i, j, n, m;
    int t, te;
    int cnt;
    int x;
    for (te=1, scanf("%d",&t);te <=t;te++) {
        scanf("%d %d",&n,&m);
        cnt = 0;
        for(i=0;i<n;i++) {
            scanf("%d",&x);
            if (x == 1) cnt++;
        }
        dp[cnt] = 1;
        for(i=0;i<m;i++) {
            for(j=0;j<=n;j++) {
                tmp[j] = dp[j];
                dp[j] = 0;
            }
            for (j=0;j<=n;j++) {
                if (j-1 >= 0) {
                    dp[j-1] += ((long long)tmp[j] * j) % mod;
                    dp[j-1] %= mod;
                }
                if (j+1 <= n) {
                    dp[j+1] += ((long long)tmp[j] *  (n - j)) % mod;
                    dp[j+1] %= mod;
                }
            }
        }
        printf("Case #%d: %d\n",te,dp[0]);
        for (i=0;i<=n;i++) dp[i] = tmp[i] = 0;
    }
    return 0;
}