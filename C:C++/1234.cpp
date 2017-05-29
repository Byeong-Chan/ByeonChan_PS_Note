#include <cstdio>
long long dp[56][56][56];
long long fac[12];
int main() {
    int t, i, j, k, n;
    int r, g, b;
    int tmp;
    int sum = 0;
    long long s, ans = 0;
    scanf("%d",&n);
    scanf("%d %d %d",&r,&g,&b);
    dp[0][0][0] = 1;
    fac[0] = 1;
    for(i=1;i<=n;i++) fac[i] = i * fac[i-1];
    for(t=1;t<=n;t++) {
        for(i=0;i<=r;i++) {
            if(i > sum) break;
            for(j=0;j<=g;j++) {
                if(i+j > sum) break;
                for(k=0;k<=b;k++) {
                    if(i+j+k > sum) break;
                    if(i+j+k != sum) continue;
                    
                    // 1
                    if(i+t <= r) dp[i+t][j][k] += dp[i][j][k];
                    if(j+t <= g) dp[i][j+t][k] += dp[i][j][k];
                    if(k+t <= b) dp[i][j][k+t] += dp[i][j][k];
                    // 2
                    if(!(t & 1)) {
                        tmp = t / 2;
                        s = fac[t] / fac[tmp] / fac[tmp];
                        if(i+tmp <= r && j+tmp <= g) dp[i+tmp][j+tmp][k] += dp[i][j][k] * s;
                        if(i+tmp <= r && k+tmp <= b) dp[i+tmp][j][k+tmp] += dp[i][j][k] * s;
                        if(j+tmp <= g && k+tmp <= b) dp[i][j+tmp][k+tmp] += dp[i][j][k] * s;
                    }
                    // 3
                    if(!(t % 3)) {
                        tmp = t / 3;
                        s = fac[t] / fac[tmp] / fac[tmp] / fac[tmp];
                        if(i+tmp <= r && j+tmp <= g && k+tmp <= b) dp[i+tmp][j+tmp][k+tmp] += dp[i][j][k] * s;
                    }
                }
            }
        }
        sum += t;
    }
    for(i=0;i<=r;i++) {
        for(j=0;j<=g;j++) {
            for(k=0;k<=b;k++) {
                if(i+j+k != sum) continue;
                ans += dp[i][j][k];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}