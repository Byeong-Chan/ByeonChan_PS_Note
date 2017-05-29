#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> edge[100010];
vector<int> trace;
vector<int> phnode[100010];
int phnum[100010];
int num[100010];
int cnt;
int ph = 0;
bool in[100010];
void dfs(int u) {
    int root = cnt + 1;
    num[u] = ++cnt;
    trace.push_back(u);
    for(auto i : edge[u]) {
        if(num[i] == 0) dfs(i);
        num[u] = min(num[u], num[i]);
    }
    if(root == num[u]) {
        ph++;
        while(trace.size() > 0 && num[trace.back()] >= num[u]) {
            phnode[ph].push_back(trace.back());
            num[trace.back()] = 0x7fffffff;
            phnum[trace.back()] = ph;
            trace.pop_back();
        }
    }
}
void scc(int n) {
    for(int i=1;i<=n;i++) {
        if(num[i]) continue;
        dfs(i);
    }
}
int main() {
    int i;
    int n, m;
    int x, y;
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++) {
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
        }
        scc(n);
        for(i=1;i<=ph;i++) {
            for(auto j : phnode[i]) {
                for(auto k : edge[j]) {
                    if(phnum[k] == i) continue;
                    in[phnum[k]] = true;
                }
            }
        }
        int ans = 0;
        for(i=1;i<=ph;i++) {
            if(in[i]) continue;
            ans++;
        }
        for(i=1;i<=ph;i++) phnode[i].clear(), in[i] = false;
        for(i=1;i<=n;i++) edge[i].clear(), num[i] = 0;
        ph = cnt = 0;
        printf("%d\n",ans);
    }
    return 0;
}