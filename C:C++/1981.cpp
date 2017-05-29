#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
    int x;
    int y;
    int cst;
    bool operator< (const node &a) const {
        return this->cst < a.cst;
    }
};
priority_queue<node> q;
int p[110][110];
int o[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    int k, i, j, l, n;
    int max1 = 0;
    int tx, ty;
    int ans = 0x7fffffff;
    node here, tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&o[i][j]);
            if (max1 < o[i][j]) max1 = o[i][j];
        }
    }
    for (k=max1;k>=0;k--) {
        if (k < o[0][0]) break;
        for(i=0;i<n;i++) for(j=0;j<n;j++) p[i][j] = -1;
        tmp.x = 0;
        tmp.y = 0;
        tmp.cst = o[0][0];
        q.push(tmp);
        while (q.size()) {
            here = q.top();
            q.pop();
            if (p[here.x][here.y] == -1) p[here.x][here.y] = here.cst;
            else continue;
            
            for (l=0;l<4;l++) {
                tx = here.x + dx[l];
                ty = here.y + dy[l];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                if (o[tx][ty] > k) continue;
                
                tmp.x = tx;
                tmp.y = ty;
                tmp.cst = here.cst;
                if (tmp.cst > o[tx][ty]) tmp.cst = o[tx][ty];
                q.push(tmp);
            }
        }
        if (p[n-1][n-1] == -1) continue;
        if (k - p[n-1][n-1] < ans) ans = k - p[n-1][n-1];
    }
    printf("%d\n",ans);
    return 0;
}