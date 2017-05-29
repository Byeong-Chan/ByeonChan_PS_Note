#include <cstdio>
int tmp[3];
int dp[3];
int main() {
    int i, j;
    int n;
    scanf("%d",&n);
    dp[0] = 1;
    for(i=0;i<n;i++) {
        for (j=0;j<3;j++) {
            tmp[j] = dp[j];
            dp[j] = 0;
        }
        dp[0] += tmp[0] + tmp[1] + tmp[2];
        dp[1] += tmp[0] + tmp[2];
        dp[2] += tmp[0] + tmp[1];
        dp[0] %= 9901;
        dp[1] %= 9901;
        dp[2] %= 9901;
    }
    printf("%d\n",(dp[0]+dp[1]+dp[2])%9901);
    return 0;
}