#include <cstdio>
#include <algorithm>
using namespace std;

long long H[30010];
long long h[110];
long long dp[30010];
long long tmp[30010];
const long long MAX = (long long)1 << 61;

long long Abs(long long x) {
    if(x < 0) return -x;
    return x;
}

int main() {
    int i, j, k, n;
    int t;
    int Hsz;
    long long d;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %lld", &n, &d);
        for(i=0;i<n;i++) scanf("%lld",&h[i]);
        if(Abs(h[n-1] - h[0]) > (n-1) * d) {
            printf("impossible\n");
            continue;
        }
        Hsz = 0;
        for(i=0;i<n;i++) {
            for(j=-n+1;j<n;j++) {
                H[Hsz++] = h[i] + d * j;
            }
        }
        sort(H, H+Hsz);
        Hsz = (int)(unique(H, H+Hsz) - H);
        fill(dp, dp+Hsz, MAX);
        for(i=0;i<Hsz;i++) if(h[0] == H[i]) dp[i] = 0;
        for(k=1;k<n;k++) {
            for(i=0;i<Hsz;i++) {
                tmp[i] = dp[i];
                dp[i] = MAX;
            }
            j = 0;
            for(i=0;i<Hsz;i++) {
                while(i > j && H[i] - H[j] > d) j++;
                while(j+1 < Hsz && Abs(H[i] - H[j+1]) <= d && tmp[j+1] <= tmp[j]) j++;
                dp[i] = min(dp[i], Abs(h[k] - H[i]) + tmp[j]);
            }
        }
        for(i=0;i<Hsz;i++) if(h[n-1] == H[i]) printf("%lld\n",dp[i]);
    }
    return 0;
}