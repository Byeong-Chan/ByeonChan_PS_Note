#include <cstdio>
#include <vector>
using namespace std;

int height[23];
vector<int> edge[23];
void dfs(int u, int depth) {
    int i, v;
    height[u] = depth;
    for(i=0;i<edge[u].size();i++) {
        v = edge[u][i];
        if (height[v]) continue;
        dfs(v, depth + 1);
    }
}
int main() {
    int i, n;
    int moth;
    vector<int> root;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&moth);
        if(moth == -1 || moth == 0) {
            root.push_back(i);
            continue;
        }
        edge[moth].push_back(i);
    }
    for(i=0;i<root.size();i++) dfs(root[i], 1);
    for(i=1;i<=n;i++) printf("%d\n",height[i]-1);
    return 0;
}