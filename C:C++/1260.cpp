#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void dfs(int u, vector<vector<int> > &edge, vector<bool> &chk) {
    chk[u] = true;
    printf("%d ",u);
    for(auto v : edge[u]) {
        if(chk[v]) continue;
        dfs(v, edge, chk);
    }
}
void bfs(int u, vector<vector<int> > &edge, vector<bool> &chk) {
    queue<int> q;
    chk[u] = true;
    q.push(u);
    while(q.size()) {
        u = q.front();
        q.pop();
        printf("%d ",u);
        for(auto v : edge[u]) {
            if(chk[v]) continue;
            chk[v] = true;
            q.push(v);
        }
    }
}
int main() {
    int i, n, m, v;
    int x, y;
    scanf("%d %d %d",&n,&m,&v);
    vector<vector<int> > edge(n+10, vector<int>());
    for(i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(i=1;i<=n;i++) sort(edge[i].begin(), edge[i].end());
    
    vector<bool> chk(n+10, false);
    dfs(v, edge, chk);
    printf("\n");
    
    fill(chk.begin(), chk.end(), false);
    bfs(v, edge, chk);
    printf("\n");
    return 0;
}