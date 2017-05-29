#include <cstdio>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
using namespace std;
list<int> phnode[500010];
int ph = 0;
int node[500010];
int num[500010];
int low[500010];
bool chk[500010];
bool phrest[500010];

int cnt = 0;
int phatm[500010];
int pre[500010];
int max1[500010];

list<int> edge[500010];
list<int> phedge[500010];
stack<int> trace;
queue<int> q;
void dfs(int u) {
    chk[u] = true;
    low[u] = ++cnt;
    num[u] = cnt;
    bool isroot = true;
    trace.push(u);
    
    for(list<int>::iterator it=edge[u].begin();it != edge[u].end(); it++) {
        int v = *it;
        if (!chk[v]) dfs(v);
        if (low[u] > low[v]) {
            low[u] = low[v];
            isroot = false;
        }
    }
    
    if (isroot) {
        ph++;
        while (true) {
            int x = trace.top();
            trace.pop();
            node[x] = ph;
            phnode[ph].push_back(x);
            low[x] = 0x7fffffff;
            
            if (x == u) break;
        }
    }
}
void scc(int n) {
    for(int i=1;i<=n;i++) {
        if(chk[i]) continue;
        dfs(i);
    }
}
void dfs2(int u) {
    max1[u] = -1;
    
    for(list<int>::iterator it=phedge[u].begin(); it != phedge[u].end();it++) {
        int v = *it;
        if (!max1[v]) dfs2(v);
    }
}
int main() {
    int i;
    int n, m;
    int x, y;
    int ans = 0;
    int st, S = 0, k;
    list<int>::iterator it, it2;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
    }
    scc(n);
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        phatm[node[i]] += x;
    }
    scanf("%d %d",&st,&k);
    for(i=0;i<k;i++) {
        scanf("%d",&x);
        phrest[node[x]] = true;
    }
    
    for (i=1;i<=ph;i++) {
        for(it=phnode[i].begin();it != phnode[i].end(); it++) {
            x = *it;
            if (x == st) S = i;
            for (it2=edge[x].begin(); it2 != edge[x].end(); it2++) {
                y = *it2;
                if (i != node[y]) phedge[i].push_back(node[y]);
            }
        }
    }
    dfs2(S);
    for(i=1;i<=ph;i++) {
        if (max1[i]) {
            for(it=phedge[i].begin();it != phedge[i].end(); it++) {
                x = *it;
                pre[x]++;
            }
        }
    }
    q.push(S);
    max1[S] = phatm[S];
    while(q.size()) {
        x = q.front();
        q.pop();
        if (phrest[x] && ans < max1[x]) ans = max1[x];
        
        for(it=phedge[x].begin();it!=phedge[x].end();it++) {
            y = *it;
            if (--pre[y] == 0) q.push(y);
            if (max1[x] + phatm[y] > max1[y]) max1[y] = max1[x] + phatm[y];
        }
    }
    printf("%d\n",ans);
    return 0;
}