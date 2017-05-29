#include <cstdio>
long long gcd(long long a, long long b) {
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}
int main() {
    long long n, m, sz;
    scanf("%lld %lld",&n,&m);
    sz = gcd(n,m);
    for(long long i=0;i<sz;i++) printf("1");
    printf("\n");
    return 0;
}