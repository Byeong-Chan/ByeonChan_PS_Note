#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct bung {
    int lazy;
    int hap;
}tr[4100000];
int order[610000];
int subt[610000];
int wage[610000];
vector<int> son[610000];
void update_lazy(int d) {
    if (d == 0) return;
    update_lazy(d >> 1);
    int l = d << 1;
    int r = l + 1;
    int tmp = tr[d].lazy;
    tr[d].lazy = 0;
    
    tr[l].lazy += tmp;
    tr[l].hap += tmp;
    
    tr[r].lazy += tmp;
    tr[r].hap += tmp;
}
void update(int st, int ed, int cst) {
    if (st > ed) return;
    while (1) {
        if (st == ed) {
            tr[st].hap += cst;
            tr[st].lazy += cst;
            break;
        }
        if (st & 1) {
            tr[st].hap += cst;
            tr[st].lazy += cst;
            st++;
        }
        if (!(ed & 1)) {
            tr[ed].hap += cst;
            tr[ed].lazy += cst;
            ed--;
        }
        if (st > ed) break;
        st >>= 1;
        ed >>= 1;
    }
}
struct node {
    int f;
    int pos;
    int max1;
};
vector<node> stk;
void dfs(int u) {
    int cnt = 0;
    int i;
    int tmp;
    node now, sav;
    
    now.f = 0;
    now.pos = u;
    while (1) {
        if (order[now.pos] == 0) {
            order[now.pos] = ++cnt;
            now.max1 = cnt;
        }
        
        tmp = 0;
        for (i=now.f;i<son[now.pos].size();i++) {
            tmp = son[now.pos][i];
            if (order[tmp] != 0) continue;
            break;
        }
        
        now.f = i + 1;
        if (i == son[now.pos].size()) {
            subt[now.pos] = now.max1;
            
            if (stk.size() == 0) break;
            sav = stk.back();
            if (sav.max1 < now.max1) sav.max1 = now.max1;
            now = sav;
            stk.pop_back();
        }
        else {
            stk.push_back(now);
            
            now.f = 0;
            now.pos = son[now.pos][i];
            now.max1 = 0;
        }
    }
}
int main() {
    int i;
    int k;
    int n, q;
    int x, y;
    char qt[3];
    scanf("%d %d",&n,&q);
    for(k=1;k<n;k<<=1);
    
    scanf("%d",&wage[1]);
    
    for (i=2;i<=n;i++) {
        scanf("%d %d",&wage[i], &y);
        son[y].push_back(i);
    }
    dfs(1);
    for (i=1;i<=n;i++) tr[k+order[i]-1].hap = wage[i];
    
    for (i=0;i<q;i++) {
        scanf("%s",qt);
        if (qt[0] == 'p') {
            scanf("%d %d",&x,&y);
            update(k + order[x], k + subt[x] - 1, y);
        }
        else {
            scanf("%d",&x);
            update_lazy((k+order[x]-1) >> 1);
            printf("%d\n",tr[k+order[x]-1].hap);
        }
    }
    return 0;
}