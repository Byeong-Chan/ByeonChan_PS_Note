#include <cstdio>
char o[110][110];
bool chkx[110];
bool chky[110];
int main() {
    int n;
    int i, j;
    int x = 0, y = 0;
    int cnt;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%s",o[i]);
    for(i=0;i<n;i++) {
        cnt = 0;
        for(j=0;j<n;j++) {
            if(o[i][j] != '.') {
                if(cnt >= 2) x++;
                cnt = 0;
                continue;
            }
            cnt++;
        }
        if(cnt >= 2) x++;
        
        cnt = 0;
        for(j=0;j<n;j++) {
            if(o[j][i] != '.') {
                if(cnt >= 2) y++;
                cnt = 0;
                continue;
            }
            cnt++;
        }
        if(cnt >= 2) y++;
    }
    printf("%d %d\n",x,y);
    return 0;
}