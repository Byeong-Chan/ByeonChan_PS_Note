#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
long long oil[2510];
long long dp[2510];
int path[2510][2510];
struct node {
    int pos;
    long long val;
    bool operator< (const node &a) const {
        return this->val > a.val;
    }
    void inp(int a, int b) {
        pos = a;
        val = b;
    }
};
priority_queue<node> q;
vector<node> edge[2510];
int main() {
    int i, j;
    int n, m;
    int x, y, z;
    node tmp, nxt;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%lld",&oil[i]);
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        tmp.inp(y, z);
        edge[x].push_back(tmp);
        
        tmp.inp(x, z);
        edge[y].push_back(tmp);
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) path[i][j] = -1;
        nxt.inp(i, 0);
        q.push(nxt);
        while(q.size()) {
            tmp = q.top();
            q.pop();
            if(path[i][tmp.pos] + 1) continue;
            path[i][tmp.pos] = (int)tmp.val;
            
            for(j=0;j<edge[tmp.pos].size();j++) {
                nxt.pos = edge[tmp.pos][j].pos;
                nxt.val = edge[tmp.pos][j].val + tmp.val;
                if (path[i][nxt.pos] + 1) continue;
                q.push(nxt);
            }
        }
    }
    for(i=1;i<=n;i++) dp[i] = -1;
    nxt.inp(1, 0);
    q.push(nxt);
    while(q.size()) {
        tmp = q.top();
        q.pop();
        if(dp[tmp.pos] + 1) continue;
        dp[tmp.pos] = tmp.val;
        
        for(i=1;i<=n;i++) {
            if (i == tmp.pos) continue;
            nxt.pos = i;
            nxt.val = oil[tmp.pos] * path[tmp.pos][i] + tmp.val;
            if (dp[i] + 1) continue;
            q.push(nxt);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}