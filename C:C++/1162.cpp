#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dist[21][10010];
const int INF = 0x7fffffff;
struct node {
    int use;
    int pos;
    int d;
    node() {}
    node(int use, int pos, int d) {
        this->use = use;
        this->d = d;
        this->pos = pos;
    }
    bool operator< (const node &a) const {
        return d > a.d;
    }
};
struct edge {
    int to;
    int cost;
    edge() {}
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
priority_queue<node> pq;
vector<edge> e[10010];
bool visit[21][10010];
int main() {
    int i, j, n, m, k;
    int x, y, z;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        e[x].push_back(edge(y, z));
        e[y].push_back(edge(x, z));
    }
    
    for(i=0;i<=k;i++) for(j=2;j<=n;j++) dist[i][j] = INF;
    
    pq.push(node(0, 1, 0));
    while(!pq.empty()) {
        node here = pq.top();
        pq.pop();
        if(visit[here.use][here.pos]) continue;
        visit[here.use][here.pos] = true;
        for(auto &v : e[here.pos]) {
            if(here.use + 1 <= k && here.d < dist[here.use + 1][v.to]) {
                dist[here.use + 1][v.to] = here.d;
                pq.push(node(here.use + 1, v.to, here.d));
            }
            if(here.d + v.cost < dist[here.use][v.to]) {
                dist[here.use][v.to] = here.d + v.cost;
                pq.push(node(here.use, v.to, here.d + v.cost));
            }
        }
    }
    int ans = INF;
    for(i=0;i<=k;i++) if(ans > dist[i][n]) ans = dist[i][n];
    printf("%d\n",ans);
    return 0;
}