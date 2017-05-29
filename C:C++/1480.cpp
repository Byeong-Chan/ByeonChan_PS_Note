#include <cstdio>
#include <algorithm>
using namespace std;
int dp[10000][11];
int o[13];
int main() {
    int i, j, k, l;
    int n, m, c;
    int T;
    int p;
    int ans = 0;
    scanf("%d %d %d",&n,&m,&c);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    T = 1 << n;
    for(i=0;i<T;i++) for(j=0;j<=m;j++) dp[i][j] = 0x7fffffff;
    dp[0][0] = 0;
    for(i=0;i<n;i++) {
        for(j=0;j<T;j++) {
            l = j;
            int cnt = 0;
            while(l) {
                cnt += l & 1;
                l >>= 1;
            }
            if(cnt != i) continue;
            for(k=0;k<n;k++) {
                if(j & (1 << k)) continue;
                p = j | (1 << k);
                for(l=0;l<m;l++) {
                    if(dp[j][l] == 0x7fffffff) continue;
                    if(dp[j][l] + o[k] > c) {
                        if(o[k] > c) continue;
                        dp[p][l+1] = min(dp[p][l+1], o[k]);
                    }
                    else {
                        dp[p][l] = min(dp[p][l], dp[j][l] + o[k]);
                        dp[p][l+1] = min(dp[p][l+1], o[k]);
                    }
                }
            }
        }
        for(j=0;j<T;j++) {
            l = j;
            int cnt = 0;
            while(l) {
                cnt += l & 1;
                l >>= 1;
            }
            
            for(l=0;l<m;l++) {
                if(dp[j][l] == 0x7fffffff) continue;
                if(ans < cnt) ans = cnt;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}