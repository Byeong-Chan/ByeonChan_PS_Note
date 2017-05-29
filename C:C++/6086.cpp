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
    Dinic dn;
    dn.init(256, 65, 90);
    int i, n;
    int z;
    char x, y;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("\n%c %c %d",&x,&y,&z);
        dn.addEdge(x, y, z);
    }
    printf("%d\n",dn.maxFlow());
    return 0;
}