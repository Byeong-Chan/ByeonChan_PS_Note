#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 2010;
const int INF = 0x7fffffff;

struct Dinic {
    int sink;
    int source;
    int N;
    int q[MAXN];
    int level[MAXN];
    int ptr[MAXN];
    bool chk[MAXN];
    struct edge_info {
        int cap;
        int from;
        int to;
        int f;
    };
    vector<vector<int> > g;
    vector<edge_info> edge;
    void init(int iN, int isource, int isink) {
        N = iN;
        g.resize(iN);
        sink = isink;
        source = isource;
    }
    void add_edge(int x, int y, int cap) {
        edge_info tmp;
        tmp.cap = cap;
        tmp.from = x;
        tmp.to = y;
        tmp.f = 0;
        g[x].push_back((int)edge.size());
        edge.push_back(tmp);
        
        tmp.cap = 0;
        tmp.from = y;
        tmp.to = x;
        tmp.f = 0;
        g[y].push_back((int)edge.size());
        edge.push_back(tmp);
    }
    bool bfs() {
        int i, u;
        int qt = 0, qh = 0;
        for(i=0;i<N;i++) level[i] = -1;
        level[source] = 0;
        q[qt++] = source;
        while(qh < qt) {
            u = q[qh++];
            for(i=0;i<g[u].size();i++) {
                edge_info &v = edge[g[u][i]];
                if(level[v.to] + 1) continue;
                if(v.cap > v.f) {
                    level[v.to] = level[u] + 1;
                    q[qt++] = v.to;
                }
            }
        }
        return level[sink] != -1;
    }
    int dfs(int u, int flow) {
        if (!flow) return 0;
        if (u == sink) return flow;
        for(;ptr[u]<(int)g[u].size();ptr[u]++) {
            int v = g[u][ptr[u]];
            
            if(level[edge[v].to] != level[u] + 1) continue;
            int pushed = dfs(edge[v].to, min(flow, edge[v].cap - edge[v].f));
            
            if(pushed) {
                edge[v].f += pushed;
                edge[v^1].f -= pushed;
                return pushed;
            }
        }
        return 0;
    }
    int max_flow() {
        int i;
        int flow = 0;
        int pushed;
        while (1) {
            for(i=0;i<N;i++) ptr[i] = 0;
            if (!bfs()) break;
            while((pushed = dfs(source, INF))) flow += pushed;
        }
        return flow;
    }
    void clear() {
        int i;
        edge.clear();
        for(i=0;i<N;i++) g[i].clear();
        g.clear();
    }
    void trace(int v) {
        for (size_t l=0; l<g[v].size(); ++l) {
            int id = g[v][l];
            int to = edge[id].to;
            int f = edge[id].f;
            
            // Please trace flow here
        }
    }
    
    // mincut trace
    int div(int v, int qt) {
        for (size_t l=0; l<g[v].size(); ++l) {
            int id = g[v][l];
            int to = edge[id].to;
            int f = edge[id].f;
            int cap = edge[id].cap;
            
            if (f == cap) continue;
            if (chk[to]) continue;
            
            chk[to] = true;
            q[qt++] = to;
        }
        return qt;
    }
    
    void mincut(int n) {
        int qt = 0, qh = 0;
        chk[source] = true;
        q[qt++] = source;
        int here;
        while(qh < qt) {
            here = q[qh++];
            
            qt = div(here, qt);
        }
        
        // all edge
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (i != j && chk[i] && !chk[j]) printf("%d %d\n",i,j);
            }
        }
    }
};
Dinic dec;
int main() {
    int i, j;
    int n, m, k;
    int sz, x;
    scanf("%d %d %d", &n, &m, &k);
    dec.init(n+m+3, 0, n+m+1);
    dec.add_edge(0, n+m+2, k);
    for(i=1;i<=n;i++) dec.add_edge(0, i, 1);
    for(i=1;i<=n;i++) dec.add_edge(n+m+2, i, m);
    for(i=1;i<=n;i++) {
        scanf("%d",&sz);
        for(j=0;j<sz;j++) {
            scanf("%d",&x);
            dec.add_edge(i, n+x, 1);
        }
    }
    for(i=n+1;i<=n+m;i++) dec.add_edge(i, n+m+1, 1);
    printf("%d\n",dec.max_flow());
    return 0;
}