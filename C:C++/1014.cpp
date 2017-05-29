#include <cstdio>
#include <algorithm>

using namespace std;

char o[12][12];
int dp[1<<11], tmp[1<<11];

int main() {
    int i, j, k, n, m;
    int nxt;
    int x, y;
    int maxd;
    int t;
    int ans;
    scanf("%d",&t);
    while(t--) {
        ans = 0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++) scanf("%s",o[i]);
        k = 1 << m;
        maxd = (1 << (m + 1)) - 1;
        
        int M = n * m;
        for(i=0;i<M;i++) {
            for(j=(1<<(m + 1))-1;j>=0;j--) {
                tmp[j] = dp[j];
                dp[j] = 0;
            }
            for(j=(1<<(m + 1))-1;j>=0;j--) {
                x = i / m;
                y = i % m;
                nxt = j >> 1;
                
                if(y == 0) {
                    if(((1 << 2) & j) == 0 && o[x][y] == '.') dp[nxt + k] = max(dp[nxt + k], tmp[j] + 1);
                    dp[nxt] = max(dp[nxt], tmp[j]);
                    continue;
                }
                if(y == m - 1) {
                    if(((1 << m) & j) == 0 && ((1 << 0) & j) == 0 && o[x][y] == '.') dp[nxt + k] = max(dp[nxt + k], tmp[j] + 1);
                    dp[nxt] = max(dp[nxt], tmp[j]);
                    continue;
                }
                if(((1 << m) & j) == 0 && ((1 << 2) & j) == 0 && ((1 << 0) & j) == 0 && o[x][y] == '.') dp[nxt + k] = max(dp[nxt + k], tmp[j] + 1);
                dp[nxt] = max(dp[nxt], tmp[j]);
            }
            for(j=(1<<(m + 1))-1;j>=0;j--) if(dp[j] > ans) ans = dp[j];
        }
        for(i=(1<<(m + 1))-1;i>=0;i--) tmp[i] = dp[i] = 0;
        printf("%d\n",ans);
    }
    return 0;
}