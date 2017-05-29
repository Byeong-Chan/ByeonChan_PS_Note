#include <cstdio>
int dp[210];
int o[210];
int main() {
    int i, j, n;
    int max1;
    int ans = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&o[i]);
        max1 = 0;
        for(j=0;j<i;j++) {
            if(o[i] < o[j]) continue;
            if(max1 < dp[j]) max1 = dp[j];
        }
        max1++;
        dp[i] = max1;
        if(ans < max1) ans = max1;
    }
    printf("%d",n - ans);
    return 0;
}