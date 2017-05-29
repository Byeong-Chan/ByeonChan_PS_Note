#include <stdio.h>
#include <algorithm>
using namespace std;
struct bung
{
    int num;
    int x;
    int y;
    int tmp;
}o[510000];
int fsort(bung a, bung b)
{
    if(a.y < b.y) return 1;
    return 0;
}
int ksort(bung a, bung b)
{
    if(a.x < b.x) return 1;
    if(a.x <= b.x && a.tmp > b.tmp) return 1;
    return 0;
}
int tree[1100000];
int main()
{
    int i, n;
    int d, k;
    int e = 1;
    int max1, maxchain = 1;
    int x, y;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d %d %d",&o[i].num,&o[i].x,&o[i].y);
    std::sort(o,o+n,fsort);
    o[0].tmp = e;
    for(i=1;i<n;i++) {
        if(o[i-1].y != o[i].y) o[i].tmp = ++e;
        else o[i].tmp = e;
    }
    for(k=1;k<e;k<<=1);
    std::sort(o,o+n,ksort);
    for(i=0;i<n;i++) {
        if(i>0 && o[i].x == o[i-1].x && o[i].y == o[i-1].y) continue;
        x = k+o[i].tmp-1;
        y = k+e-1;
        max1 = 0;
        while(1) {
            if(max1 < tree[x]) max1 = tree[x];
            if(max1 < tree[y]) max1 = tree[y];
            if(x&1) x++;
            if(!(y&1)) y--;
            if(x > y) break;
            if(max1 < tree[x]) max1 = tree[x];
            if(max1 < tree[y]) max1 = tree[y];
            x >>= 1;
            y >>= 1;
            if(x >= y) break;
        }
        max1++;
        d = k+o[i].tmp-1;
        if(tree[d] < max1) {
            tree[d] = max1;
            while(d > 1) {
                if(d & 1) {
                    if(tree[d] > tree[d-1]) tree[d>>1] = tree[d];
                    else break;
                }
                else {
                    if(tree[d] > tree[d+1]) tree[d>>1] = tree[d];
                    else break;
                }
                d>>=1;
            }
        }
        if(max1 > maxchain) maxchain = max1;
    }
    printf("%d",maxchain);
    return 0;
}