#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int moth[1000010];
int son[1000010];
int magic[1000010];

struct node {
    long long x;
    int cnt;
    node() {}
    node(long long ix, int icnt) {
        x = ix;
        cnt = icnt;
    }
    bool operator < (const node &a) const {
        if(x/cnt != a.x/a.cnt) return x/cnt < a.x/a.cnt;
        else {
            long long k1 = x%cnt;
            long long k2 = a.x%a.cnt;
            
            return k1*a.cnt < k2*cnt;
        }
    }
    node operator + (const node &a) const {
        return node(x*a.x, cnt+a.cnt);
    }
};

node dp[1000010][2];
vector<int> edge[1000010];
queue<int> q;

long long gcd(long long a, long long b) {
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

void bfs(int u) {
    int v;
    queue<int> que;
    que.push(u);
    while(que.size()) {
        u = que.front();
        que.pop();
        for(int i = 0; i < edge[u].size();i++) {
            v = edge[u][i];
            if(moth[v]) continue;
            moth[v] = u;
            que.push(v);
            son[u]++;
        }
        if(son[u] == 0) q.push(u);
    }
}
int main() {
    int i, n, x, y;
    //freopen("/Users/SeoByeongChan/Downloads/contest1_testdata/mag/mag.in.4b","rt",stdin);
    node ans((long long)0x7fffffff << 32, 1), tmp;
    scanf("%d",&n);
    for(i=0;i<n-1;i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(i=1;i<=n;i++) {
        scanf("%d", &magic[i]);
        if(node(magic[i], 1) < ans) ans = node(magic[i], 1);
        dp[i][1] = dp[i][0] = node(magic[i], 1);
    }
    moth[1] = -1;
    bfs(1);
    while(q.size()) {
        int here = q.front();
        int nxt = moth[here];
        q.pop();
        if(dp[here][0] < ans) ans = dp[here][0];
        if(dp[here][1] < ans) ans = dp[here][1];
        if(nxt == -1) break;
        if(--son[nxt] == 0) q.push(nxt);
        
        tmp = dp[here][0] + dp[nxt][0];
        if(tmp < ans) ans = tmp;
        
        tmp = dp[here][1] + dp[nxt][0];
        if(tmp < ans) ans = tmp;
        
        tmp = dp[here][0] + dp[nxt][1];
        if(tmp < ans) ans = tmp;
        
        tmp = dp[here][1] + dp[nxt][1];
        if(tmp < ans) ans = tmp;
        
        if(magic[nxt] == 1) {
            if(dp[here][0] + node(1, 1) < dp[nxt][0]) dp[nxt][0] = dp[here][0] + node(1, 1);
            if(dp[here][1] + node(1, 1) < dp[nxt][1]) dp[nxt][1] = dp[here][1] + node(1, 1);
        }
        else if(dp[here][0].x == 1) {
            if(dp[here][0] + node(magic[nxt], 1) < dp[nxt][1]) dp[nxt][1] = dp[here][0] + node(magic[nxt], 1);
            if(dp[here][1] + node(magic[nxt], 1) < dp[nxt][1]) dp[nxt][1] = dp[here][1] + node(magic[nxt], 1);
        }
        else {
            if(dp[here][0] + node(magic[nxt], 1) < dp[nxt][1]) dp[nxt][1] = dp[here][0] + node(magic[nxt], 1);
            if(dp[here][1] + node(magic[nxt], 1) < dp[nxt][1]) dp[nxt][1] = dp[here][1] + node(magic[nxt], 1);
        }
    }
    long long sub = gcd(ans.x, ans.cnt);
    ans = node(ans.x/sub, (int)(ans.cnt/sub));
    printf("%lld/%d\n",ans.x,ans.cnt);
    return 0;
}