#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct edge_info {
    int dest;
    int cost;
    edge_info() {}
    edge_info(int idest, int icost) {
        dest = idest;
        cost = icost;
    }
};
struct node {
    int pos;
    int d;
    node() {}
    node(int ipos, int id) {
        pos = ipos;
        d = id;
    }
    bool operator < (const node &a) const {
        return d > a.d;
    }
};

void shortest_path(int n, int s, int *dist, vector<vector<edge_info> > &edge) {
    int i;
    node here;
    priority_queue<node> q;
    for(i=1;i<=n;i++) dist[i] = INT_MAX;
    dist[s] = 0;
    q.push(node(s, 0));
    while (q.size()) {
        here = q.top();
        q.pop();
        if(dist[here.pos] < here.d) continue;
        dist[here.pos] = here.d;
        for(i=0;i<edge[here.pos].size();i++) {
            edge_info &nxt = edge[here.pos][i];
            q.push(node(nxt.dest, nxt.cost + here.d));
        }
    }
}
int main() {
    int i;
    int n, m;
    int x, y, z;
    int a, b;
    int ans1 = 0, ans2 = 0;
    int *dist;
    vector<vector<edge_info> > edge;
    scanf("%d %d",&n,&m);
    edge.resize(n + 1);
    dist = (int *)calloc(n + 1, sizeof(int));
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        edge[x].push_back(edge_info(y,z));
        edge[y].push_back(edge_info(x,z));
    }
    scanf("%d %d",&a,&b);
    shortest_path(n, 1, dist, edge);
    if(dist[a] == INT_MAX && dist[b] == INT_MAX) {
        printf("-1");
        return 0;
    }
    ans1 += dist[a];
    ans2 += dist[b];
    shortest_path(n, a, dist, edge);
    if((ans1 == INT_MAX || dist[b] == INT_MAX) && (ans2 == INT_MAX || dist[n] == INT_MAX)) {
        printf("-1\n");
        return 0;
    }
    if(ans1 != INT_MAX) ans1 += dist[b];
    if(ans2 != INT_MAX) ans2 += dist[n];
    shortest_path(n, b, dist, edge);
    if((ans1 == INT_MAX || dist[n] == INT_MAX) && (ans2 == INT_MAX || dist[a] == INT_MAX)) {
        printf("-1\n");
        return 0;
    }
    if(ans1 != INT_MAX) ans1 += dist[n];
    if(ans2 != INT_MAX) ans2 += dist[a];
    
    printf("%d\n",min(ans1, ans2));
    return 0;
}