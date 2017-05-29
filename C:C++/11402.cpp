#include <cstdio>
long long mod;
long long rep(long long a, long long b) {
    if (b == 0) return 1;
    long long tmp = rep(a, b >> 1);
    tmp *= tmp;
    tmp %= mod;
    
    if (b & 1) tmp *= a;
    tmp %= mod;
    
    return tmp;
}
long long inv[2010];
long long mul[2010];
int main() {
    int i;
    long long n, m, p;
    long long ni, mi;
    long long ans = 1;
    long long max1;
    scanf("%lld %lld %lld",&n,&m,&p);
    
    max1 = n;
    if (max1 < m) max1 = m;
    
    mod = p;
    inv[0] = 1;
    for(i=1;i<p;i++) {
        inv[i] = rep(i, p-2);
        if (i > 0) inv[i] = (inv[i] * inv[i-1]) % mod;
    }
    mul[0] = 1;
    for(i=1;i<p;i++) {
        mul[i] = i;
        mul[i] *= mul[i-1];
        mul[i] %= mod;
    }
    
    while (max1) {
        ni = n % p;
        mi = m % p;
        
        if (ni < mi) ans *= 0;
        else ans *= mul[ni] * inv[mi] * inv[ni-mi];
        ans %= mod;
        
        n /= p;
        m /= p;
        max1 /= p;
    }
    printf("%lld\n",ans);
    return 0;
}