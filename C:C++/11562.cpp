#include <cstdio>
#include <algorithm>

using namespace std;

const int INT_MAX = 0x7fffffff;

int dist[251][251];
int main() {
    int k, i, j;
    int x, y, z;
    int n, m;
    int Q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            dist[i][j] = INT_MAX;
        }
        dist[i][i] = 0;
    }
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&x,&y,&z);
        if(z == 0) dist[x][y] = 0, dist[y][x] = 1;
        else dist[x][y] = 0, dist[y][x] = 0;
    }
    for(k=1;k<=n;k++) {
        for(i=1;i<=n;i++) {
            if (dist[i][k] == INT_MAX) continue;
            for(j=1;j<=n;j++) {
                if(dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    scanf("%d",&Q);
    for(i=0;i<Q;i++) {
        scanf("%d %d",&x,&y);
        printf("%d\n",dist[x][y]);
    }
    return 0;
}