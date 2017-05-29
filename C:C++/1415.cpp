#include <cstdio>
#include <algorithm>
using namespace std;
long long dp[500010], tmp[500010];
bool chk[500010];
int o[53];
int main() {
    int i, j, n;
    int sum = 0;
    int x = 0;
    long long ans = 0;
    scanf("%d",&n);
    dp[0] = 1;
    for (i=1;i<=n;i++) scanf("%d",&o[i]);
    sort(o+1,o+n+1);
    o[0] = -1;
    for (i=1;i<=n;i++) {
        if (o[i-1] != o[i]) {
            for (j=0;j<=sum;j++) tmp[j] = dp[j];
            x = o[i];
        }
        else x += o[i];
        for(j=sum;j>=0;j--) if (j+x <= 500000) dp[j+x] += tmp[j];
        sum += o[i];
    }
    chk[0] = chk[1] = true;
    for (i=2;i<=sum;i++) {
        if (chk[i]) continue;
        for(j=i;j<=sum;j+=i) chk[j] = true;
        ans += dp[i];
    }
    printf("%lld\n",ans);
    return 0;
}