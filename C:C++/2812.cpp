#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair<char, int> pr;
char o[500010];
pr indextr[2150000];
bool cmp(pr x, pr y) {
    if (x.first != y.first) return x.first < y.first;
    return x.second > y.second;
}
int main() {
    int n, m;
    int i;
    int k;
    int d;
    int p;
    int st, ed;
    int l, r;
    pr max1;
    scanf("%d %d", &n,&m);
    scanf("%s", o);
    for (k = 1; k < n; k <<= 1);
    for (i = 1; i < k * 2; i++) indextr[i].first = '0' - 1;
    for (i = 0; i < n; i++) {
        d = k + i;
        indextr[d] = make_pair(o[i], i);
        while(d > 1) {
            l = d << 1;
            r = l + 1;
            if (cmp(indextr[d], indextr[l])) indextr[d] = indextr[l];
            if (cmp(indextr[d], indextr[r])) indextr[d] = indextr[r];
            d >>= 1;
        }
    }
    p = 0;
    while (m > 0 && n - p - m >= 1) {
        st = k + p;
        if(k+p+m < k+n) ed = k + p + m;
        else ed = k + n - 1;
        max1 = make_pair('0' - 1, 0x7fffffff);
        while (1) {
            if (cmp(max1, indextr[st])) max1 = indextr[st];
            if (cmp(max1, indextr[ed])) max1 = indextr[ed];
            if (st == ed) break;
            if (st & 1) st++;
            if (!(ed & 1)) ed--;
            if (st > ed) break;
            st >>= 1;
            ed >>= 1;
        }
        for (i = p; i < max1.second; i++) o[i] = 0;
        m = m - max1.second + p;
        p = max1.second + 1;
        if(p+m == n) {
            for(i=p;i<n;i++) o[i] = 0;
            break;
        }
    }
    for (i = 0; i < n; i++) if (o[i] != 0) printf("%c", o[i]);
    return 0;
}