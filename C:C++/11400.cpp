#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> phnode[100010];
int ph = 0;
int node[100010];
int num[100010];
int low[100010];
bool chk[100010];
int cnt = 0;
vector<int> edge[100010];
vector<int> trace;
void dfs(int u, int moth) {
    chk[u] = true;
    low[u] = ++cnt;
    num[u] = cnt;
    bool isroot = true;
    trace.push_back(u);
    
    for(int i=0;i<edge[u].size();i++) {
        int v = edge[u][i];
        if (v == moth) continue;
        if (!chk[v]) dfs(v, u);
        if (low[u] > low[v]) {
            low[u] = low[v];
            isroot = false;
        }
    }
    
    if (isroot) {
        ph++;
        while (true) {
            int x = trace.back();
            trace.pop_back();
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
        dfs(i, -1);
    }
}
pair<int, int> ans[1000010];
int main() {
    int i, j;
    int n, m;
    int x, y;
    int sz = 0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    scc(n);
    for(i=1;i<=n;i++) {
        for(j=0;j<(int)edge[i].size();j++) {
            int v = edge[i][j];
            if(v < i) continue;
            if(node[i] != node[v]) ans[sz++] = make_pair(i, v);
        }
    }
    printf("%d\n",sz);
    sort(ans , ans + sz);
    for(i=0;i<sz;i++) printf("%d %d\n",ans[i].first, ans[i].second);
    return 0;
}