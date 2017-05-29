#include <cstdio>
#include <algorithm>
using namespace std;
int ans[1010];
int o[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
int flood(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= n) return 0;
    if(o[x][y] == 0) return 0;
    o[x][y] = 0;
    int tmp = 0;
    for(int i = 0; i < 4; i++) tmp += flood(x+dx[i], y+dy[i]);
    return tmp + 1;
}
int main() {
    int i, j;
    int cnt = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%1d",&o[i][j]);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(!o[i][j]) continue;
            ans[cnt++] = flood(i, j);
        }
    }
    sort(ans, ans+cnt);
    printf("%d\n",cnt);
    for(i=0;i<cnt;i++) printf("%d\n",ans[i]);
    return 0;
}