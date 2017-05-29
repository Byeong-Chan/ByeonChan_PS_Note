#include <cstdio>
#include <cmath>
long long rep(long long x, long long n, long long mod) {
    if (n == 0) return 1;
    long long tmp = rep(x, n>>1, mod);
    tmp *= tmp;
    tmp %= mod;
    if (n & 1) {
        tmp *= x;
        tmp %= mod;
    }
    return tmp;
}
long long cnt(long long x, long long d, long long s, int depth) {
    if (s / d == 0) return 0;
    long long tmp = cnt(x, d * x, s, depth + 1);
    tmp += ((s/d) - (s/(d*x))) * (long long)depth;
    return tmp;
}
bool chk[4000010];
int main() {
    int i, j;
    long long ans = 1;
    long long n, m, p;
    long long lv;
    scanf("%lld %lld %lld",&n, &m, &p);
    if (m > n/2) m = n-m;
    
    chk[1] = true;
    chk[0] = true;
    for(i=2;i<=n;i++) {
        if (chk[i] == 0) {
            for(j=i;j<=n;j+=i) chk[j] = true;
            lv = cnt(i, i, n, 1);
            if (i <= m) lv -= cnt(i, i, m, 1);
            if (i <= n-m) lv -= cnt(i, i, n-m, 1);
            
            ans *= rep(i, lv, p);
            ans %= p;
        }
    }
    printf("%lld\n",ans);
    
    return 0;
}