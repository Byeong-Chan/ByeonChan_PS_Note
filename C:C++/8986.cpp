#include <cstdio>
#include <algorithm>
using namespace std;
struct bung {
    long long num;
    long long pos;
    bool operator< (const bung &a) const {
        return this->pos * a.num < a.pos * this->num;
    }
}o[100010];
long long sav[100010];
long long _abs(long long x) {
    if (x < 0) return -x;
    else return x;
}
int main() {
    int i, l, n;
    long long k, d;
    long long hap;
    long long ans;
    scanf("%d",&n);
    k = (long long)n * (n-1);
    k >>= 1;
    k >>= 1;
    for(i=0;i<n;i++) {
        scanf("%lld",&sav[i]);
        o[i].pos = sav[i];
        o[i].num = i;
    }
    if (n == 1 || n == 2) {
        printf("0");
        return 0;
    }
    sort(o+1,o+n);
    for (i=1;i<n;i++) {
        k -= o[i].num;
        if (k < 0) break;
    }
    
    hap = 0;
    d = o[i].pos / o[i].num;
    for (l=0;l<n;l++) hap += _abs(sav[l]-d*l);
    ans = hap;
    
    hap = 0;
    d++;
    for (l=0;l<n;l++) hap += _abs(sav[l]-d*l);
    if (ans > hap) ans = hap;
    
    if (i-1 > 0) {
        hap = 0;
        d = o[i-1].pos / o[i-1].num;
        for (l=0;l<n;l++) hap += _abs(sav[l]-d*l);
        if (ans > hap) ans = hap;
        
        hap = 0;
        d++;
        for (l=0;l<n;l++) hap += _abs(sav[l]-d*l);
        if (ans > hap) ans = hap;
    }
    printf("%lld",ans);
    return 0;
}