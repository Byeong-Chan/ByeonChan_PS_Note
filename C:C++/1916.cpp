#include <cstdio>
#include <cstring>
unsigned int o[1010][1010];
bool visit[1010];
const unsigned int MAX = ((((unsigned int)1 << 31) - 1) << 1) + 1;
int main() {
    int i, j, n, m;
    int via;
    int x, y, z;
    unsigned int min1;
    
    memset(o, -1, sizeof(o));
    scanf("%d%d",&n,&m);
    for(i=m;i>0;i--) {
        scanf("%d %d %d",&x,&y,&z);
        if(o[x][y] > z) o[x][y] = z;
    }
    scanf("%d %d",&x,&y);
    o[x][x] = 0;
    visit[x] = true;
    for(i=n-1;i>0;i--) {
        min1 = MAX;
        via = 0;
        for(j=n;j>0;j--) {
            if(visit[j]) continue;
            if(o[x][j] == MAX) continue;
            if(min1 > o[x][j]) {
                min1 = o[x][j];
                via = j;
            }
        }
        if(min1 == MAX) break;
        visit[via] = true;
        for(j=n;j>0;j--) {
            if(o[via][j] == MAX) continue;
            if(min1 + o[via][j] < o[x][j]) o[x][j] = min1 + o[via][j];
        }
    }
    if(o[x][y] == MAX) printf("-1\n");
    else printf("%d\n",o[x][y]);
    return 0;
}