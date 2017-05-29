#include <cstdio>
int dp[21][21][21][21][21];
int o[21][21];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int main() {
    int n, L;
    int t;
    int c, i, j, k, l;
    int tx, ty, ex, ey, p, q;
    int ans = 0;
    bool sw;
    scanf("%d %d",&n,&L);
    sw = L & 1;
    t = L / 2 - !sw;
    for (i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&o[i][j]);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            for(k=0;k<n;k++) {
                for(l=0;l<n;l++) {
                    if (o[i][j] == o[k][l]) dp[0][i][j][k][l] = 1;
                }
            }
        }
    }
    for (c = 0; c < t; c++) {
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                for(k=0;k<n;k++) {
                    for(l=0;l<n;l++) {
                        for (p=0;p<8;p++) {
                            tx = i + dx[p];
                            ty = j + dy[p];
                            if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                            for(q=0;q<8;q++) {
                                ex = k + dx[q];
                                ey = l + dy[q];
                                if (ex < 0 || ex >= n || ey < 0 || ey >= n) continue;
                                if (o[ex][ey] == o[tx][ty]) dp[c+1][tx][ty][ex][ey] += dp[c][i][j][k][l];
                                 
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if (sw) {
                ans += dp[t][i][j][i][j];
                continue;
            }
            for(p=0;p<8;p++) {
                tx = i + dx[p];
                ty = j + dy[p];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                ans += dp[t][i][j][tx][ty];
            }
        }
    }
    printf("%d\n",ans);
     
    return 0;
}