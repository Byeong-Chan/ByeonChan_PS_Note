#include <cstdio>
long long gcd(long long x, long long y) {
    if(x % y == 0) return y;
    else return gcd(y, x % y);
}
int main() {
    long long i;
    long long n, m;
    long long x, y;
    long long ansx = 1, ansy = 1;
    scanf("%lld %lld",&n,&m);
    m /= n;
    for(i=1;i*i<=m;i++) {
        if(m % i) continue;
        x = i;
        y = m / i;
        if(gcd(x, y) == 1) ansx = x, ansy = y;
    }
    printf("%lld %lld\n",ansx * n, ansy * n);
    return 0;
}