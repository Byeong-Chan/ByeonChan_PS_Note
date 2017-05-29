#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int a[410000], b[410000], ahap[410000], bhap[410000], cut[410000], cut2[410000];
unsigned long long int maxhap = 0, minhap = 0, tmp;
struct bung {
    int x;
    int y;
}big[1100000];
struct seo {
    int x;
    int y;
}sma[1100000];
priority_queue<int, vector<int>, greater<int> > max1;
bool ksort(seo a, seo b)
{
    if (a.x < b.x) return true;
    return false;
}
bool fsort(bung a, bung b) {
    if (a.y < b.y) return true;
    return false;
}
int main() {
    int i, k, n, m, t;
    int p = 0;
    int key, st, ed;
    scanf("%d %d %d", &k, &n, &m);
    for (i = 0; i<m; i++) {
        scanf("%d %d", &big[i].x, &big[i].y);
        sma[i].x = ++big[i].x;
        sma[i].y = ++big[i].y;
 
        a[big[i].y]++;
        b[big[i].x]++;
    }
    std::sort(big, big + m, fsort);
    std::sort(sma, sma + m, ksort);
    for (i = 1; i<m; i++) {
        if (big[i].y != big[i - 1].y) {
            t = big[i - 1].y;
            while (p < t - 1) {
                p++;
                cut[p] = cut[p - 1];
            }
            cut[++p] = i;
        }
    }
    t = big[i - 1].y;
    while (p < n) {
        p++;
        if (p < t) {
            cut[p] = cut[p - 1];
            continue;
        }
        cut[p] = m;
    }
 
    p = 0;
    for (i = 1; i<m; i++) {
        if (sma[i].x != sma[i - 1].x) {
            t = sma[i - 1].x;
            while (p < t - 1) {
                p++;
                cut2[p] = cut2[p - 1];
            }
            cut2[++p] = i;
        }
    }
    t = sma[i - 1].x;
    while (p < n) {
        p++;
        if (p < t) {
            cut2[p] = cut2[p - 1];
            continue;
        }
        cut2[p] = m;
    }
 
    t = n;
    for (i = 1; i <= n; i++) if (a[i] == 0) max1.push(i);
    while (max1.size()) {
        key = max1.top();
        max1.pop();
 
        ahap[key - 1] = --t;
 
        st = cut2[key - 1];
        ed = cut2[key];
        for (i = st; i<ed; i++) if (--a[sma[i].y] == 0) max1.push(sma[i].y);
    }
 
 
    t = k - n;
    for (i = 1; i <= n; i++) if (b[i] == 0) max1.push(i);
    while (max1.size()) {
        key = max1.top();
        max1.pop();
 
        bhap[key - 1] = t++;
 
        st = cut[key - 1];
        ed = cut[key];
        for (i = st; i<ed; i++) if (--b[big[i].x] == 0) max1.push(big[i].x);
    }
 
    tmp = 1;
    for (i = 0; i<n; i++)
    {
        minhap += (tmp * ahap[i]);
        minhap %= 1000000007;
 
        maxhap += (tmp * bhap[i]);
        maxhap %= 1000000007;
 
 
        tmp *= k;
        tmp %= 1000000007;
    }
    if (maxhap < minhap) maxhap = 1000000007 + maxhap - minhap;
    else maxhap -= minhap;
 
    printf("%lld", maxhap);
    return 0;
}