#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[4010][4010];
char o[4010];
char u[4010];
int main() {
    int i, j;
    int n, m;
    int ans = 0;
    scanf("%s",o+1);
    scanf("%s",u+1);
    
    n = (int)strlen(o+1);
    m = (int)strlen(u+1);
    
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(o[i] != u[j]) continue;
            dp[i][j] = dp[i-1][j-1] + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d",ans);
    return 0;
}