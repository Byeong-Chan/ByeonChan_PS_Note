#include <cstdio>
#include <vector>
using namespace std;
vector<int> edge[110];
bool chk[110];
int dfs(int u) {
    int tmp = 0;
    chk[u] = true;
    for(auto &v : edge[u]) {
        if(chk[v]) continue;
        tmp += dfs(v);
    }
    return tmp + 1;
}
int main() {
    int i;
    int x, y;
    int n, m;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    printf("%d\n",dfs(1)-1);
    return 0;
}