#include <cstdio>
int dp[1010];
int dp2[1010];
int main() {
    int i, n;
    int x;
    int ans = 0;
    int tmp;
    int m;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        dp[i] += dp[i-1] + x;
        dp2[i] += dp2[i-1] + dp[i];
    }
    m = n * dp[n];
    for(i=1;i<=n;i++) {
        tmp = dp2[n] - (dp[i-1] * (n-i+1)) - dp2[i-1];
        tmp += dp2[i-1] + ((dp[n] - dp[i-1]) * (i-1));
        if(tmp > ans) ans = tmp;
    }
    printf("%d\n",m-ans);
    return 0;
}