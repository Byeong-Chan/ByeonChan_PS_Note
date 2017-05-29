#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > GroupC;
vector<pair<int, int> > GroupD;
const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;

int o[210][210];
int ans[210];
int n1, n2, edges, last[MAXN1], pre[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    pre[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = pre[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = pre[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || (!vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}
int main() {
    char s1, s2;
    int t;
    int i, j, dog, cat, n;
    int num1, num2;
    pair<int, int> tmp1, tmp2;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d%*c",&cat,&dog,&n);
        GroupC.clear();
        GroupD.clear();
        for(i=0;i<n;i++) {
            scanf("%c%d %c%d%*c",&s1,&num1,&s2,&num2);
            if(s1 == 'C') GroupC.push_back(make_pair(num1, num2));
            else GroupD.push_back(make_pair(num1, num2));
        }
        init((int)GroupC.size(), (int)GroupD.size());
        for(i=0;i<GroupC.size();i++) {
            tmp1 = GroupC[i];
            for(j=0;j<GroupD.size();j++) {
                tmp2 = GroupD[j];
                if(tmp1.first == tmp2.second || tmp1.second == tmp2.first) addEdge(i, j);
            }
        }
        printf("%d\n",n-maxMatching());
    }
    return 0;
}