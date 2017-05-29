#include <cstdio>
#define mod 1000000007
long long rep(int x, int n) {
    if (n == 0) return 1;
    long long tmp = rep(x, n >> 1);
    tmp = (tmp * tmp) % mod;
    if (n & 1) tmp = (tmp * x) % mod;
    return tmp;
}
bool chk[4000000];
int main() {
    int i;
    int n, k;
    long long ans = 1, p = 1;
    scanf("%d %d",&n,&k);
    if (k > n/2) k = n - k;
    for (i=1;i<=k;i++) {
        p *= i;
        p %= mod;
    }
    ans *= rep((int)p, mod - 2);
    for (i=k-1;i>=0;i--) {
        ans *= (n-i);
        ans %= mod;
    }
    printf("%lld\n",ans);
    return 0;
}