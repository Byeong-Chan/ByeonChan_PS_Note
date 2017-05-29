#include <cstdio>
#include <algorithm>

using namespace std;

const int INT_MAX = 0x7fffffff;

int dist[23][23];
bool chk[23][23];
int main() {
    int k, i, j, n;
    int m = 0;
    int ans = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&dist[i][j]);
        }
    }
    for(k=0;k<n;k++) {
        for(i=0;i<n;i++) {
            if(i == k) continue;
            for(j=0;j<n;j++) {
                if(i == k || j == k) continue;
                if(dist[i][k] + dist[k][j] == dist[i][j]) chk[i][j] = true;
                else if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    for(i=0;i<n;i++) for(j=0;j<n;j++) {
        if(chk[i][j]) continue;
        ans += dist[i][j];
    }
    ans >>= 1;
    printf("%d\n",ans);
    return 0;
}