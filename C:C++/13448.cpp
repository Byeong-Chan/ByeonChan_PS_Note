#include <cstdio>
#include <algorithm>
using namespace std;
struct bung {
    int M;
    int P;
    int R;
    bool operator< (const bung &a) const {
        return (long long)this->R * a.P < (long long)a.R * this->P;
    }
}o[54];
long long dp[100010];
int main() {
    int i, j;
    int n, m;
    long long ans = 0;
    long long tmp;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&o[i].M);
    for(i=0;i<n;i++) scanf("%d",&o[i].P);
    for(i=0;i<n;i++) scanf("%d",&o[i].R);
    sort(o, o+n);
    for(i=0;i<n;i++) {
        for(j=m;j>=0;j--) {
            if (j+o[i].R > m) continue;
            tmp = dp[j] + o[i].M - (long long)o[i].P*(j+o[i].R);
            dp[j + o[i].R] = max(tmp, dp[j + o[i].R]);
        }
    }
    for(i=0;i<=m;i++) if (ans < dp[i]) ans = dp[i];
    printf("%lld\n",ans);
    return 0;
}