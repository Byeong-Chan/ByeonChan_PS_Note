#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 610;
const int INF = 0x7fffffff;

struct edge {
    int a, b, cap, flow;
};

int o[MAXN];
int N, s, t, d[MAXN], ptr[MAXN], q[MAXN];
bool chk[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    for(int i=0;i<N;i++) d[i] = -1;
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
            to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
        to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        for(int i=0;i<N;i++) ptr[i] = 0;
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

void clear() {
    for(int i=0;i<MAXN;i++) g[i].clear();
    e.clear();
}

queue<int> que;
void trace(int v) {
    for (size_t l=0; l<g[v].size(); ++l) {
        int id = g[v][l];
        int to = e[id].b;
        int f = e[id].flow;
        int cap = e[id].cap;
        
        if (f == cap) continue;
        if (chk[to]) continue;
        
        chk[to] = true;
        que.push(to);
    }
}

int main() {
    int i;
    int n, m;
    int x, y;
    int src, sink;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&src,&sink);
    s = 0;
    t = n * 2 + 1;
    N = n * 2 + 2;
    add_edge(s, src, INF);
    add_edge(sink + n, t, INF);
    for (i=1;i<=n;i++) {
        scanf("%d",&o[i]);
        add_edge(i, i + n, o[i]);
    }
    for(i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        add_edge(x+n, y, o[x]);
        add_edge(y+n, x, o[y]);
    }
    int flw = dinic();
    
    chk[s] = true;
    que.push(s);
    int here;
    while(que.size()) {
        here = que.front();
        que.pop();
        
        trace(here);
    }
    
    for(i=1;i<=n;i++) if (chk[i] && !chk[i+n]) printf("%d ",i);
    return 0;
}