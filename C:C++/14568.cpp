#include <cstdio>
int dp[110][110];
int main() {
    int i;
    int n;
    int m;
    int ans = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        m = n - i * 2 - 2;
        if(m <= 0) break;
        ans += (m>>1);
    }
    printf("%d\n",ans);
    return 0;
}