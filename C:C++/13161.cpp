#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 50010;
const int INF = 0x7fffffff;

struct edge {
    int a, b, cap, flow;
};

int N, s, t, d[MAXN], ptr[MAXN], q[MAXN];
int ans[MAXN];
bool chk[MAXN];
vector<edge> e;
vector<int> g[MAXN];

vector<int> jinbo;
vector<int> bosu;
int sad[510][510];
bool freedom[510];

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

// mincut trace
queue<int> que;
void div(int v) {
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

void mincut(int n) {
    chk[s] = true;
    que.push(s);
    int here;
    while(que.size()) {
        here = que.front();
        que.pop();
        
        div(here);
    }
    
    // all edge
    for(int i=1;i<=n;i++) {
        if (!freedom[i]) continue;
        if (chk[s] == 1 && chk[i] == 0) bosu.push_back(i);
        else if (chk[i] == 1 && chk[t] == 0) jinbo.push_back(i);
    }
}

int main() {
    int i, j, n;
    int x;
    scanf("%d",&n);
    s = 0;
    t = n + 1;
    N = n + 2;
    for(i=1;i<=n;i++) {
        scanf("%d",&x);
        if(x == 1) {jinbo.push_back(i); continue;}
        else if(x == 2) {bosu.push_back(i); continue;}
        freedom[i] = true;
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%d",&sad[i][j]);
        }
    }
    int sum = 0;
    for(i=0;i<jinbo.size();i++) {
        for(j=0;j<bosu.size();j++) {
            sum += sad[jinbo[i]][bosu[j]];
        }
    }
    if (jinbo.size() == 0 || bosu.size() == 0) {
        if(bosu.size() == 0) {
            printf("0\n");
            for(i=1;i<=n;i++) printf("%d ",i);
            printf("\n");
            printf("\n");
            return 0;
        }
        printf("0\n");
        printf("\n");
        for(i=1;i<=n;i++) printf("%d ",i);
        printf("\n");
        return 0;
    }
    int fl;
    for(i=1;i<=n;i++) {
        if (!freedom[i]) continue;
        fl = 0;
        for (j=0;j<jinbo.size();j++) fl += sad[i][jinbo[j]];
        add_edge(s, i, fl);
        
        fl = 0;
        for (j=0;j<bosu.size();j++) fl += sad[i][bosu[j]];
        add_edge(i, t, fl);
        
        for(j=1;j<=n;j++) if(j!=i && freedom[j]) add_edge(i, j, sad[i][j]);
    }
    printf("%d\n",dinic()+sum);
    mincut(n);
    sort(jinbo.begin(), jinbo.end());
    sort(bosu.begin(), bosu.end());
    for(i=0;i<jinbo.size();i++) printf("%d ",jinbo[i]);
    printf("\n");
    for(i=0;i<bosu.size();i++) printf("%d ",bosu[i]);
    printf("\n");
    return 0;
}