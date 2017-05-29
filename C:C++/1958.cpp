#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char o[110], u[110], c[110];
int dp[110][110][110];
int di[6] = {-1, 0, 0, -1, -1, 0};
int dj[6] = {0, -1, 0, -1, 0, -1};
int dk[6] = {0, 0, -1, 0, -1, -1};
int main() {
    int n, m, p;
    int i, j, k, l;
    scanf("%s",o+1);
    n = (int)strlen(o+1);
    scanf("%s",u+1);
    m = (int)strlen(u+1);
    scanf("%s",c+1);
    p = (int)strlen(c+1);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            for(k=1;k<=p;k++) {
                for(l=0;l<6;l++) dp[i][j][k] = max(dp[i][j][k], dp[i+di[l]][j+dj[l]][k+dk[l]]);
                if(o[i] == u[j] && u[j] == c[k]) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1] + 1);
            }
        }
    }
    printf("%d\n",dp[n][m][p]);
    return 0;
}