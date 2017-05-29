#include <cstdio>
#include <vector>
using namespace std;
vector<int> edge[300010];
int bi[300010];
bool chk[300010];
bool sw;
void dfs(int u) {
    chk[u] = true;
    for(auto &v : edge[u]) {
        if(!chk[v]) {
            bi[v] = bi[u] ^ 1;
            dfs(v);
        }
        if(bi[u] == bi[v]) sw = true;
    }
}
int main() {
    int i, n, m, t;
    int x, y;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++) {
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        sw = false;
        for(i=1;i<=n;i++) dfs(i);
        if(sw) printf("NO\n");
        else printf("YES\n");
        
        for(i=1;i<=n;i++) chk[i] = false;
        for(i=1;i<=n;i++) bi[i] = 0;
        for(i=1;i<=n;i++) edge[i].clear();
    }
    return 0;
}