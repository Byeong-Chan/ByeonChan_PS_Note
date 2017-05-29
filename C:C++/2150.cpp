#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> edge[10010];
vector<int> invedge[10010];
vector<int> phnode[10010];
vector<int> trace;
vector<int> node;
int arr[10010];
bool chk[10010];
bool chki[10010];
int cnt;
int ph = 0;
void dfs(int u) {
    chk[u] = true;
    for(auto i : edge[u]) {
        if(chk[i]) continue;
        dfs(i);
    }
    trace.push_back(u);
}
void invdfs(int u) {
    chki[u] = true;
    for(auto i : invedge[u]) {
        if(chki[i]) continue;
        invdfs(i);
    }
    node.push_back(u);
}
void scc(int n) {
    for(int i=1;i<=n;i++) {
        if(chk[i]) continue;
        dfs(i);
    }
    while(trace.size()) {
        int u = trace.back();
        trace.pop_back();
        
        if(!chki[u]) invdfs(u);
        if(node.size()) {
            ph++;
            while(node.size()) {
                phnode[ph].push_back(node.back());
                node.pop_back();
            }
        }
    }
}
bool cmp(int a, int b) {
    return phnode[a][0] < phnode[b][0];
}
int main() {
    int i;
    int n, m;
    int x, y;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++) {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        invedge[y].push_back(x);
    }
    scc(n);
    for(i=1;i<=ph;i++) arr[i-1] = i, sort(phnode[i].begin(), phnode[i].end());
    sort(arr, arr+ph, cmp);
    printf("%d\n",ph);
    for(i=0;i<ph;i++) {
        x = arr[i];
        for(auto i : phnode[x]) printf("%d ",i);
        printf("-1\n");
    }
}