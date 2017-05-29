#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1010][1010];
int trace[1010][1010];
int x[1010], y[1010];
int abs(int x) {
    if(x < 0) return -x;
    return x;
}
void backt(int x, int y) {
    if(x == 0 && y == 1) return;
    if(trace[x][y] < 0) {
        backt(x, -trace[x][y]);
        printf("2\n");
    }
    else {
        backt(trace[x][y], y);
        printf("1\n");
    }
}
int main() {
    int i, j;
    int n, m;
    int min1 = 0x7fffffff, posx, posy;
    int tmp;
    scanf("%d%d",&n,&m);
    for(i=0;i<=m+1;i++) for(j=0;j<=m+1;j++) dp[i][j] = 0x7fffffff;
    x[0] = y[0] = 1;
    x[1] = y[1] = n;
    dp[0][1] = 0;
    for(i=2;i<=m+1;i++) {
        scanf("%d %d",&x[i],&y[i]);
        for(j=0;j<i-1;j++) {
            if(dp[i-1][j] != 0x7fffffff) {
                tmp = dp[i-1][j] + abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
                if(dp[i][j] > tmp) {
                    dp[i][j] = tmp;
                    trace[i][j] = i - 1;
                }
                tmp = dp[i-1][j] + abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if(dp[i-1][i] > tmp) {
                    dp[i-1][i] = tmp;
                    trace[i-1][i] = -j;
                }
            }
            if(dp[j][i-1] != 0x7fffffff) {
                tmp = dp[j][i-1] + abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
                if(dp[j][i] > tmp) {
                    dp[j][i] = tmp;
                    trace[j][i] = -(i-1);
                }
                tmp = dp[j][i-1] + abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if(dp[i][i-1] > tmp) {
                    dp[i][i-1] = tmp;
                    trace[i][i-1] = j;
                }
            }
            if(i == m+1) {
                if(min1 > dp[i][j]) {
                    min1 = dp[i][j];
                    posx = i;
                    posy = j;
                }
                if(min1 > dp[j][i]) {
                    min1 = dp[j][i];
                    posx = j;
                    posy = i;
                }
                if(min1 > dp[i][i-1]) {
                    min1 = dp[i][i-1];
                    posx = i;
                    posy = i-1;
                }
                if(min1 > dp[i-1][i]) {
                    min1 = dp[i-1][i];
                    posx = i-1;
                    posy = i;
                }
            }
        }
    }
    printf("%d\n",min1);
    backt(posx, posy);
    
    return 0;
}