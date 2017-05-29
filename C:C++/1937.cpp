#include <cstdio>
#include <algorithm>
using namespace  std;
struct node {
    int x;
    int y;
    int val;
    bool operator< (const node &a) const {
        return this->val < a.val;
    }
}o[250010];
int pos[510][510];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dp[250010];
int main() {
    int i, j, n;
    int N, cnt = 0;
    int x, y;
    int tmp, ans = 1;
    scanf("%d",&n);
    N = n*n;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&x);
            o[cnt].x = i;
            o[cnt].y = j;
            o[cnt++].val = x;
        }
    }
    sort(o,o+N);
    for(i=0;i<N;i++) pos[o[i].x][o[i].y] = i;
    for(i=0;i<N;i++) {
        dp[i] = 1;
        for(j=0;j<4;j++) {
            x = o[i].x + dx[j];
            y = o[i].y + dy[j];
            if(x < 0 || y < 0 || x >= n || y >= n) continue;
            if(o[pos[x][y]].val >= o[i].val) continue;
            tmp = dp[pos[x][y]] + 1;
            dp[i] = max(tmp, dp[i]);
            ans = max(ans, tmp);
        }
    }
    printf("%d\n",ans);
    return 0;
}