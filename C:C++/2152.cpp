#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
vector<int> phedge[300010];
vector<int> phnode[300010];
int ph = 0;
int node[300010];
int num[300010];
int low[300010];
bool chk[300010];
int son[300010];
int table[300010];
int sav[300010];
int cnt = 0;
int chk2[300010];
vector<int> edge[300010];

struct dum {
    int pos;
    int f;
    bool isroot;
};

//vector<dum> stk;
vector<int> trace;
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
            node[num[x]] = ph;
            phnode[ph].push_back(x);
            low[x] = 0x7fffffff;
            
            if (x == u) break;
        }
    }
}
int main() {
    int i, j, pos, nxt;
    int nxtnode;
    int n, m, s, t;
    int x, y;
    int sz, sz2;
    int d;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
    }
    for (i = 1; i <= n; i++) {
        if (chk[i]) continue;
        dfs(i);
    }
    q.push(node[num[s]]);
    table[node[num[s]]] = (int)phnode[node[num[s]]].size();
    while (q.size()) {
        d = q.front();
        q.pop();
        sav[d] = (int)phnode[d].size();
        chk2[d] = d;
        sz = (int)phnode[d].size();
        for (i = 0; i < sz; i++) {
            pos = phnode[d][i];
            sz2 = (int)edge[pos].size();
            for (j = 0; j < sz2; j++) {
                nxt = edge[pos][j];
                nxtnode = node[num[nxt]];
                
                if (chk2[nxtnode] == d) continue;
                
                son[nxtnode]++;
                phedge[d].push_back(nxtnode);
                if(!chk2[nxtnode]) q.push(nxtnode);
                chk2[nxtnode] = d;
            }
        }
    }
    
    q.push(node[num[s]]);
    while (q.size()) {
        d = q.front();
        q.pop();
        sz = (int)phedge[d].size();
        for (i = 0; i < sz; i++) {
            nxt = phedge[d][i];
            if (--son[nxt] == 0) q.push(nxt);
            if (table[nxt] < sav[nxt] + table[d]) table[nxt] = sav[nxt] + table[d];
        }
    }
    
    printf("%d", table[node[num[t]]]);
    return 0;
}