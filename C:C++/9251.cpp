#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1010][1010];
char o[1010], u[1010];
int main() {
    int i, j;
    int n, m;
    scanf("%s",o+1);
    n = (int)strlen(o+1);
    scanf("%s",u+1);
    m = (int)strlen(u+1);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(o[i] == u[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}