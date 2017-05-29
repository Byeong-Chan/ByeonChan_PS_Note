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
vector<node> edge[101010];
priority_queue<node> q;
int main() {
    int i, j;
    int n, k, m;
    int x, y;
    node here, nxt;
    scanf("%d %d %d",&n,&k,&m);
    for (i=1;i<=m;i++) {
        y = n+i;
        for(j=0;j<k;j++) {
            scanf ("%d",&x);
            edge[x].push_back({y, 1});
            edge[y].push_back({x, 1});
        }
    }
    q.push({1, 1});
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
    o[n] /= 2;
    if (o[n]) printf("%d\n",o[n]+1);
    else printf("-1\n");
    return 0;
}