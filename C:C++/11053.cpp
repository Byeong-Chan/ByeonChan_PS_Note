#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int k;
struct nodes {
    int val;
    int pos;
    nodes() {}
    nodes(int ival, int ipos) {
        val = ival;
        pos = ipos;
    }
    bool operator > (const nodes &a) const {
        if(val != a.val) return val > a.val;
        else return pos < a.pos;
    }
};
nodes segtree[1<<21];

void init(int n) {
    for(k=1;k<n;k<<=1);
    for(int i = k << 1; i > 0; i--) segtree[i] = nodes(0, 0);
}

void update(int d, nodes val) {
    d += k;
    d--;
    if(val > segtree[d]) segtree[d] = val;
    while(d > 1) {
        d >>= 1;
        int l = d << 1;
        int r = l + 1;
        if(segtree[l] > segtree[d]) segtree[d] = segtree[l];
        if(segtree[r] > segtree[d]) segtree[d] = segtree[r];
    }
}
nodes query(int st, int ed) {
    nodes ans(0, 0x7fffffff);
    st += k;
    ed += k;
    st--;
    ed--;
    
    while(1) {
        if(segtree[st] > ans) ans = segtree[st];
        if(segtree[ed] > ans) ans = segtree[ed];
        if(st == ed) break;
        if(st & 1) st++;
        if(!(ed & 1)) ed--;
        if(st > ed) break;
        
        st >>= 1;
        ed >>= 1;
    }
    return ans;
}

map<int, int> tpx;
int o[1010];
int dx[1010];
nodes dp[1010];

int main() {
    int i, n;
    int ex = 0;
    int tmp;
    nodes here, ans(0, 0x7fffffff);
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&o[i]);
        dx[i-1] = o[i];
    }
    sort(dx, dx+n);
    for(i=0;i<n;i++) {
        if(tpx[dx[i]] == 0) tpx[dx[i]] = ++ex;
    }
    init(ex);
    for(i=1;i<=n;i++) {
        tmp = tpx[o[i]];
        here = nodes(0, 0x7fffffff);
        if(tmp - 1 > 0) here = query(1, tmp-1);
        
        here.val += 1;
        dp[i] = here;
        here.pos = i;
        
        update(tmp, here);
        
        if(here > ans) ans = here;
    }
    printf("%d\n",ans.val);
    return 0;
}