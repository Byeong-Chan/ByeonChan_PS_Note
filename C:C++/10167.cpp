#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, k;
struct bung {
    ll Lmax;
    ll Rmax;
    ll LR;
    ll Amax;
}index1[10300], del;
struct seo {
    int x;
    int y;
    int num;
    ll cst;
}o[3001];
bool fsort(seo a, seo b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
bool ksort(seo a, seo b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
ll _max(ll x, ll y) {
    if (x > y) return x;
    return y;
}
int main() {
    int i, j;
    int d;
    int p = 0;
    ll max1 = 0;
    ll tmp;
    int l, r;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d %d %lld",&o[i].x,&o[i].y,&o[i].cst);
    sort(o, o+n, fsort);
    o[0].num = ++p;
    for(i=1;i<n;i++) {
        if(o[i].x != o[i-1].x) o[i].num = ++p;
        else o[i].num = p;
    }
    for(k=1;k<p;k<<=1);
    sort(o, o+n, ksort);
    for(i=0;i<n;i++) {
        if(i > 0 && o[i].y == o[i-1].y) continue;
        for(j=1;j<=k+p;j++) index1[j] = del;
        for(j=i;j<n;j++) {
            tmp = o[j].cst;
            d = k + o[j].num - 1;
            index1[d].Lmax += tmp;
            index1[d].Rmax += tmp;
            index1[d].LR += tmp;
            index1[d].Amax += tmp;
            while(d > 1) {
                d >>= 1;
                l = d<<1;
                r = l+1;
                index1[d].LR += tmp;
                index1[d].Lmax = _max(index1[l].Lmax, index1[l].LR + index1[r].Lmax);
                index1[d].Rmax = _max(index1[r].Rmax, index1[r].LR + index1[l].Rmax);
 
                index1[d].Amax = _max(index1[l].Rmax + index1[r].Lmax, _max(index1[l].Amax, _max(index1[r].Amax, index1[d].LR)));
            }
            if(j+1 == n || (j+1 < n && o[j].y != o[j+1].y)) {
                if(max1 < index1[1].Amax) max1 = index1[1].Amax;
            }
        }
    }
    printf("%lld",max1);
    return 0;
}