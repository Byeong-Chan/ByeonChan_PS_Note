#include <cstdio>
#include <algorithm>
using namespace std;
bool chk[110];
int dt[110][110];
int main() {
    int i, j, n, m;
    int x;
    int tmp;
    int ans;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++) {
        scanf("%d",&x);
        chk[x-1] = true;
    }
    dt[0][0] = 1;
    for(i=0;i<n;i++) {
        for(j=0;j<=n;j++) {
            if (dt[i][j] == 0) continue;
            if (j >= 3) {
                if (dt[i+1][j-3] == 0) dt[i+1][j-3] = dt[i][j];
                else dt[i+1][j-3] = min(dt[i+1][j-3], dt[i][j]);
            }
            if (chk[i]) {
                if (dt[i+1][j] == 0) dt[i+1][j] = dt[i][j];
                else dt[i+1][j] = min(dt[i+1][j], dt[i][j]);
            }
            
            if (dt[i+1][j] == 0) dt[i+1][j] = dt[i][j] + 10000;
            else dt[i+1][j] = min(dt[i+1][j], dt[i][j] + 10000);
            
            tmp = i+3;
            if (tmp > n) tmp = n;
            if (dt[tmp][j+1] == 0) dt[tmp][j+1] = dt[i][j] + 25000;
            else dt[tmp][j+1] = min(dt[tmp][j+1], dt[i][j] + 25000);
            
            tmp = i+5;
            if (tmp > n) tmp = n;
            if (dt[tmp][j+2] == 0) dt[tmp][j+2] = dt[i][j] + 37000;
            else dt[tmp][j+2] = min(dt[tmp][j+2], dt[i][j] + 37000);
        }
    }
    ans = 0x7fffffff;
    for(i=0;i<=n;i++) if (dt[n][i]) ans = min(ans, dt[n][i]);
    printf("%d\n",ans - 1);
    return 0;
}