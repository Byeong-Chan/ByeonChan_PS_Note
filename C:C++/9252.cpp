#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1010][1010];
char o[1010], u[1010];
char moth[1010][1010];
char ans[1010];
int main() {
    int i, j;
    int n, m;
    scanf("%s",o+1);
    n = (int)strlen(o+1);
    scanf("%s",u+1);
    m = (int)strlen(u+1);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(dp[i][j] < dp[i-1][j]) {
                dp[i][j] = dp[i-1][j];
                moth[i][j] = 'd';
            }
            if(dp[i][j] < dp[i][j-1]) {
                dp[i][j] = dp[i][j-1];
                moth[i][j] = 'l';
            }
            if(o[i] == u[j] && dp[i][j] < dp[i-1][j-1] + 1) {
                dp[i][j] = dp[i-1][j-1] + 1;
                moth[i][j] = 'p';
            }
        }
    }
    printf("%d\n",dp[n][m]);
    int di = n, dj = m;
    int cnt = 0;
    while(di && dj) {
        char tmp = moth[di][dj];
        if(tmp == 0) break;
        if(tmp == 'd') di--;
        if(tmp == 'l') dj--;
        if(tmp == 'p') {
            ans[cnt++] = o[di];
            di--;
            dj--;
        }
    }
    reverse(ans, ans+cnt);
    printf("%s\n",ans);
    return 0;
}