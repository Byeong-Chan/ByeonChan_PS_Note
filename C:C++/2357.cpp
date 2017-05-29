#include <cstdio>
#include <algorithm>
using namespace std;
int k;
int mintree[1 << 18], maxtree[1 << 18];
void init(int n) {
    for(k=1;k<n;k<<=1);
    for(int i=(k<<1)-1;i>0;i--) {
        maxtree[i] = 0;
        mintree[i] = 0x7fffffff;
    }
}
void update(int d, int val) {
    d += k;
    d--;
    maxtree[d] = mintree[d] = val;
    while(d > 1) {
        d >>= 1;
        int l = d << 1;
        int r = l + 1;
        if(maxtree[l] > maxtree[d]) maxtree[d] = maxtree[l];
        if(maxtree[r] > maxtree[d]) maxtree[d] = maxtree[r];
        if(mintree[l] < mintree[d]) mintree[d] = mintree[l];
        if(mintree[r] < mintree[d]) mintree[d] = mintree[r];
    }
}
pair<int, int> query(int st, int ed) {
    pair<int, int> mxmn(0, 0x7fffffff);
    st += k;
    ed += k;
    st--;
    ed--;
    while(1) {
        if(maxtree[st] > mxmn.first) mxmn.first = maxtree[st];
        if(maxtree[ed] > mxmn.first) mxmn.first = maxtree[ed];
        if(mintree[st] < mxmn.second) mxmn.second = mintree[st];
        if(mintree[ed] < mxmn.second) mxmn.second = mintree[ed];
        if(st == ed) break;
        if(st & 1) st++;
        if(!(ed & 1)) ed--;
        if(st > ed) break;
        st >>= 1;
        ed >>= 1;
    }
    return mxmn;
}
int main() {
    int i, n, m;
    int x, y;
    pair<int, int> ans;
    scanf("%d %d",&n,&m);
    init(n);
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        update(i, x);
    }
    for(i=0;i<m;i++) {
        scanf("%d %d",&x, &y);
        ans = query(x, y);
        printf("%d %d\n",ans.second, ans.first);
    }
    return 0;
}