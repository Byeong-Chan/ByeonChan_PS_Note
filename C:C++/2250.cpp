#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
int cnt = 0;
list<int> len[10010];
struct node {
    int l;
    int r;
}o[10010];
void dfs(int depth, int num) {
    if(num == -1) return;
    dfs(depth+1, o[num].l);
    cnt++;
    len[depth].push_back(cnt);
    dfs(depth+1, o[num].r);
}
int moth[10010];
int main() {
    int i, n;
    int x, y, z;
    int ans = 1, pos = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d %d %d",&x,&y,&z);
        o[x].l = y;
        o[x].r = z;
        if(y != -1) moth[y]++;
        if(z != -1) moth[z]++;
    }
    for(i=1;i<=n;i++) {
        if(moth[i] > 0) continue;
        dfs(0, i);
        break;
    }
    for(i=0;i<=n;i++) {
        if(len[i].size() == 0) continue;
        if(ans < len[i].back() - len[i].front() + 1) {
            pos = i + 1;
            ans = len[i].back() - len[i].front() + 1;
        }
    }
    printf("%d %d\n",pos,ans);
    return 0;
}