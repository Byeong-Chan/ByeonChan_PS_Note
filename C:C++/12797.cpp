#include <cstdio>
#include <algorithm>
using namespace std;
#define mod 1000000007
long long rep(long long x, long long r) {
    if (r == 0) return 1;
    long long tmp = rep(x, r >> 1);
    tmp *= tmp;
    tmp %= mod;
    if (r & 1) {
        tmp *= x;
        tmp %= mod;
    }
    return tmp;
}
long long p[1010];
long long sav[1010];
long long p_inv[1010][1010];
long long e[1010];
long long a[1010];
int main() {
    int n, m;
    int i, j;
    long long div, tmp, sum = 0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++) scanf("%lld",&a[i]);
    sort(a, a+m);
    e[0] = 1;
    for(i=0;i<m;i++) {
        p[0] = 1;
        div = rep(a[i], mod-2);
        for(j=1;j<=i;j++) {
            tmp = a[i] - a[j-1];
            p[j] = ((p[j-1] * div % mod) * tmp) % mod;
        }
        e[i] = p[0];
        sav[i] = p[i];
    }
    for(i=0;i<m;i++) {
        tmp = 1;
        p_inv[i][i] = 1;
        div = rep(sav[i], mod-2);
        p_inv[i][i] *= div;
        e[i] *= rep(a[i], n);
        for(j=i+1;j<m;j++) {
            p_inv[i][j] = ((mod - (tmp * a[j]) % mod) * (rep(a[j] - a[i], mod-2) % mod)) % mod;
            
            tmp += p_inv[i][j];
            tmp %= mod;
            if (tmp < 0) tmp += mod;
            
            p_inv[i][j] *= div;
            p_inv[i][j] %= mod;
        }
    }
    for (i=0;i<m;i++) {
        for(j=0;j<m;j++) {
            sum += p_inv[j][i] * e[j];
            sum %= mod;
        }
    }
    printf ("%lld",sum);
    return 0;
}