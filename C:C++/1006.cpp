#include <cstdio>
#include <algorithm>
using namespace std;
int dp[4][4], tmp[4][4];
int o[2][10010];
int main() {
    int i, j, k;
    int n, w;
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n, &w);
        for(i=0;i<2;i++) {
            for(j=0;j<n;j++) {
                scanf("%d",&o[i][j]);
            }
        }
        if(n == 1) {
            if(o[0][0] + o[1][0] <= w) printf("1\n");
            else printf("2\n");
            continue;
        }
        
        for(i=0;i<4;i++) for(j=0;j<4;j++) dp[i][j] = 20001;
        
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 1;
        if(o[0][0] + o[1][0] <= w) dp[0][3] = 1;
        else dp[0][3] = 2;
        
        if(o[0][0] + o[0][n-1] <= w) {
            dp[1][1] = 1;
            dp[1][3] = 2;
        }
        
        if(o[1][0] + o[1][n-1] <= w) {
            dp[2][2] = 1;
            dp[2][3] = 2;
        }
        
        if(o[0][0] + o[0][n-1] <= w && o[1][0] + o[1][n-1] <= w) dp[3][3] = 2;
        
        for(k=1;k<n-1;k++) {
            for(i=0;i<4;i++) for(j=0;j<4;j++) tmp[i][j] = dp[i][j];
            for(i=0;i<4;i++) for(j=0;j<4;j++) dp[i][j] = 20001;
            for(i=0;i<4;i++) {
                dp[i][0] = min(dp[i][0], tmp[i][3]);
                
                dp[i][1] = min(dp[i][1], tmp[i][3] + 1);
                if(o[0][k] + o[0][k-1] <= w) dp[i][1] = min(dp[i][1], tmp[i][2] + 1);
                
                dp[i][2] = min(dp[i][2], tmp[i][3] + 1);
                if(o[1][k] + o[1][k-1] <= w) dp[i][2] = min(dp[i][2], tmp[i][1] + 1);
                
                if(o[0][k] + o[1][k] <= w) dp[i][3] = min(dp[i][3], tmp[i][3] + 1);
                else dp[i][3] = min(dp[i][3], tmp[i][3] + 2);
                if(o[0][k] + o[0][k-1] <= w) dp[i][3] = min(dp[i][3], tmp[i][2] + 2);
                if(o[1][k] + o[1][k-1] <= w) dp[i][3] = min(dp[i][3], tmp[i][1] + 2);
                if(o[0][k] + o[0][k-1] <= w && o[1][k] + o[1][k-1] <= w) dp[i][3] = min(dp[i][3], tmp[i][0] + 2);
            }
        }
        int ans;
        
        if(o[0][k] + o[1][k] <= w) ans = dp[0][3] + 1;
        else ans = dp[0][3] + 2;
        if(ans > dp[0][2] + 2 && o[0][k] + o[0][k-1] <= w) ans = dp[0][2] + 2;
        if(ans > dp[0][1] + 2 && o[1][k] + o[1][k-1] <= w) ans = dp[0][1] + 2;
        if(ans > dp[0][0] + 2 && o[0][k] + o[0][k-1] <= w && o[1][k] + o[1][k-1] <= w) ans = dp[0][0] + 2;
        
        if(ans > dp[1][3] + 1) ans = dp[1][3] + 1;
        if(ans > dp[1][1] + 1 && o[1][k] + o[1][k-1] <= w) ans = dp[1][1] + 1;
        
        if(ans > dp[2][3] + 1) ans = dp[2][3] + 1;
        if(ans > dp[2][2] + 1 && o[0][k] + o[0][k-1] <= w) ans = dp[2][2] + 1;
        
        if(ans > dp[3][3]) ans = dp[3][3];
        
        printf("%d\n",ans);
    }
    return 0;
}