#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    int pos;
    int cst;
    bool operator< (const node &a) const {
        return this->cst > a.cst;
    }
};
int o[101010];
int u[101010];
vector<node> edge[101010];
vector<node> inverse_edge[101010];
priority_queue<node> q;
int main() {
    int i;
    int n, k, m;
    int x, y, z;
    node here, nxt;
    scanf("%d %d %d",&n,&m,&k);
    for (i=1;i<=m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        edge[x].push_back({y, z});
        inverse_edge[y].push_back({x, z});
    }
    q.push({k, 1});
    while (q.size()) {
        here = q.top();
        q.pop();
        if (o[here.pos]) continue;
        o[here.pos] = here.cst;
        
        for (i=0;i<edge[here.pos].size();i++) {
            nxt = edge[here.pos][i];
            q.push({nxt.pos, here.cst + nxt.cst});
        }
    }
    
    q.push({k, 1});
    while (q.size()) {
        here = q.top();
        q.pop();
        if (u[here.pos]) continue;
        u[here.pos] = here.cst;
        
        for (i=0;i<inverse_edge[here.pos].size();i++) {
            nxt = inverse_edge[here.pos][i];
            q.push({nxt.pos, here.cst + nxt.cst});
        }
    }
    int ans = 0;
    for(i=1;i<=n;i++) {
        x = o[i] + u[i] - 2;
        if (ans < x) ans = x;
    }
    printf("%d",ans);
    return 0;
}