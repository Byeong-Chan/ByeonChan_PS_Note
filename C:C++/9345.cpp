#include <cstdio>
#include <algorithm>

using namespace std;

struct segmenttree {
    int k, N;
    int arr[100010];
    int segmin[1<<18];
    int segmax[1<<18];
    void updatemin(int d, int val) {
        int l, r;
        d += k - 1;
        segmin[d] = val;
        while(d > 1) {
            d >>= 1;
            l = d << 1;
            r = l + 1;
            if(segmin[r] > segmin[l]) segmin[d] = segmin[l];
            else segmin[d] = segmin[r];
        }
    }
    void updatemax(int d, int val) {
        int l, r;
        d += k - 1;
        segmax[d] = val;
        while(d > 1) {
            d >>= 1;
            l = d << 1;
            r = l + 1;
            if(segmax[r] < segmax[l]) segmax[d] = segmax[l];
            else segmax[d] = segmax[r];
        }
    }
    void init(int n) {
        N = n;
        for(k=1;k<n;k<<=1);
        for(int i=(k<<1)-1;i>0;i--) {
            segmin[i] = 0x7fffffff;
            segmax[i] = 0;
        }
        for(int i=n;i>0;i--) {
            arr[i] = i;
            updatemin(i, i);
            updatemax(i, i);
        }
    }
    int querymax(int l, int r) {
        int ans = 0;
        l += k - 1;
        r += k - 1;
        while(1) {
            if(ans < segmax[l]) ans = segmax[l];
            if(ans < segmax[r]) ans = segmax[r];
            if(l == r) break;
            if(l & 1) l++;
            if(!(r & 1)) r--;
            if(l > r) break;
            
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
    int querymin(int l, int r) {
        int ans = 0x7fffffff;
        l += k - 1;
        r += k - 1;
        while(1) {
            if(ans > segmin[l]) ans = segmin[l];
            if(ans > segmin[r]) ans = segmin[r];
            if(l == r) break;
            if(l & 1) l++;
            if(!(r & 1)) r--;
            if(l > r) break;
            
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
};
segmenttree dec;
int main() {
    int t;
    int n, m;
    int i;
    int q, x, y;
    int tmp1, tmp2;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        dec.init(n);
        for(i=0;i<m;i++) {
            scanf("%d %d %d",&q, &x, &y);
            x++;
            y++;
            if(x > y) swap(x, y);
            if(q) {
                if(dec.querymin(x, y) == x && dec.querymax(x, y) == y) printf("YES\n");
                else printf("NO\n");
            }
            else {
                tmp1 = dec.arr[x];
                tmp2 = dec.arr[y];
                dec.updatemax(x, tmp2);
                dec.updatemax(y, tmp1);
                dec.updatemin(x, tmp2);
                dec.updatemin(y, tmp1);
                dec.arr[x] = tmp2;
                dec.arr[y] = tmp1;
            }
        }
    }
    return 0;
}