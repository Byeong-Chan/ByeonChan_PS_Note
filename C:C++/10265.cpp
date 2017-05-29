#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> phnode[1010];
vector<int> phedge[1010];
int ph = 0;
int node[1010];
int pre[1010];
int num[1010];
int low[1010];
bool chk[1010];
int cnt = 0;
int hap[1010];
vector<int> edge[1010];
vector<int> trace;
queue<int> q;

bool dt[1010];

void dfs(int u) {
    chk[u] = true;
    low[u] = ++cnt;
    num[u] = cnt;
    bool isroot = true;
    trace.push_back(u);
    
    for(int i=0;i<edge[u].size();i++) {
        int v = edge[u][i];
        if (!chk[v]) dfs(v);
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
        dfs(i);
    }
}
int main() {
    int i, j, l;
    int n, m;
    int x, y;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        if (i != x) edge[x].push_back(i);
    }
    scc(n);
    dt[0] = true;
    for (i=1;i<=ph;i++) {
        
        for(j=0;j<phnode[i].size();j++) {
            x = phnode[i][j];
            for(l=0;l<edge[x].size();l++) {
                y = edge[x][l];
                if (i != node[y]) {
                    phedge[i].push_back(node[y]);
                    pre[node[y]]++;
                }
            }
        }
    }
    for(i=1;i<=ph;i++) if (pre[i] == 0) q.push(i);
    while (q.size()) {
        x = q.front();
        q.pop();
        
        l = (int)phnode[x].size();
        for (i=m;i>=hap[x];i--) if (i+l <= m && dt[i]) dt[i+l] = true;
        for (i=0;i<phedge[x].size();i++) {
            y = phedge[x][i];
            hap[y] += hap[x] + l;
            if (--pre[y] == 0) q.push(y);
        }
    }
    for(i=m;i>=0;i--) {
        if (dt[i]) {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}