#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;
int dp[5][5], tmp[5][5];
int hap[5][5] = {1, 2, 2, 2, 2,
                 3, 1, 3, 4, 3,
                 3, 3, 1, 3, 4,
                 3, 4, 3, 1, 3,
                 3, 3, 4, 3, 1};
int main() {
    int i, j;
    int x, pre;
    int ans = INF;
    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            dp[i][j] = INF;
        }
    }
    pre = 0;
    dp[0][0] = 0;
    while(1) {
        scanf("%d",&x);
        if(x == 0) break;
        for(i=0;i<5;i++) {
            for(j=0;j<5;j++) {
                tmp[i][j] = dp[i][j];
                dp[i][j] = INF;
            }
        }
        for(i=0;i<5;i++) {
            if(x == i) continue;
            if(tmp[pre][i] != INF) dp[x][i] = min(dp[x][i], tmp[pre][i] + hap[pre][x]);
            if(tmp[i][pre] != INF) dp[i][x] = min(dp[i][x], tmp[i][pre] + hap[pre][x]);
        }
        for(i=0;i<5;i++) {
            if(pre == x) continue;
            if(tmp[pre][i] != INF) dp[pre][x] = min(dp[pre][x], tmp[pre][i] + hap[i][x]);
            if(tmp[i][pre] != INF) dp[x][pre] = min(dp[x][pre], tmp[i][pre] + hap[i][x]);
        }
        pre = x;
    }
    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            if(ans > dp[i][j]) ans = dp[i][j];
        }
    }
    printf("%d\n",ans);
    return 0;
}