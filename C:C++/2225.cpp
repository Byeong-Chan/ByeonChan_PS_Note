#include <cstdio>
#define mod 1000000000
int dp[210], tmp[210];
int main() {
    int i, j, l;
    int n, k;
    scanf("%d %d",&n,&k);
    dp[0] = 1;
    for (i=0;i<k;i++) {
        for(j=0;j<=n;j++) {
            tmp[j] = dp[j];
            dp[j] = 0;
        }
        for (j=0;j<=n;j++) {
            for (l=0;l<=n;l++) {
                if (j+l > n) continue;
                dp[j+l] += tmp[j];
                dp[j+l] %= mod;
            }
        }
    }
    printf("%d",dp[n]);
    return 0;
}