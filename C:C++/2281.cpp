#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1010];
int sum[1010];
int main() {
    int i, j, n, m;
    int tmp;
    int ans = 0x7fffffff;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) {
        scanf("%d",&sum[i]);
        sum[i] += sum[i-1];
    }
    for(i=1;i<=n;i++) dp[i] = 0x7fffffff;
    for(i=0;i<n;i++) {
        for(j=i+1;j<=n;j++) {
            tmp = sum[j] - sum[i] + j - i - 1;
            if(tmp > m) break;
            dp[j] = min(dp[j], dp[i] + (m - tmp) * (m - tmp));
        }
    }
    for(i=n;i>=0;i--) {
        tmp = sum[n] - sum[i] + n - i - 1 + (i == n);
        if(tmp > m) break;
        ans = min(ans, dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}