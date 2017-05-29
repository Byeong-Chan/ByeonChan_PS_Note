#include <cstdio>
int seg[3000010];
int p[40010];
int k;
void update(int d) {
    int l, r;
    while (d > 1) {
        d >>= 1;
        l = (d << 1);
        r = l + 1;
        if (seg[d] < seg[l]) seg[d] = seg[l];
        if (seg[d] < seg[r]) seg[d] = seg[r];
    }
}
int query(int l, int r) {
    l += k-1;
    r += k-1;
    int max1 = 0;
    while(l <= r) {
        if(max1 < seg[l]) max1 = seg[l];
        if(max1 < seg[r]) max1 = seg[r];
        if(l == r) break;
        
        if(l & 1) l++;
        if(!(r & 1)) r--;
        
        if(l > r) break;
        l >>= 1;
        r >>= 1;
    }
    return max1;
}
int main() {
    int t;
    int i, n, x;
    int tmp;
    int ans;
    scanf("%d",&t);
    while (t--) {
        ans = 0;
        scanf("%d",&n);
        k = 1 << 17;
        for(i=1;i<=3000000;i++) seg[i] = 0;
        for(i=0;i<n;i++) {
            scanf("%d",&x);
            p[x] = i;
            tmp = query(1, x) + 1;
            if (ans < tmp) ans = tmp;
            if (seg[k + x - 1] < tmp) {
                seg[k + x - 1] = tmp;
                update(k + x - 1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}