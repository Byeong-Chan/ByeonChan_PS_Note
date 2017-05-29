#include <cstdio>
int dp[1010];
int main() {
    int i;
    int n;
    dp[0] = 1;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        dp[i] += dp[i-1] + (i-2 >= 0 ? dp[i-2] : 0) * 2;
        dp[i] %= 10007;
    }
    printf("%d\n",dp[n]);
    return 0;
}