#include <cstdio>
long double dp[12], tmp[12];
int main() {
    int i, j, n, m, k;
    long double ans = 0;
    while(scanf("%d %d",&n,&m) == 2) {
        k = n + 1;
        for(i=0;i<=n;i++) dp[i] = 1/(long double)k;
        for(i=0;i<m-1;i++) {
            for(j=0;j<=n;j++) {
                tmp[j] = dp[j];
                dp[j] = 0;
            }
            for(j=0;j<=n;j++) {
                if(j-1 >= 0) dp[j - 1] += tmp[j] / k;
                dp[j] += tmp[j] / k;
                if(j+1 <= n) dp[j + 1] += tmp[j] / k;
            }
        }
        ans = 0.0;
        for(i=0;i<=n;i++) ans += dp[i];
        printf("%.5Lf\n",ans*100);
    }
    return 0;
}