#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int factor[45];
long long cnt(int depth, long long x, long long p, long long n) {
    if(p > n) return 0;
    long long tmp = cnt(depth+1, x, p * x, n);
    tmp += (n / p - n / (p * x)) * (long long)depth;
    return tmp;
}
map<int, long long> how;
int main() {
    int i, n;
    int m;
    long long tmp, k;
    long long ans;
    while(scanf("%d %lld",&n,&k) == 2) {
        tmp = k;
        m = 0;
        ans = 1;
        for(i=2;i*i<=k;i++) {
            if (tmp % i == 0) how[i] = cnt(1, i, i, n);
            while (tmp % i == 0) {
                factor[m++] = i;
                tmp /= i;
            }
        }
        if (tmp > 1) {
            factor[m++] = (int)tmp;
            how[(int)tmp] = cnt(1, tmp, tmp, n);
            tmp = 1;
        }
        factor[m] = 0x7fffffff;
        for(i=0;i<m;i++) {
            tmp = --how[factor[i]];
            if (tmp >= 0) ans *= factor[i];
        }
        printf("%lld\n",ans);
        how.clear();
    }
    return 0;
}