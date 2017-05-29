#include <cstdio>
#include <algorithm>
int cnt[110];
long long p[110];
long long ans[100010];
int main() {
    int i, j;
    int n, m;
    const long long inf = (long long)1 << 33;
    scanf("%d %d",&m,&n);
    ans[0] = 1;
    for(i=0;i<m;i++) scanf("%lld",&p[i]);
    for(i=1;i<=n;i++) {
        ans[i] = inf;
        for(j=0;j<m;j++) {
            while (ans[i-1] >= ans[cnt[j]] * p[j]) cnt[j]++;
            ans[i] = std::min(ans[cnt[j]] * p[j], ans[i]);
        }
    }
    printf("%lld",ans[n]);
    return 0;
}