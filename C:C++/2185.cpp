#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int segtree1[1<<16], segtree2[1<<16];
int nonzero1[1<<16], nonzero2[1<<16];
void update(int segtree[], int nonzero[], int d, int hl, int hr, int l, int r, int val) {
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
    if(mid >= hl) update(segtree, nonzero, d<<1, hl, hr, l, mid, val);
    if(mid+1 <= hr) update(segtree, nonzero, (d<<1)+1, hl, hr, mid+1, r, val);
    
    if(nonzero[d] == 0) segtree[d] = segtree[d<<1] + segtree[(d<<1)+1];
}
int query(int segtree[], int d, int hl, int hr, int l, int r) {
    if(hl <= l && hr >= r) return segtree[d];
    
    int tmpl = 0, tmpr = 0;
    int mid = (l + r) / 2;
    if(mid >= hl) tmpl = query(segtree, d<<1, hl, hr, l, mid);
    if(mid+1 <= hr) tmpr = query(segtree, (d<<1)+1, hl, hr, mid+1, r);
    return tmpl + tmpr;
}
struct node {
    int x;
    int y;
    int val;
    node() {}
    node(int ix, int iy, int ival): x(ix), y(iy), val(ival) {}
};
vector<node> p[20010];
vector<node> q[20010];
int main() {
    int st = 0, ed = 20000;
    int x1, y1, x2, y2;
    int n;
    int i, j;
    int tmp;
    int ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        x1 += 10000;
        x2 += 10000;
        y1 += 10000;
        y2 += 10000;
        
        p[x1].push_back(node(y1, y2 - 1, 1));
        p[x2].push_back(node(y1, y2 - 1, -1));
        
        q[y1].push_back(node(x1, x2 - 1, 1));
        q[y2].push_back(node(x1, x2 - 1, -1));
    }
    for(i=0;i<=20000;i++) {
        for(j=0;j<p[i].size();j++) {
            if(p[i][j].val == -1) continue;
            tmp = segtree1[1];
            update(segtree1, nonzero1, 1, p[i][j].x, p[i][j].y, st, ed, p[i][j].val);
            ans += (segtree1[1] - tmp) * 2;
        }
        for(j=0;j<q[i].size();j++) {
            if(q[i][j].val == -1) continue;
            tmp = segtree2[1];
            update(segtree2, nonzero2, 1, q[i][j].x, q[i][j].y, st, ed, q[i][j].val);
            ans += (segtree2[1] - tmp) * 2;
        }
        for(j=0;j<p[i].size();j++) {
            if(p[i][j].val == 1) continue;
            update(segtree1, nonzero1, 1, p[i][j].x, p[i][j].y, st, ed, p[i][j].val);
        }
        for(j=0;j<q[i].size();j++) {
            if(q[i][j].val == 1) continue;
            update(segtree2, nonzero2, 1, q[i][j].x, q[i][j].y, st, ed, q[i][j].val);
        }
    }
    printf("%d\n",ans);
    return 0;
}