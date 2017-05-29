#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

struct node {
    int pos;
    int val;
    node() {}
    node(int ipos, int ival) {
        pos = ipos;
        val = ival;
    }
    bool operator < (const node &a) const {
        return val > a.val;
    }
};
struct info {
    int v;
    int val;
    info() {}
    info(int iv, int ival) {
        v = iv;
        val = ival;
    }
};
int d[200010];
vector<info> edge[200010];
priority_queue<node> pq;

int main() {
    int i, n, m;
    int start;
    int x, y, z;
    
    scanf("%d %d", &n, &m);
    scanf("%d", &start);
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        edge[x].push_back(info(y,z));
    }
    pq.push(node(start, 0));
    fill(d+1, d+n+1, INF);
    while(pq.size()) {
        node here = pq.top();
        pq.pop();
        if(here.val >= d[here.pos]) continue;
        d[here.pos] = here.val;
        
        for(i=0;i<edge[here.pos].size();i++) {
            info &nxt = edge[here.pos][i];
            if(d[nxt.v] > here.val + nxt.val) pq.push(node(nxt.v, here.val + nxt.val));
        }
    }
    for(i=1;i<=n;i++) {
        if(d[i] == INF) printf("INF\n");
        else printf("%d\n",d[i]);
    }
    return 0;
}