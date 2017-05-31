#include <cstdio>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(int u, int dest, int len, vector<vector<int> > &adj, list<int> &ans, list<int>::iterator &concat) {
    if(len != 0) {
        ans.insert(concat, u);
        if(u == dest) return;
    }
    int size = (int)adj[u].size();
    for(int i=0;i<size;i++) {
        if(adj[u][i] == 0) continue;
        adj[u][i]--;
        adj[i][u]--;
        dfs(i, dest, len + 1, adj, ans, concat);
        return;
    }
}
int main() {
    int n, start = -1;
    scanf("%d",&n);
    list<int> ans;
    vector<vector<int> > adj(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            scanf("%d",&adj[i][j]);
            sum += adj[i][j];
        }
        if(sum != 0 && start == -1) start = i;
        if(sum & 1) {
            printf("-1\n");
            return 0;
        }
    }
    ans.push_back(start);
    for(auto pos = ans.begin(); pos != ans.end(); pos++) {
        auto concat = ++pos;
        pos--;
        dfs(*pos, *pos, 0, adj, ans, concat);
    }
    for(auto v = ans.begin(); v != ans.end(); v++) printf("%d ",*v + 1);
    printf("\n");
    return 0;
}
