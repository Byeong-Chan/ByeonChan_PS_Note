#include <cstdio>
#include <algorithm>
using namespace std;
int ans[10010];
int o[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int flood(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return 0;
    if(o[x][y] != 0) return 0;
    o[x][y] = 1;
    int tmp = 0;
    for(int i = 0; i < 4; i++) tmp += flood(x+dx[i], y+dy[i]);
    return tmp + 1;
}
int main() {
    int i, j;
    int x1, y1, x2, y2;
    int cnt = 0;
    int k;
    scanf("%d %d %d", &m, &n, &k);
    for(i=0;i<k;i++) {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        o[x1][y1]++;
        o[x1][y2]--;
        o[x2][y1]--;
        o[x2][y2]++;
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            o[i][j] += (i-1 >= 0 ? o[i-1][j] : 0) + (j-1 >= 0 ? o[i][j-1] : 0);
            o[i][j] -= i-1 >= 0 && j-1 >= 0 ? o[i-1][j-1] : 0;
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(o[i][j]) continue;
            ans[cnt++] = flood(i, j);
        }
    }
    sort(ans, ans+cnt);
    printf("%d\n",cnt);
    for(i=0;i<cnt;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}