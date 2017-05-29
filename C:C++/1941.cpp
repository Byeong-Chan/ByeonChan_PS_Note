#include <cstdio>
char o[6][6];
bool u[6][6];
int ct[6][6];
int cnt = 0, ans = 0;
void flood(int x, int y) {
    if(x < 0 || y < 0 || x >= 5 || y >= 5) return;
    if(u[x][y] == false) return;
    if(ct[x][y] == cnt) return;
    ct[x][y] = cnt;
    flood(x-1, y);
    flood(x+1, y);
    flood(x, y-1);
    flood(x, y+1);
}
void dfs(int n, int m) {
    if(m == 7) {
        int i, j;
        int p = 0;
        int s = 0;
        cnt++;
        for(i=0;i<5;i++) {
            for(j=0;j<5;j++) {
                if(!u[i][j]) continue;
                if(ct[i][j] != cnt) {
                    p++;
                    flood(i, j);
                }
                if(o[i][j] == 'S') s++;
            }
        }
        if(p == 1 && s >= 4) ans++;
        return;
    }
    if(n == 25) return;
    u[n/5][n%5] = false;
    dfs(n+1, m);
    u[n/5][n%5] = false;
    
    
    u[n/5][n%5] = true;
    dfs(n+1, m+1);
    u[n/5][n%5] = false;
}
int main() {
    int i;
    for(i=0;i<5;i++) scanf("%s",o[i]);
    dfs(0, 0);
    printf("%d\n",ans);
    return 0;
}