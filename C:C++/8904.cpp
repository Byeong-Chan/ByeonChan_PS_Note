#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
    int from;
    int to;
    int cap;
    int flow;
    Edge(){}
    Edge(int ifrom, int ito, int icap, int iflow): from(ifrom), to(ito), cap(icap), flow(iflow){}
};
struct Dinic {
public:
    void init(int N, int source, int sink) {
        this->N = N;
        this->source = source;
        this->sink = sink;
        g.resize(N+1);
        level.resize(N+1);
        pre.resize(N+1);
    }
    void addEdge(int from, int to, int cap) {
        g[from].push_back((int)edge.size());
        edge.push_back(Edge(from, to, cap, 0));
        g[to].push_back((int)edge.size());
        edge.push_back(Edge(to, from, 0, 0));
    }
    int bfs() {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;
        q.push(source);
        while(!q.empty()) {
            int here = q.front();
            q.pop();
            if(here == sink) continue;
            
            for(int &i : g[here]) {
                Edge &v = edge[i];
                if(level[v.to] + 1) continue;
                if(v.cap - v.flow == 0) continue;
                level[v.to] = level[v.from] + 1;
                q.push(v.to);
            }
        }
        return level[sink];
    }
    int dfs(int u, int pushed) {
        if(u == sink) return pushed;
        for(; pre[u] < g[u].size(); pre[u]++) {
            Edge &v = edge[g[u][pre[u]]];
            if(level[v.from] + 1 != level[v.to]) continue;
            if(v.cap - v.flow == 0) continue;
            int tmp = dfs(v.to, min(v.cap - v.flow, pushed));
            if(tmp > 0) {
                Edge &inv = edge[g[u][pre[u]] ^ 1];
                v.flow += tmp;
                inv.flow -= tmp;
                return tmp;
            }
        }
        return 0;
    }
    int maxFlow() {
        int sum = 0;
        while(bfs()+1) {
            fill(pre.begin(), pre.end(), 0);
            while(1) {
                int tmp = dfs(source, 0x7fffffff);
                if(tmp == 0) break;
                sum += tmp;
            }
        }
        return sum;
    }
    void clear() {
        edge.clear();
        level.clear();
        pre.clear();
        for(vector<int> &i : g) i.clear();
        g.clear();
    }
    vector<Edge> &getEdge() {
        return edge;
    }
private:
    int N;
    int source;
    int sink;
    queue<int> q;
    vector<Edge> edge;
    vector<int> level;
    vector<int> pre;
    vector<vector<int> > g;
};
int main() {
    int test_case;
    int l;
    int i, j, n, m;
    int w;
    int all;
    int sink;
    int cnt;
    int st, ed;
    int source, N;
    vector<vector<int> > ans(510, vector<int>(510));
    Dinic dec;
    scanf("%d", &test_case);
    while (test_case--) {
        scanf("%d %d", &m, &n);
        
        source = 0;
        sink = n + 501;
        N = sink + 1;
        dec.init(N, source, sink);
        all = 0;
        for (i=1;i<=500;i++) dec.addEdge(0, i, m);
        for (i=501;i<sink;i++) {
            scanf("%d %d %d",&st,&w,&ed);
            for (j=st;j<ed;j++) dec.addEdge(j, i, 1);
            dec.addEdge(i, sink, w);
            all += w;
        }
        
        if (dec.maxFlow() < all) {
            dec.clear();
            printf("0\n");
            continue;
        }
        
        for (Edge u : dec.getEdge()) {
            int id = u.from;
            int to = u.to;
            int f = u.flow;
            if (id <= 500 && to > 500 && to < sink) {
                if (f == 1) {
                    for(l=id;l<id+f;l++) ans[to-500][l] = 1;
                }
            }
        }
        for(i=1;i<=n;i++) {
            cnt = 0;
            st = ed = -1;
            for(j=1;j<=501;j++) {
                if(ans[i][j]) {
                    if (st == -1) st = ed = j;
                    else ed++;
                }
                else {
                    if(st != -1) cnt++;
                    st = -1;
                }
            }
            
            st = ed = -1;
            printf("%d ",cnt);
            for(j=1;j<=501;j++) {
                if(ans[i][j]) {
                    if (st == -1) st = ed = j;
                    else ed++;
                }
                else {
                    if(st != -1) printf("%d %d ",st,ed+1);
                    st = -1;
                }
                ans[i][j] = false;
            }
            printf("\n");
        }
        dec.clear();
    }
    return 0;
}