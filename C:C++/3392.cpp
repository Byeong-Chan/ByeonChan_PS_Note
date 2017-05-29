#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int segtree[1<<21];
int nonzero[1<<21];
void update(int d, int hl, int hr, int l, int r, int val) {
    if(hl <= l && hr >= r) {
        if(val + 1) segtree[d] = val * (r - l + 1);
        
        nonzero[d] += val;
        if(nonzero[d] == 0) {
            if(l < r) segtree[d] = segtree[d<<1] + segtree[(d<<1)+1];
            else segtree[d] = 0;
        }
        
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= hl) update(d<<1, hl, hr, l, mid, val);
    if(mid+1 <= hr) update((d<<1)+1, hl, hr, mid+1, r, val);
    
    if(nonzero[d] == 0) segtree[d] = segtree[d<<1] + segtree[(d<<1)+1];
}
int query(int d, int hl, int hr, int l, int r) {
    if(hl <= l && hr >= r) return segtree[d];
    
    int tmpl = 0, tmpr = 0;
    int mid = (l + r) / 2;
    if(mid >= hl) tmpl = query(d<<1, hl, hr, l, mid);
    if(mid+1 <= hr) tmpr = query((d<<1)+1, hl, hr, mid+1, r);
    return tmpl + tmpr;
}
struct node {
    int x;
    int y;
    int val;
    node() {}
    node(int ix, int iy, int ival): x(ix), y(iy), val(ival) {}
};
vector<node> p[30010];
int main() {
    int st = 0, ed = 30000;
    int x1, y1, x2, y2;
    int n;
    int i, j;
    int ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        p[x1].push_back(node(y1, y2 - 1, 1));
        p[x2].push_back(node(y1, y2 - 1, -1));
    }
    for(i=0;i<=30000;i++) {
        for(j=0;j<p[i].size();j++) {
            update(1, p[i][j].x, p[i][j].y, st, ed, p[i][j].val);
        }
        ans += segtree[1];
    }
    printf("%d\n",ans);
    return 0;
}